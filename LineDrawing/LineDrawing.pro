TARGET=LineDrawing
CONFIG+=c++14
SOURCES+=src/main.cpp
OBJECTS_DIR=obj
INCLUDEPATH+= ../ImageTests/include
LIBS+= -L ../ImageTests -lImage -lOpenImageIO
