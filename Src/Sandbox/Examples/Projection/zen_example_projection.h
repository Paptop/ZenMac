#ifndef zen_example_projection_h
#define zen_example_projection_h

#include "imgui.h"

#include "Sandbox/ISandbox.h"

#include <glad/glad.h>

#include "Math/ZMatrix.h"
#include "Math/ZVector.h"
#include "Math/ZPipeline.h"
#include "Math/ZMath.h"

#include "IO/ZFileLoader.h"
#include "Graphics/GL/ZShaderGL.h"

namespace Zen
{
    class Zen_Example_Projection : public ISandbox
    {
    public:
        Zen_Example_Projection()
        : _VBO(-1)
        , _VAO(-1)
        , _IBO(-1)
        {
            const std::string& vertShader = Zen::ZFileLoader::LoadTextFile(_vertPath);
            const std::string& fragShader = Zen::ZFileLoader::LoadTextFile(_fragPath);
            GL::MakeProgram(_zsh, vertShader.c_str(), fragShader.c_str());
            
            _aVertex[0] = {-0.5f , 0.5f, 0.0f};
            _aVertex[1] = {0.5f , 0.5f, 0.0f};
            _aVertex[2] = {0.5f , -0.5f, 0.0f};
            _aVertex[3] = {-0.5f, -0.5f, 0.0f};
            _aVertex[4] = {0.0f, 0.0f, -1.0f};
            
            _aIndices[0] = 0;
            _aIndices[1] = 1;
            _aIndices[2] = 2;
            
            _aIndices[3] = 0;
            _aIndices[4] = 3;
            _aIndices[5] = 2;
            
            _aIndices[6] = 0;
            _aIndices[7] = 4;
            _aIndices[8] = 1;
            
            _aIndices[9]  = 1;
            _aIndices[10] = 4;
            _aIndices[11] = 2;
            
            _aIndices[12] = 2;
            _aIndices[13] = 4;
            _aIndices[14] = 3;
            
            _aIndices[15] = 3;
            _aIndices[16] = 4;
            _aIndices[17] = 0;
            
            
            glGenVertexArrays(1, &_VAO);
            glGenBuffers(1, &_VBO);
            glBindVertexArray(_VAO);
            
            glBindBuffer(GL_ARRAY_BUFFER, _VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(_aVertex), _aVertex, GL_STATIC_DRAW);
            
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ZVector3f), 0);
            
            glGenBuffers(1, &_IBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _IBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_aIndices), _aIndices, GL_STATIC_DRAW);
            
            _scale = {1.0f, 1.0f, 1.0f};
            _translations = {0.0f, 0.0f, 0.0f};
            _rotations = {0.0f, 0.0f, 0.0f};
        }
        
        virtual void Render()
        {
            UpdateAnimation(0.0f);
            
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            _pipe.SetScale(_scale);
            _pipe.SetRotation(_rotations);
            _pipe.SetTranslation(_translations);
            
            _pipe.GetTransform(_mvp);
            
            GL::SetMatrix4f(_zsh, "mvp", _mvp);
            GL::Use(_zsh);
            
            glBindVertexArray(_VAO);
            glDrawElements(GL_TRIANGLES, sizeof(_aIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
        }
        
        virtual void RenderGUI()
        {
            ImGui::Begin("Zen_Example_Triangle");
            
            ImGui::SliderFloat("RotationX", &_rotations.x, -360.0f, 360.0f);
            ImGui::SliderFloat("RotationY", &_rotations.y, -360.0f, 360.0f);
            ImGui::SliderFloat("RotationZ", &_rotations.z, -360.0f, 360.0f);

            ImGui::SliderFloat("ScaleX", &_scale.x, -2.0f, 2.0f);
            ImGui::SliderFloat("ScaleY", &_scale.y, -2.0f, 2.0f);
            ImGui::SliderFloat("ScaleZ", &_scale.z, -2.0f, 2.0f);

            ImGui::SliderFloat("TranslationX", &_translations.x, -1.0f, 1.0f);
            ImGui::SliderFloat("TranslationY", &_translations.y, -1.0f, 1.0f);
            ImGui::SliderFloat("TranslationZ", &_translations.z, -1000.0f, 1000.0f);
        }
        
        void UpdateAnimation(float fDelta)
        {
            _fProgress += 0.1f * 0.001f;
            
            if(_fProgress >= 1.0f)
            {
                _fProgress = 0.0f;
            }
            
            _translations.z = Zen::fLerp(0.0f, 25.0f, _fProgress);
            _rotations.z = Zen::fLerp(0.0f, 90.0f, _fProgress);
            _rotations.y = Zen::fLerp(-90.0f, 90.0f, _fProgress);
        }
        
        
    private:
        GL::ZShaderGL   _zsh;
        ZVector3f       _aVertex[5];
        int             _aIndices[18];
        ZMatrix4f       _mvp;
        ZPipeline       _pipe;
        const char*     _vertPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/Projection/GLSL/projection.vert";
        const char*     _fragPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/Projection/GLSL/projection.frag";
        uint32_t        _VBO;
        uint32_t        _IBO;
        uint32_t        _VAO;
        float           _fProgress;
        
        //Specific
        ZVector3f   _rotations;
        ZVector3f   _translations;
        ZVector3f   _scale;
    };
}

#endif /* zen_example_translation_h */

