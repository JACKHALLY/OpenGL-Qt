QT += core gui opengl
LIBS += -lopengl32 -lglu32
TARGET = OpenGL_CG

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    cgwidget.h \
    common_point.h \
    common_polyline.h \
    common_point.h \
    common_type.h

SOURCES += \
    main.cpp \
    cgwidget.cpp

DISTFILES +=
