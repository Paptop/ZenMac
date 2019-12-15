#ifndef zen_example_translation_h
#define zen_example_translation_h

#include "imgui.h"

#include "Sandbox/ISandbox.h"

#include <glad/glad.h>

#include "Math/ZMatrix.h"
#include "Math/ZVector.h"
#include "Math/ZPipeline.h"

#include "IO/ZFileLoader.h"
#include "GL/ZShaderGL.h"

/*
 M
 [1] [0] [0] [X]
 [0] [1] [0] [Y]
 [0] [0] [1] [Z]
 [0] [0] [0] [1]
 
 T(M)
 [X] [Y] [Z] [1]
 [0] [0] [1] [0]
 [0] [1] [0] [0]
 [1] [0] [0] [0]
 */
namespace Zen
{
    class Zen_Example_Translation : public ISandbox
    {
    public:
        Zen_Example_Translation()
        : _shader()
        , _VBO(-1)
        , _VAO(-1)
        {
            const std::string& vertShader = Zen::ZFileLoader::LoadTextFile(_vertPath);
            const std::string& fragShader = Zen::ZFileLoader::LoadTextFile(_fragPath);
            _shader.MakeProgram(vertShader.c_str(), fragShader.c_str());
            
            _aVertex[0] = {-0.5f ,-0.5f, 0.0f};
            _aVertex[1] = {0.0f , 0.5f, 0.0f};
            _aVertex[2] = {0.5f , -0.5f, 0.0f};
            _aVertex[3] = {0.0f,  0.0f,  1.0f};
            
            glGenVertexArrays(1, &_VAO);
            glGenBuffers(1, &_VBO);
            glBindVertexArray(_VAO);
            
            glBindBuffer(GL_ARRAY_BUFFER, _VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(_aVertex), _aVertex, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ZVector3f), 0);
            glEnableVertexAttribArray(0);
            
            _pipe.SetScale({2.0f, 2.0f ,2.0f});
            _pipe.SetRotation({45.0f, 45.0f, 0.0});
        }
        
        virtual void Render()
        {
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            _shader.Use();
            
            _pipe.GetTransform(_mvp);
            _shader.SetMatrix4f("MVP", _mvp);
            glBindVertexArray(_VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }
        
        virtual void RenderGUI()
        {
            ImGui::Begin("Zen_Example_Triangle");
        }
        
        
    private:
        ZShaderGL   _shader;
        ZVector3f   _aVertex[4];
        ZMatrix4f   _mvp;
        ZPipeline   _pipe;
        const char* _vertPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/Translation/GLSL/translation.vert";
        const char* _fragPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/Translation/GLSL/translation.frag";
        u32         _VBO;
        u32         _VAO;
    };
}

#endif /* zen_example_translation_h */
