macx: GOOGLETEST_DIR = /Users/Shared/gitrepositories/googletest/
unix:!macx: GOOGLETEST_DIR = /usr/src/googletest/

include(gtest_dependency.pri)

QT += testlib
QT += core

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += testcase

SOURCES +=  main.cpp 

INCLUDEPATH += $$PWD/../fftLibrary
LIBS += -L$$OUT_PWD/../fftLibrary -lfftLibrary
