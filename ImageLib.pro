TARGET=Image
TEMPLATE=lib
CONFIG += staticlib
SOURCES+=Image.cpp
HEADERS+=Image.h
CONFIG-=app_bundle
CONFIG+=c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CXXFLAGS += -g
INCLUDEPATH+=/usr/local/include
LIBS+= -L/public/devel/2018/lib64 -lOpenImageIO
