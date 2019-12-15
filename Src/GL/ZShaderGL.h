#ifndef ZShaderGL_h
#define ZShaderGL_h

#include "Utils/ZType.h"
#include "Math/ZMatrix.h"

#include <string>
#include <glad/glad.h>

namespace Zen
{
    class ZShaderGL
    {
    public:
        ZShaderGL();
        ZShaderGL(const GLchar* vertexShader, const GLchar* fragmentShader);
        
        void MakeProgram(const GLchar* vertexShader, const GLchar* fragmentShader);
        
        void SetBool(const std::string& name, bool value)                const;
        void SetInt(const std::string& name, int value)                  const;
        void SetFloat(const std::string& name, float value)              const;
        void SetVector3f(const std::string& name, float* value)          const;
        void SetMatrix4f(const std::string& name, const ZMatrix4f& mat)  const;

        void Use();

    private:
        void AssembleProgram(const GLchar* vertexShader, const GLchar* fragmentShader);
        int CreateAndCompile(GLenum shaderType, const GLchar* src);
        int CreateProgram(u32 vertexShader, u32 fragmentShader);
        
    private:
        int         _iID;
    };
}

#endif /* ZShaderGL_h */
