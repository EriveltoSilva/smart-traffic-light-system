package com.example.smarttrafficlight.controllers;

import com.fazecast.jSerialComm.SerialPort;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;

import java.io.PrintWriter;
import java.net.URL;
import java.util.ResourceBundle;

public class MainController implements Initializable {
    private SerialPort serialPort;
    private Integer statusLed =0;

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
    }

    @FXML
    public void handleConnectButton(){
        if(this.serialPort==null || !this.serialPort.isOpen())
            this.connectSerial();
        else if(this.serialPort!=null && this.serialPort.isOpen())
            this.disconnectSerial();
    }


    @FXML
    public void handleToggleLedButton(){
        if(this.serialPort==null || !this.serialPort.isOpen()) {
            showAlert(Alert.AlertType.ERROR, "Envio de Comando", "Erro enviando comando.\nPrimeiro se conecte ao arduino!");
            return ;
        }
        PrintWriter arduino = new PrintWriter(this.serialPort.getOutputStream());
        arduino.println(statusLed.toString());
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

    private void showAlert(Alert.AlertType type, String title, String message)
    {
        Alert alert = new Alert(type);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    private boolean isCommPortValid(String commName)
    {
        return (commName!=null && !commName.isBlank() && !commName.isEmpty());
    }

    private void connectSerial(){
        String commPortSelected = comboSerialPort.getSelectionModel().getSelectedItem();

        if(!isCommPortValid(commPortSelected)) {
            showAlert(Alert.AlertType.ERROR,"Erro de comunição","Selecione a porta COM por favor!");
            return;
        }

        this.serialPort = SerialPort.getCommPort(commPortSelected);
        this.serialPort.setComPortParameters(9600, 8, 1, 0);
        this.serialPort.setComPortTimeouts(SerialPort.TIMEOUT_READ_BLOCKING, 0, 0);

        if(!this.serialPort.openPort()){
            showAlert(Alert.AlertType.ERROR, "Erro!", "ERROR: A PORTA COM NÃO ESTA DISPONIVEL");
            return;
        }
        btnConnect.setText("Desconectar");
        comboSerialPort.setDisable(true);
        showAlert(Alert.AlertType.CONFIRMATION, "Sucesso!", "Comunição estabelecida com sucesso!");
    }
    private void disconnectSerial(){
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
