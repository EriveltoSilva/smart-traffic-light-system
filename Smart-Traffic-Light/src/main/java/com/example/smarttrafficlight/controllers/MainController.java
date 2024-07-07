package com.example.smarttrafficlight.controllers;

import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortDataListener;
import com.fazecast.jSerialComm.SerialPortEvent;
import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.stage.Stage;
import serialcommunication.PacketListener;

import java.io.PrintWriter;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.ResourceBundle;

public class MainController implements Initializable {
    private SerialPort serialPort;
    private Integer statusLed =0;
    private final StringBuilder dataBuffer = new StringBuilder();

    @FXML
    private Button btnConnect;

    @FXML
    private Button btnToggleLed;

    @FXML
    private ComboBox<String> comboSerialPort;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        System.out.println("# STARTTING SERIAL PORT");
        loadSerialPorts();
        System.out.println("# STOPPING SERIAL PORT");

        // Chamar a função disconnectSerial ao clicar no botão de fechar a aplicação
        Platform.runLater(() -> {
            Stage primaryStage = (Stage) comboSerialPort.getScene().getWindow();
            primaryStage.setOnCloseRequest(event -> {
                disconnectSerial();
            });
        });
    }

    @FXML
    public void handleConnectButton(){
        if(this.serialPort==null || !this.serialPort.isOpen())
            this.connectSerial();
        else if(this.serialPort!=null && this.serialPort.isOpen())
            this.disconnectSerial();
    }

    @FXML
    public void handleToggleLedButton() {
        if(this.serialPort==null || !this.serialPort.isOpen()) {
            showAlert(Alert.AlertType.ERROR, "Envio de Comando", "Erro enviando comando.\nPrimeiro se conecte ao arduino!");
            return ;
        }
        PrintWriter arduino = new PrintWriter(this.serialPort.getOutputStream());
        if(statusLed==0){
            arduino.print("1");
            statusLed=1;
        }
        else {
            arduino.print("0");
            statusLed=0;
        }
        arduino.flush();
        arduino.close();
    }

    private void loadSerialPorts(){
        SerialPort[] serialPorts = SerialPort.getCommPorts();

        for (SerialPort serialPort : serialPorts) {
            /*System.out.println(serialPort.getSystemPortName());
            System.out.println(serialPort.getDescriptivePortName());*/
            comboSerialPort.getItems().add(serialPort.getSystemPortName());
            //comboSerialPort.getItems().add(serialPort.getDescriptivePortName());
        }
    }

    private void showAlert(Alert.AlertType type, String title, String message) {
        Alert alert = new Alert(type);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    private boolean isCommPortValid(String commName) {
        return (commName!=null && !commName.isBlank() && !commName.isEmpty());
    }

    private void processReceivedData(String data) {
        dataBuffer.append(data);
        int index;
        while ((index = dataBuffer.indexOf("\n")) != -1) {
            String completeData = dataBuffer.substring(0, index).replaceAll("\\s+", "");
            dataBuffer.delete(0, index + 1);
            System.out.println("Complete data received: " + completeData);
        }
    }

    private void connectSerial(){
        String commPortSelected = comboSerialPort.getSelectionModel().getSelectedItem();

        if(!isCommPortValid(commPortSelected)) {
            showAlert(Alert.AlertType.ERROR,"Erro de comunição","Selecione a porta COM por favor!");
            return;
        }

        this.serialPort = SerialPort.getCommPort(commPortSelected);
        this.serialPort.setComPortParameters(9600, Byte.SIZE, SerialPort.ONE_STOP_BIT, SerialPort.NO_PARITY);
        this.serialPort.setComPortTimeouts(SerialPort.TIMEOUT_READ_BLOCKING, 0, 0);

        if(!this.serialPort.openPort()){
            showAlert(Alert.AlertType.ERROR, "Erro!", "ERROR: A PORTA COM NÃO ESTA DISPONIVEL");
            return;
        }

        this.serialPort.addDataListener(new SerialPortDataListener() {
            @Override
            public int getListeningEvents() { return SerialPort.LISTENING_EVENT_DATA_RECEIVED; }
            @Override
            public void serialEvent(SerialPortEvent event)
            {
                byte[] newData = event.getReceivedData();
                String str = new String(newData);
                processReceivedData(str);
            }
        });

        btnConnect.setText("Desconectar");
        comboSerialPort.setDisable(true);
        showAlert(Alert.AlertType.CONFIRMATION, "Sucesso!", "Comunição estabelecida com sucesso!");
    }

    private void disconnectSerial(){
        if (this.serialPort != null && this.serialPort.isOpen()) {
            if(this.serialPort.closePort())
            {
                btnConnect.setText("Conectar");
                comboSerialPort.setDisable(false);
                showAlert(Alert.AlertType.CONFIRMATION, "Sucesso!", "Comunição desconectada com sucesso!");
            }
            else
                showAlert(Alert.AlertType.ERROR, "Erro!", "# ERROR: ERRO FECHANDO A PORTA SERIAL");
        }
    }


}
