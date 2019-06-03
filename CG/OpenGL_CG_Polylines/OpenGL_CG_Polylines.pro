QT += core gui opengl
LIBS += -lopengl32 -lglu32
TARGET = OpenGL_CG_Polylines

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    cgwidget.h \
    common_line.h \
    common_point.h \
    common_type.h

SOURCES += \
    cgwidget.cpp \
    main.cpp
