#include "loadshaders.h"

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

GLuint LoadShaders( ShaderInfo* shaders, QObject* parent)
{
    if ( shaders == NULL ) { return 0; }

    QOpenGLShaderProgram* prog = new QOpenGLShaderProgram(parent);

    ShaderInfo* entry = shaders;

    QOpenGLShader::ShaderType type;

    while ( entry->type != GL_NONE){
        switch(entry->type){
        case GL_VERTEX_SHADER: type = QOpenGLShader::Vertex; break;
        case GL_FRAGMENT_SHADER: type = QOpenGLShader::Fragment; break;
        case GL_GEOMETRY_SHADER: type = QOpenGLShader::Geometry; break;
        case GL_TESS_CONTROL_SHADER: type = QOpenGLShader::TessellationControl; break;
        case GL_TESS_EVALUATION_SHADER: type = QOpenGLShader::TessellationEvaluation; break;
        default: type = QOpenGLShader::Vertex;
        }

        fprintf(stderr, "[loadshaders.cpp] entry->filename: %s\n", entry->filename);
        prog->addShaderFromSourceFile(type, entry->filename);
        entry++;
    }
    prog->link();

    return prog->programId();
}

#ifdef __cplusplus
}
#endif // __cplusplus
