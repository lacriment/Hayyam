#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T13:26:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app


SOURCES += main.cpp\
        app.cpp \
    statusupdateform.cpp

HEADERS  += app.hpp \
    statusupdateform.hpp

FORMS    += app.ui \
    statusupdateform.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release/ -llib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug/ -llib
else:unix: LIBS += -L$$OUT_PWD/../lib/ -llib

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib
