#include "GL/ZShaderGL.h"

#include "Utils/ZDebug.h"


Zen::ZShaderGL::ZShaderGL()
: _iID(-1)
{
}

Zen::ZShaderGL::ZShaderGL(const GLchar* vertexShader, const GLchar* fragmentShader)
{
    AssembleProgram(vertexShader, fragmentShader);
}

void Zen::ZShaderGL::MakeProgram(const GLchar* vertexShader, const GLchar* fragmentShader)
{
    AssembleProgram(vertexShader, fragmentShader);
}

void Zen::ZShaderGL::SetBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(_iID, name.c_str()), (int)value);
}

void Zen::ZShaderGL::SetInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(_iID, name.c_str()), (int)value);
}

void Zen::ZShaderGL::SetFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(_iID, name.c_str()), value);
}

void Zen::ZShaderGL::SetVector3f(const std::string& name, float* values) const
{
    glUniform3fv(glGetUniformLocation(_iID, name.c_str()), 1, values);
}

void Zen::ZShaderGL::SetMatrix4f(const std::string& name, const ZMatrix4f& mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(_iID, name.c_str()), 1, GL_TRUE, &mat.m[0][0]);
}

void Zen::ZShaderGL::Use()
{
    ASSERT(_iID >= 0, "Program not set");
    glUseProgram(_iID);
}

void Zen::ZShaderGL::AssembleProgram(const GLchar* vertexShader, const GLchar* fragmentShader)
{
    u32 iVertex = CreateAndCompile(GL_VERTEX_SHADER, vertexShader);
    u32 iFrag = CreateAndCompile(GL_FRAGMENT_SHADER, fragmentShader);
    CreateProgram(iVertex, iFrag);
}

int Zen::ZShaderGL::CreateAndCompile(GLenum shaderType, const GLchar* src)
{
    const int kBufferSize = 512;
    char info[kBufferSize];
    int success;

    u32 iShaderID = glCreateShader(shaderType);
    glShaderSource(iShaderID, 1, &src, nullptr);
    glCompileShader(iShaderID);
    glGetShaderiv(iShaderID, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(iShaderID, kBufferSize, nullptr, info);
        strcat(info, "[Error] shader compiled with error\n");
        ASSERT(false, info);
        return -1;
    }

    return iShaderID;
}

int Zen::ZShaderGL::CreateProgram(u32 vertexShader, u32 fragmentShader)
{
    const int kBufferSize = 512;
    char info[kBufferSize];
    int success;

    _iID = glCreateProgram();
    glAttachShader(_iID, vertexShader);
    glAttachShader(_iID, fragmentShader);
    glLinkProgram(_iID);

    // print linking errors if any
    glGetProgramiv(_iID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(_iID, 512, NULL, info);
        strcat(info, "[Error] shader compiled with error\n");
        ASSERT(false, info);
        return -1;
    }


    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return 0;
}
