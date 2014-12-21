#ifndef FIRSTPROGRAM_H
#define FIRSTPROGRAM_H

#include "openglwindow.h"

class FirstProgram : public OpenGLWindow
{
public:
    FirstProgram(QWindow* parent = 0);
    ~FirstProgram();

    void initialize();
    void render();

private:
    enum VAO_IDs { Triangles, NumVAOs };
    enum Buffer_IDs { ArrayBuffer, NumBuffers };
    enum Attrib_IDs { vPosition = 0 };

    GLuint VAOs[NumVAOs];
    GLuint Buffers[NumBuffers];

    static const GLuint NumVertices = 6;
};

#endif // FIRSTPROGRAM_H
