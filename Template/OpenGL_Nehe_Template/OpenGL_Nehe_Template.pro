QT += core gui opengl
LIBS += -lopengl32 -lglu32
TARGET = OpenGL_CG

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    nehewidget.h

SOURCES += \
    main.cpp \
    nehewidget.cpp
