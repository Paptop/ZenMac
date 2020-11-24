#include "Graphics/GL/ZShaderGL.h"

#include "Utils/ZDebug.h"

#include <glad/glad.h>

namespace Zen { namespace GL{

//-- Private functions
    void AssembleProgram(ZShaderGL& sh, const GLchar* vertexShader, const GLchar* fragmentShader);
    int CreateAndCompile(ZShaderGL& sh, GLenum shaderType, const GLchar* src);
    int CreateProgram(ZShaderGL& sh, uint32_t vertexShader, uint32_t fragmentShader);
//---

    void MakeProgram(ZShaderGL& sh, const char* vertexShader, const char* fragmentShader)
    {
        AssembleProgram(sh, vertexShader, fragmentShader);
    }

    void SetBool(ZShaderGL& sh, const char* name, bool value)
    {
        glUniform1i(glGetUniformLocation(sh._id, name), (int)value);
    }

    void SetInt(ZShaderGL& sh, const char* name, int value)
    {
        glUniform1i(glGetUniformLocation(sh._id, name), (int)value);
    }

    void SetFloat(ZShaderGL& sh, const char* name, float value)
    {
        glUniform1f(glGetUniformLocation(sh._id, name), value);
    }

    void SetVector3f(ZShaderGL& sh, const char* name, float* values)
    {
        glUniform3fv(glGetUniformLocation(sh._id, name), 1, values);
    }

    void SetMatrix4f(const ZShaderGL& sh, const char* name, const ZMatrix4f& mat)
    {
        glUniformMatrix4fv(glGetUniformLocation(sh._id, name), 1, GL_TRUE, &mat.m[0][0]);
    }

    void Use(ZShaderGL& sh)
    {
        ASSERT(sh._id >= 0, "Program not set");
        glUseProgram(sh._id);
    }

    void AssembleProgram(ZShaderGL& sh, const char* vertexShader, const char* fragmentShader)
    {
        uint32_t iVertex = CreateAndCompile(sh, GL_VERTEX_SHADER, vertexShader);
        uint32_t iFrag = CreateAndCompile(sh, GL_FRAGMENT_SHADER, fragmentShader);
        CreateProgram(sh, iVertex, iFrag);
    }

    int CreateAndCompile(ZShaderGL& sh, GLenum shaderType, const GLchar* src)
    {
        const int kBufferSize = 512;
        char info[kBufferSize];
        int success;

        uint32_t iShaderID = glCreateShader(shaderType);
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

    int CreateProgram(ZShaderGL& sh, uint32_t vertexShader, uint32_t fragmentShader)
    {
        const int kBufferSize = 512;
        char info[kBufferSize];
        int success;

        sh._id = glCreateProgram();
        glAttachShader(sh._id, vertexShader);
        glAttachShader(sh._id, fragmentShader);
        glLinkProgram(sh._id);

        // print linking errors if any
        glGetProgramiv(sh._id, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(sh._id, 512, NULL, info);
            strcat(info, "[Error] shader compiled with error\n");
            ASSERT(false, info);
            return -1;
        }


        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return 0;
    }

}}
