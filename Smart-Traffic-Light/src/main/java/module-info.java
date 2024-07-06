module com.example.smarttrafficlight {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;
    requires com.fazecast.jSerialComm;

    opens com.example.smarttrafficlight to javafx.fxml;
    exports com.example.smarttrafficlight;
    exports com.example.smarttrafficlight.controllers;
    opens com.example.smarttrafficlight.controllers to javafx.fxml;
}