QT += core gui opengl
LIBS += -lopengl32 -lglu32
TARGET = OpenGL_CG_BigDipper

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    cgwidget.h \
    common_point.h

SOURCES += \
    cgwidget.cpp \
    common_point.cpp \
    main.cpp
