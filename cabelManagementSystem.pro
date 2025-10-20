QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addnewback.cpp \
    addnewcabel.cpp \
    addnewhave.cpp \
    backlist.cpp \
    cabel.cpp \
    cabelback.cpp \
    cabelhave.cpp \
    cabellist.cpp \
    globals.cpp \
    havelist.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomlabel.cpp

HEADERS += \
    addnewback.h \
    addnewcabel.h \
    addnewhave.h \
    backlist.h \
    cabel.h \
    cabelback.h \
    cabelhave.h \
    cabellist.h \
    globals.h \
    havelist.h \
    mainwindow.h \
    qcustomlabel.h

FORMS += \
    addnewback.ui \
    addnewcabel.ui \
    addnewhave.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
