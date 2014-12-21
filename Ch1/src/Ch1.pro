#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T20:35:52
#
#-------------------------------------------------

macx {
   QMAKE_MAC_SDK=macosx10.9
}

mac {
   CONFIG -= app_bundle
}

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ch1
TEMPLATE = app


SOURCES += main.cpp\
    openglwindow.cpp \
    firstprogram.cpp \
    loadshaders.cpp

HEADERS  += \
    openglwindow.h \
    firstprogram.h \
    loadshaders.h

OTHER_FILES += \
    triangles.vert \
    triangles.frag

other.path = $${OUT_PWD}
other.files = $${PWD}/$${OTHER_FILES}

INSTALLS += other
