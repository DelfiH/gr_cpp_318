QT += core
QT += core gui widgets
QT += script

CONFIG += c++11

TARGET = lab_3_1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    probabilities.cpp \
    printchar.cpp \
    initialization.cpp \
    animals.cpp \
    min_max.cpp \
    type_cast.cpp \
    elevator.cpp \
    calculator.cpp \
    animal_menu.cpp \
    tasks.cpp

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    probabilities.h \
    printchar.h \
    initialization.h \
    animals.h \
    min_max.h \
    type_cast.h \
    elevator.h \
    calculator.h \
    animal_menu.h \
    tasks.h

FORMS += \
    calculator.ui
