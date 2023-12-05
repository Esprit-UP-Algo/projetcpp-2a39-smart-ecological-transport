QT       += core gui
QT       += core gui sql
QT += widgets printsupport
QT += core gui charts
QT += serialport
QT +=  core sql printsupport multimedia multimediawidgets svg network axcontainer widgets network charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduinoc.cpp \
    client.cpp \
    clients.cpp \
    conge.cpp \
    connection.cpp \
    employe.cpp \
    employes.cpp \
    espacepro.cpp \
    exportexcel.cpp \
    login.cpp \
    main.cpp \
    gogreen.cpp \
    pdf.cpp \
    popup.cpp \
    qrcode.cpp \
    reservations.cpp \
    reserve.cpp \
    retours.cpp \
    sms.cpp \
    smtp.cpp \
    station.cpp \
    vehicule.cpp \
    vhicule.cpp

HEADERS += \
    arduino.h \
    arduinoc.h \
    client.h \
    clients.h \
    conge.h \
    connection.h \
    employe.h \
    employes.h \
    espacepro.h \
    exportexcel.h \
    gogreen.h \
    login.h \
    pdf.h \
    popup.h \
    qrcode.h \
    reservations.h \
    reserve.h \
    retours.h \
    sms.h \
    smtp.h \
    station.h \
    vehicule.h \
    vhicule.h

FORMS += \
    Vehicule.ui \
    clients.ui \
    employes.ui \
    espacepro.ui \
    gogreen.ui \
    retours.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
