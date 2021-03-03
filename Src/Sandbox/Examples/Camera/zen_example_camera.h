#ifndef zen_example_camera_h
#define zen_example_camera_h

#include "imgui.h"

#include "Sandbox/ISandbox.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Math/ZMath.h"

#include "IO/ZFileLoader.h"
#include "Graphics/GL/ZShaderGL.h"
#include "Graphics/GL/ZGL.h"

namespace Zen
{
    class Zen_Example_Camera : public ISandbox
    {
    public:
        Zen_Example_Camera()
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

            
            GL::GenBindVertexArray(_VAO, 1);
            GL::GenBindBuffer<Math::ZVec3f>(GL_ARRAY_BUFFER, _VBO, _aVertex);
            GL::EnableAttributes(0, 3, GL_FLOAT, GL_FALSE, sizeof(Math::ZVec3f), 0);
            GL::GenBindBuffer<int>(GL_ELEMENT_ARRAY_BUFFER, _IBO, _aIndices);
            
            _transform.pos = {0.0f, 0.0f, 10.0f};
            _transform.rot = {0.0f, 0.0f, 0.0f};
            _transform.scale = {1.0f, 1.0f, 1.0f};
            
            _camera.pos = {0.0f, 0.0f, 0.0f};
            _camera.target = {0.0f, 0.0f, 1.0f};
            _camera.up = {0.0f, 1.0f, 0.0f};
        }
        
        virtual void Render() override
        {
            UpdateAnimation(0.0f);
            GL::Clear(GL_COLOR_BUFFER_BIT);
            
            Math::CalcMVP(_mvp, _transform, _camera, _projection);
            GL::SetMatrix4f(_zsh, "mvp", _mvp);
            
            GL::Use(_zsh);
            glBindVertexArray(_VAO);
            glDrawElements(GL_TRIANGLES, sizeof(_aIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
        }
        
        virtual void RenderGUI() override
        {
            
            ImGui::Begin("Zen_Example_Triangle");
            
            /*


            ImGui::SliderFloat("ScaleX", &_scale.x, -2.0f, 2.0f);
            ImGui::SliderFloat("ScaleY", &_scale.y, -2.0f, 2.0f);
            ImGui::SliderFloat("ScaleZ", &_scale.z, -2.0f, 2.0f);

            ImGui::SliderFloat("TranslationX", &_translations.x, -1.0f, 1.0f);
            ImGui::SliderFloat("TranslationY", &_translations.y, -1.0f, 1.0f);
            ImGui::SliderFloat("TranslationZ", &_translations.z, -1000.0f, 1000.0f);
            
            ImGui::SliderFloat("CameraUpX", &_upVector.x, -10.0f, 10.0f);
            ImGui::SliderFloat("CameraUpY", &_upVector.y, -10.0f, 10.0f);
            ImGui::SliderFloat("CameraUpZ", &_upVector.z, -10.0f, 10.0f);
            
            ImGui::SliderFloat("CameraTX", &_targetVector.x, -10.0f, 10.0f);
            ImGui::SliderFloat("CameraTY", &_targetVector.y, -10.0f, 10.0f);
            ImGui::SliderFloat("CameraTZ", &_targetVector.z, -10.0f, 10.0f);
            
            ImGui::SliderFloat("CameraPosX", &_position.x, -10.0f, 10.0f);
            ImGui::SliderFloat("CameraPosY", &_position.y, -10.0f, 10.0f);
            ImGui::SliderFloat("CameraPosZ", &_position.z, -10.0f, 10.0f);
             */
            
            ImGui::SliderFloat("CameraPosX", &_camera.pos.x, -10.0f, 10.0f);
            ImGui::SliderFloat("CameraPosY", &_camera.pos.y, -10.0f, 10.0f);
            ImGui::SliderFloat("CameraPosZ", &_camera.pos.z, -10.0f, 10.0f);
            
            
            ImGui::SliderFloat("PosX", &_transform.pos.x, -10.0f, 10.0f);
            ImGui::SliderFloat("PosY", &_transform.pos.y, -10.0f, 10.0f);
            ImGui::SliderFloat("PosZ", &_transform.pos.z, -10.0f, 10.0f);
            
            ImGui::SliderFloat("RotX", &_transform.rot.x, -360.0f, 360.0f);
            ImGui::SliderFloat("RotY", &_transform.rot.y, -360.0f, 360.0f);
            ImGui::SliderFloat("RotZ", &_transform.rot.z, -360.0f, 360.0f);
            
            //ImGui::SliderFloat("RotationX", &_transform.rot.x, -360.0f, 360.0f);
            //ImGui::SliderFloat("RotationY", &_rotations.y, -360.0f, 360.0f);
            //ImGui::SliderFloat("RotationZ", &_rotations.z, -360.0f, 360.0f);

        }
        
        virtual void KeyPressed(int key, int action) override
        {
            /*
             if (key ==  && action == GLFW_PRESS)
             {
             }
             */
            
            if(key == GLFW_KEY_W && action == GLFW_PRESS)
            {
//                _position += (_targetVector * 3.0f);
            }
        }
        
        void UpdateAnimation(float fDelta)
        {
            _fProgress += 0.1f * 0.001f;
            
            if(_fProgress >= 1.0f)
            {
                _fProgress = 0.0f;
            }
            
            //_transform.pos.x = Math::fLerp(0.0f, 25.0f, _fProgress);
            //_rotations.z = Math::fLerp(0.0f, 90.0f, _fProgress);
            //_rotations.y = Math::fLerp(-90.0f, 90.0f, _fProgress);
            
            //_pipe.GetCamera().SetTarget(_targetVector);
            //_pipe.GetCamera().SetPos(_position);
            //_pipe.GetCamera().SetUp(_upVector);
        }
        
    private:
        GL::ZShaderGL   _zsh;
        Math::ZVec3f    _aVertex[5];
        int             _aIndices[18];
        
        //TODO: FIX ME PLS
        const char*     _vertPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/Camera/GLSL/camera.vert";
        const char*     _fragPath = "/Users/iljajurchenko/Dev/Zen/Src/Sandbox/Examples/Camera/GLSL/camera.frag" ;
        
        uint32_t        _VBO;
        uint32_t        _IBO;
        uint32_t        _VAO;
        float       _fProgress;
        
        //Specific
        Math::ZTransform      _transform;
        Math::ZCamera         _camera;
        Math::ZProjection     _projection;
        Math::ZMat4f          _mvp;
        
    };
}

#endif /* zen_example_translation_h */

