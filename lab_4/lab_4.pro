QT += core
QT -= gui

CONFIG += c++11

TARGET = lab_4
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    task1.cpp \
    task2.cpp \
    task3.cpp \
    task4.cpp \
    task5.cpp \
    task6.cpp \
    task7.cpp \
    task8.cpp \
    task9.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    tasks.h \
    task1.h \
    task2.h \
    task3.h \
    task4.h \
    task5.h \
    task6.h \
    task7.h \
    task8.h \
    task9.h
