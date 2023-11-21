#include "arduino.h"

Arduino::Arduino(QObject *parent) : QObject(parent) {
    connect(&arduino, &QSerialPort::readyRead, this, &Arduino::readFromSerial);
}

Arduino::~Arduino() {
    if (arduino.isOpen()) {
        arduino.close();
    }
}

bool Arduino::connectToArduino() {
    bool connected = false;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.description().contains("Arduino")) { // Adjust the description as per your Arduino's identifier
            arduino.setPort(info);
            arduino.setBaudRate(QSerialPort::Baud9600); // Set your desired baud rate
            arduino.setDataBits(QSerialPort::Data8);
            arduino.setParity(QSerialPort::NoParity);
            arduino.setStopBits(QSerialPort::OneStop);
            arduino.setFlowControl(QSerialPort::NoFlowControl);

            if (arduino.open(QIODevice::ReadWrite)) {
                connected = true;
                break;
            }
        }
    }
    return connected;
}

bool Arduino::enrollFingerprint() {
    if (!arduino.isOpen()) {
        return false;
    }

    // Send enrollment command to Arduino
    arduino.write("ENROLL\n"); // Adjust the command according to your fingerprint module's protocol

    return true; // Placeholder for success or failure
}

bool Arduino::verifyFingerprint() {
    if (!arduino.isOpen()) {
        return false;
    }

    // Send verification command to Arduino
    arduino.write("VERIFY\n"); // Adjust the command according to your fingerprint module's protocol

    return true; // Placeholder for success or failure
}

void Arduino::readFromSerial() {
    serialData.append(arduino.readAll());
    // Implement logic to parse received data and handle fingerprint module responses
    // For example, detect when enrollment or verification is successful and emit corresponding signals
}
