#ifndef ZShaderGL_h
#define ZShaderGL_h

#include "Math/ZMath.h"
#include "Graphics/GL/ZGL_Types.h"

//TODO: Change to const char*
#include <string>

namespace Zen { namespace GL{

    void MakeProgram(ZShaderGL& sh, const char* vertexShader, const char* fragmentShader);
    
    //TODO: it can be a template
    void SetBool(const ZShaderGL& sh,     const char* name, bool value);
    void SetInt(const ZShaderGL& sh,      const char* name, int value);
    void SetFloat(const ZShaderGL& sh,    const char* name, float value);
    void SetVector3f(const ZShaderGL& sh, const char* name, float* value);
    void SetMatrix4f(const ZShaderGL& sh, const char* name, const Math::ZMat4f& mat);

    void Use(ZShaderGL& sh);


        
}};

#endif //Shader calls
