# Created by and for Qt Creator. This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = Course_Project_Qt

QT = core gui widgets

HEADERS = \
   $$PWD/controller/controller.hpp \
   $$PWD/controller/database.hpp \
   $$PWD/controller/eventHandler.hpp \
   $$PWD/controller/menu.hpp \
   $$PWD/controller/timer.hpp \
   $$PWD/controller/user.hpp \
   $$PWD/model/logic.hpp \
   $$PWD/view/GridFactory.hpp \
   $$PWD/view/Grids.hpp \
   $$PWD/view/GridsFactories.hpp \
   $$PWD/view/IGrid.hpp \
   $$PWD/view/selector.hpp

SOURCES = \
   $$PWD/controller/controller.cpp \
   $$PWD/controller/database.cpp \
   $$PWD/controller/eventHandler.cpp \
   $$PWD/controller/menu.cpp \
   $$PWD/controller/timer.cpp \
   $$PWD/controller/user.cpp \
   $$PWD/model/logic.cpp \
   $$PWD/view/Grids.cpp \
   $$PWD/view/GridsFactories.cpp \
   $$PWD/view/selector.cpp \
   $$PWD/main.cpp \

# Include path for SQLite headers
INCLUDEPATH += $$PWD/include

# Link the SQLite library
LIBS += -L$$PWD/lib -lsqlite3

#DEFINES =
