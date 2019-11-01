# this is the name of the lib
TARGET=Image
TEMPLATE=lib
CONFIG+=staticlib
CONFIG+=c++14
OBJECTS_DIR=obj
SOURCES += src/Image.cpp
HEADERS += include/Image.h
INCLUDEPATH += include
LIBS += -lOpenImageIO
