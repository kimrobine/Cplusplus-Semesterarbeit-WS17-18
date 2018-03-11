TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    passagier.cpp

HEADERS += \
    passagier.h

data.path = $$OUT_PWD/

data.files += $$PWD/*.dat

data.files += $$PWD/*.xml

data.files += $$PWD/*.txt

data.files += $$PWD/*.dtd

INSTALLS += data
