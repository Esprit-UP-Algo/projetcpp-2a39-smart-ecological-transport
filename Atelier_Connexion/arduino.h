#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class Arduino : public QObject {
    Q_OBJECT

public:
    Arduino(QObject *parent = nullptr);
    ~Arduino();

    bool connectToArduino();
    bool enrollFingerprint();
    bool verifyFingerprint();

signals:
    void fingerprintEnrolled(bool success);
    void fingerprintVerified(bool success);

private slots:
    void readFromSerial();

private:
    QSerialPort arduino;
    QByteArray serialData;
    // Other necessary private members
};

#endif // ARDUINO_H
