QT       += core gui charts

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
    aboutwidget/aboutdialog.cpp \
    buttons/cbutton.cpp \
    buttons/clabels.cpp \
    buttons/trendwidgetbuttons.cpp \
    datamanager.cpp \
    main.cpp \
    monitorwidget/curvegraph.cpp \
    monitorwidget/curvegraph2.cpp \
    monitorwidget/mainchannelwidget.cpp \
    monitorwidget/monitorwidget.cpp \
    monitorwidget/spectrumgraph.cpp \
    monitorwidget/subchannelwidget.cpp \
    multipwidgets/ecg.cpp \
    multipwidgets/heartrate.cpp \
    multipwidgets/mchart.cpp \
    multipwidgets/multipwidget.cpp \
    multipwidgets/respgraph.cpp \
    multipwidgets/spo2widget.cpp \
    multipwidgets/temperature.cpp \
    qcustomplot.cpp \
    setupwidget/setupwidget.cpp \
    signalqualitydialog/signalqualitydialog.cpp \
    statusbar/statsbar.cpp \
    trendwidget/showvaluewideget.cpp \
    trendwidget/trendwidget.cpp \
    widget.cpp

HEADERS += \
    aboutwidget/aboutdialog.h \
    buttons/cbutton.h \
    buttons/clabels.h \
    buttons/trendwidgetbuttons.h \
    datamanager.h \
    monitorwidget/curvegraph.h \
    monitorwidget/curvegraph2.h \
    monitorwidget/mainchannelwidget.h \
    monitorwidget/monitorwidget.h \
    monitorwidget/spectrumgraph.h \
    monitorwidget/subchannelwidget.h \
    multipwidgets/ecg.h \
    multipwidgets/heartrate.h \
    multipwidgets/mchart.h \
    multipwidgets/multipwidget.h \
    multipwidgets/respgraph.h \
    multipwidgets/spo2widget.h \
    multipwidgets/temperature.h \
    qcustomplot.h \
    setupwidget/setupwidget.h \
    signalqualitydialog/signalqualitydialog.h \
    statusbar/statsbar.h \
    trendwidget/showvaluewideget.h \
    trendwidget/trendwidget.h \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

FORMS += \
    form.ui
