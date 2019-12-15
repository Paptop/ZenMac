#ifndef zen_example_triangle_h
#define zen_example_triangle_h

#include "imgui.h"

#include "Sandbox/ZSandbox.h"

#include <glad/glad.h>

#include "Math/ZVector.h"

#include "IO/ZFileLoader.h"
#include "GL/ZShaderGL.h"

namespace Zen
{
    class Zen_Example_Triangle : public ISandbox
    {
    public:
        Zen_Example_Triangle()
        : _shader()
        , _VBO(-1)
        , _VAO(-1)
        {
            const std::string& vertShader = Zen::ZFileLoader::LoadTextFile(_vertPath);
            const std::string& fragShader = Zen::ZFileLoader::LoadTextFile(_fragPath);
            _shader.MakeProgram(vertShader.c_str(), fragShader.c_str());
            
            _fColor[0] = 0.0f; _fColor[1] = 1.0f; _fColor[2] = 0.0f;
            
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
        
        ~Zen_Example_Triangle()
        {
        }
        
        virtual void Render()
        {
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            _shader.Use();
            _shader.SetVector3f("zColor", _fColor);
            glBindVertexArray(_VAO);
            
            glBindBuffer(GL_ARRAY_BUFFER, _VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(_aVertex), _aVertex, GL_DYNAMIC_DRAW);
            
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }
        
        virtual void RenderGUI()
        {
            ImGui::Begin("Zen_Example_Triangle");
            ImGui::SliderFloat("V0_X", &_aVertex[0].x, -1.0f, 1.0f);
            ImGui::SliderFloat("V0_Y", &_aVertex[0].y, -1.0f, 1.0f);
            ImGui::SliderFloat("V0_Z", &_aVertex[0].z, -1.0f, 1.0f);
            ImGui::Text("\n");
            
            ImGui::SliderFloat("V1_X", &_aVertex[1].x, -1.0f, 1.0f);
            ImGui::SliderFloat("V1_Y", &_aVertex[1].y, -1.0f, 1.0f);
            ImGui::SliderFloat("V1_Z", &_aVertex[1].z, -1.0f, 1.0f);
            ImGui::Text("\n");
            
            ImGui::SliderFloat("V2_X", &_aVertex[2].x, -1.0f, 1.0f);
            ImGui::SliderFloat("V2_Y", &_aVertex[2].y, -1.0f, 1.0f);
            ImGui::SliderFloat("V2_Z", &_aVertex[2].z, -1.0f, 1.0f);
            ImGui::Text("\n");
            
            ImGui::ColorEdit4("clear color", (float*)_fColor);
        }
        
    private:
        ZShaderGL   _shader;
        ZVector3f   _aVertex[3];
        float       _fColor[3];
        const char* _vertPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/Triangle/GLSL/triangle.vert";
        const char* _fragPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/Triangle/GLSL/triangle.frag";
        u32         _VBO;
        u32         _VAO;
    };
    
};

#endif // zen_example_triangle_h
