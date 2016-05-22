#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T13:26:34
#
#-------------------------------------------------

QT       += sql

TARGET = lib
TEMPLATE = lib

DEFINES += LIB_LIBRARY

SOURCES += \
    models/customer.cpp \
    models/shipment.cpp \
    models/city.cpp \
    models/office.cpp \
    models/distance.cpp \
    db/connection.cpp \
    helpers/filehelper.cpp \
    helpers/stringhelper.cpp \
    algorithm/pricing.cpp

HEADERS += library.hpp\
        lib_global.hpp \
    models/customer.hpp \
    models/shipment.hpp \
    models/city.hpp \
    models/office.hpp \
    models/distance.hpp \
    db/connection.hpp \
    helpers/filehelper.hpp \
    helpers/stringhelper.hpp \
    algorithm/graph.hpp \
    algorithm/pricing.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
