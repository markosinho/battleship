TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    polje.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    polje.h

