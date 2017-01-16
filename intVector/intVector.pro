QT += core
QT -= gui

CONFIG += c++11

TARGET = intVector
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    intvector.cpp

HEADERS += \
    intvector.h
