TARGET=ImageTests
SOURCES+=ImageTests.cpp ../src/Image.cpp
HEADERS+= ../include/Image.h
CONFIG-=app_bundle
CONFIG+=c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CXXFLAGS += -g
INCLUDEPATH+=/usr/local/include
INCLUDEPATH+=../include
LIBS+= -L/usr/local/lib -lgtest -lgtest_main -pthread
LIBS+= -L/public/devel/2018/lib64 -lOpenImageIO
