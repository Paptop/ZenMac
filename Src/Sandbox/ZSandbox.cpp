#include "imgui.h"

#include "Sandbox/ZSandbox.h"

#include "Sandbox/Examples/Color/zen_example_color.h"
#include "Sandbox/Examples/Triangle/zen_example_triangle.h"
#include "Sandbox/Examples/ColorInterpolation/zen_example_color_interpolation.h"
#include "Sandbox/Examples/Transform/zen_example_transform.h"
#include "Sandbox/Examples/Projection/zen_example_projection.h"
#include "Sandbox/Examples/Camera/zen_example_camera.h"


#include <glad/glad.h>

Zen::ISandbox* Zen::ZSandbox::_instance = nullptr;

Zen::ZSandbox::ZSandbox()
: _activeSandbox(nullptr)
{
}


Zen::ZSandbox::~ZSandbox()
{
    if(_activeSandbox)
    {
        delete _activeSandbox;
    }
}

void Zen::ZSandbox::Render()
{
    glClearColor(0.0f,1.0f,1.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if(_activeSandbox)
    {
        _activeSandbox->Render();
    }
}

void Zen::ZSandbox::RenderGUI()
{
    ImGui::NewFrame();
    
    if(_activeSandbox)
    {
        _activeSandbox->RenderGUI();
        
        if(ImGui::Button("Close"))
        {
            OnClose();
        }
        
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
        ImGui::Render();
        return;
    }

    ImGui::Begin("Zen examples");
    Examples();
    ImGui::SameLine();
    ImGui::End();
    ImGui::Render();
}

void Zen::ZSandbox::KeyPressed(int key, int action)
{
    if(!_activeSandbox)
    {
        return;
    }
    
    _activeSandbox->KeyPressed(key, action);
}

void Zen::ZSandbox::OnClose()
{
    delete _activeSandbox;
    _activeSandbox = nullptr;
}

void Zen::ZSandbox::Examples()
{
    if(ImGui::Button("Color"))
    {
        _activeSandbox = new Zen_Example_Color();
    }
    else if (ImGui::Button("Triangle"))
    {
        _activeSandbox = new Zen_Example_Triangle();
    }
    else if (ImGui::Button("ColorLerp"))
    {
        _activeSandbox = new Zen_Color_Interpolation();
    }
    else if (ImGui::Button("Transform"))
    {
        _activeSandbox = new Zen_Example_Transform();
    }
    else if (ImGui::Button("Projection"))
    {
        _activeSandbox = new Zen_Example_Projection();
    }
    else if (ImGui::Button("Camera"))
    {
        _activeSandbox = new Zen_Example_Camera();
    }
}
