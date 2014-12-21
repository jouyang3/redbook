#include "firstprogram.h"
#include "loadshaders.h"

#include <iostream>
using namespace std;

#define BUFFER_OFFSET(offset) ((void *)(offset))

FirstProgram::FirstProgram(QWindow *parent)
{
    fprintf(stderr, "[firstprogram.cpp] constructor called.\n");
}

FirstProgram::~FirstProgram(){
    glDeleteVertexArrays(NumVAOs, VAOs);
}

void FirstProgram::initialize(){
    fprintf(stderr, "[firstprogram.cpp] initialization called.\n");
    fprintf(stderr, "[firstprogram.cpp] NumVAOs %i.\n", sizeof(VAOs));

    //Creates+Obtain 1 Unused VAO name, and make the name current + initialize to default state
    glGenVertexArrays(NumVAOs, VAOs);

    //Creates a Vertex Array Object via the current VAO name and make this vertex array object active
    glBindVertexArray(VAOs[Triangles]);

    //Test out glIsVertexArray
    fprintf(stderr, "[firstprogram.cpp] Vertex Array Object Name '%i' is%sallocated.\n",
            VAOs[Triangles], glIsVertexArray(VAOs[Triangles])?" ":" not ");

    fprintf(stderr, "[firstprogram.cpp] creating vertices.\n");
    GLfloat vertices[NumVertices][2] = {
        { -0.90, -0.90 }, // Triangle 1
        {  0.85, -0.90 },
        { -0.90,  0.85 },
        {  0.90, -0.85 }, // Triangle 2
        {  0.90,  0.90 },
        { -0.85,  0.90 }
    };

    fprintf(stderr, "[firstprogram.cpp] creating buffers.\n");
    glGenBuffers(NumBuffers, Buffers);

    fprintf(stderr, "[firstprogram.cpp] binding buffers.\n");
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);

    fprintf(stderr, "[firstprogram.cpp] writing buffer vertice data.\n");
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    fprintf(stderr, "[firstprogram.cpp] after writing buffer vertice data.\n");

    ShaderInfo shaders[] = {
        { GL_VERTEX_SHADER,     "triangles.vert" },
        { GL_FRAGMENT_SHADER,   "triangles.frag" },
        { GL_NONE, NULL }
    };

    fprintf(stderr, "[firstprogram.cpp] before loading shaders.\n");
    GLuint program = LoadShaders(shaders, this);
    fprintf(stderr, "[firstprogram.cpp] program id: %i\n", program);
    glUseProgram(program);

    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
}

void FirstProgram::render(){
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(VAOs[Triangles]);
    glDrawArrays(GL_TRIANGLES, 0, NumVertices);
    glFlush();
}
