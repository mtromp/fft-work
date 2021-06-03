QT += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core gui

TARGET = fftLibrary
TEMPLATE = lib

DEFINES += FFTLIBRARY_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
  inplacefft.cpp \
  mainwindow.cpp

HEADERS += \
  inplacefft.h \
  mainwindow.h

unix {
  target.path = /usr/lib
  INSTALLS += target
}
