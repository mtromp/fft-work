QT += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += core gui

TARGET = fftLibrary
TEMPLATE = lib

DEFINES += FFTLIBRARY_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
  fftpoint.cpp \
  inplacefft.cpp \
  mainwindow.cpp

HEADERS += \
  fftpoint.h \
  inplacefft.h \
  mainwindow.h

unix {
  target.path = /usr/lib
  INSTALLS += target
}
