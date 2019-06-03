QT += core gui opengl
LIBS += -lopengl32 -lglu32
TARGET = OpenGL_CG_DotPlots

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    cgwidget.h \
    common_point.h

SOURCES += \
    cgwidget.cpp \
    main.cpp
