QMAKE_MAC_SDK = macosx10.14
TEMPLATE = subdirs

SUBDIRS += \
    fftLibrary \
    fftApplication \
    fftTests

fftApplication.depends = fftLibrary
fftTests.depends = fftLibrary
