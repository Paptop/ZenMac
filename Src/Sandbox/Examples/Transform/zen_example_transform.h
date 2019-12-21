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

namespace Zen
{
    class Zen_Example_Transform : public ISandbox
    {
    public:
        Zen_Example_Transform()
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
            
            glGenVertexArrays(1, &_VAO);
            glGenBuffers(1, &_VBO);
            glBindVertexArray(_VAO);
            
            glBindBuffer(GL_ARRAY_BUFFER, _VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(_aVertex), _aVertex, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ZVector3f), 0);
            glEnableVertexAttribArray(0);
            
            _scale = {1.0f, 1.0f, 1.0f};
            _translations = {0.0f, 0.0f, 0.0f};
            _rotations = {0.0f, 0.0f, 0.0f};
        }
        
        virtual void Render()
        {
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            _pipe.SetScale(_scale);
            _pipe.SetRotation(_rotations);
            _pipe.SetTranslation(_translations);
            
            _pipe.GetTransform(_mvp);
            _shader.SetMatrix4f("mvp", _mvp);
            
            _shader.Use();
            glBindVertexArray(_VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }
        
        virtual void RenderGUI()
        {
            ImGui::Begin("Zen_Example_Triangle");
            
            ImGui::SliderFloat("RotationX", &_rotations.x, -360.0f, 360.0f);
            ImGui::SliderFloat("RotationY", &_rotations.y, -360.0f, 360.0f);
            ImGui::SliderFloat("RotationZ", &_rotations.z, -360.0f, 360.0f);

			ImGui::SliderFloat("TranslationX", &_translations.x, -1.0f, 1.0f);
			ImGui::SliderFloat("TranslationY", &_translations.y, -1.0f, 1.0f);
			ImGui::SliderFloat("TranslationZ", &_translations.z, -1.0f, 1.0f);

			ImGui::SliderFloat("ScaleX", &_scale.x, -2.0f, 2.0f);
			ImGui::SliderFloat("ScaleY", &_scale.y, -2.0f, 2.0f);
			ImGui::SliderFloat("ScaleZ", &_scale.z, -2.0f, 2.0f);
        }
        
        
    private:
        ZShaderGL   _shader;
        ZVector3f   _aVertex[4];
        ZMatrix4f   _mvp;
        ZPipeline   _pipe;
        const char* _vertPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/Transform/GLSL/translation.vert";
        const char* _fragPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/Transform/GLSL/translation.frag";
        u32         _VBO;
        u32         _VAO;
        
        //Specific
        ZVector3f   _rotations;
        ZVector3f   _translations;
        ZVector3f   _scale;
    };
}

#endif /* zen_example_translation_h */
