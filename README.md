# OpenGL-Qt
OpenGL exercises with Qt

# Template
Template/OpenGL_CG_Template

Template/OpenGL_Nehe_Template

- Template configure(for .pro file)
1. QT += opengl
2. LIBS += -lopengl32 -lglu32
- Template implementation
1. inherit QGLWidget, QOpenGLFunctions
2. override initializeGL(), paintGL(), resizeGL()
3. need to call initializeOpenGLFunctions() in initializeGL(), or runtime error will be occurred
