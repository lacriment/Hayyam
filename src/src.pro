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
    statusupdateform.cpp \
    aboutform.cpp \
    helpform.cpp \
    customermanagementform.cpp \
    customereditform.cpp \
    shipmentmanagementform.cpp \
    shipmenteditform.cpp \
    customerselectionform.cpp \
    officeselectionform.cpp

HEADERS  += app.hpp \
    statusupdateform.hpp \
    aboutform.hpp \
    helpform.hpp \
    customermanagementform.hpp \
    customereditform.hpp \
    shipmentmanagementform.hpp \
    shipmenteditform.hpp \
    customerselectionform.hpp \
    officeselectionform.hpp

FORMS    += app.ui \
    statusupdateform.ui \
    aboutform.ui \
    helpform.ui \
    customermanagementform.ui \
    customereditform.ui \
    shipmentmanagementform.ui \
    shipmenteditform.ui \
    customerselectionform.ui \
    officeselectionform.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release/ -llib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug/ -llib
else:unix: LIBS += -L$$OUT_PWD/../lib/ -llib

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib
