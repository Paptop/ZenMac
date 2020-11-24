#ifndef zen_example_color_interpolation_h
#define zen_example_color_interpolation_h

#include "imgui.h"

#include "Sandbox/ISandbox.h"

#include <glad/glad.h>

#include "Math/ZVector.h"

#include "IO/ZFileLoader.h"
#include "Graphics/GL/ZShaderGL.h"

namespace Zen
{
    class Zen_Color_Interpolation : public ISandbox
    {
    public:
        Zen_Color_Interpolation()
        {
            const std::string& vertShader = Zen::ZFileLoader::LoadTextFile(_vertPath);
            const std::string& fragShader = Zen::ZFileLoader::LoadTextFile(_fragPath);
            GL::MakeProgram(_sh, vertShader.c_str(), fragShader.c_str());
    
            _aVertex[0] = {-0.5f ,-0.5f, 0.0f};
            _aVertex[1] = {0.0f , 0.5f, 0.0f};
            _aVertex[2] = {0.5f , -0.5f, 0.0f};
            
            glGenVertexArrays(1, &_VAO);
            glGenBuffers(1, &_VBO);
            glBindVertexArray(_VAO);

            glBindBuffer(GL_ARRAY_BUFFER, _VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(_aVertex), _aVertex, GL_DYNAMIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ZVector3f), 0);
            glEnableVertexAttribArray(0);
        }
        
        ~Zen_Color_Interpolation()
        {
        }
        
        virtual void Render() override
        {
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            GL::Use(_sh);
            glBindVertexArray(_VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }
        
        virtual void RenderGUI() override
        {
            ImGui::Begin("Zen_Example_Color_Interpolation");
        }
        
    private:
        GL::ZShaderGL   _sh;
        ZVector3f       _aVertex[3];
        const char*     _vertPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/ColorInterpolation/GLSL/triangle.vert";
        const char*     _fragPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/ColorInterpolation/GLSL/triangle.frag";
        uint32_t        _VBO;
        uint32_t        _VAO;
    };
}
#endif // zen_example_color_interpolation_h
