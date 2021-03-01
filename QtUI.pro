QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport serialport
#printsupport

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
    Com/cbutton.cpp \
    Com/clabels.cpp \
    Com/cswitch.cpp \
    Com/menu.cpp \
    Com/trendwidgetbuttons.cpp \
    aboutwidget/aboutdialog.cpp \
    main.cpp \
    mainwindow/widget.cpp \
    monitorwidget/curvegraph.cpp \
    monitorwidget/curvegraph2.cpp \
    monitorwidget/mainchannelwidget.cpp \
    monitorwidget/monitorwidget.cpp \
    monitorwidget/spectrumgraph.cpp \
    monitorwidget/subchannelwidget.cpp \
    qcustomplot/qcustomplot.cpp \
    setupwidget/setupwidget.cpp \
    signalqualitydialog/signalqualitydialog.cpp \
    statusbar/statsbar.cpp \
    trendwidget/trendwidget.cpp \
    trendwidget/valuewidget.cpp \

HEADERS += \
    Com/cbutton.h \
    Com/clabels.h \
    Com/cswitch.h \
    Com/menu.h \
    Com/trendwidgetbuttons.h \
    aboutwidget/aboutdialog.h \
    mainwindow/widget.h \
    monitorwidget/curvegraph.h \
    monitorwidget/curvegraph2.h \
    monitorwidget/mainchannelwidget.h \
    monitorwidget/monitorwidget.h \
    monitorwidget/spectrumgraph.h \
    monitorwidget/subchannelwidget.h \
    qcustomplot/qcustomplot.h \
    setupwidget/setupwidget.h \
    signalqualitydialog/signalqualitydialog.h \
    statusbar/statsbar.h \
    trendwidget/trendwidget.h \
    trendwidget/valuewidget.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

FORMS += \
    form.ui
