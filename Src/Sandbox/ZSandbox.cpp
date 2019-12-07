#include "imgui.h"

#include "Sandbox/ZSandbox.h"

#include "Sandbox/Examples/zen_example_color.h"
#include "Sandbox/Examples/zen_example_triangle.h"


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

void Zen::ZSandbox::OnClose()
{
    delete _activeSandbox;
    _activeSandbox = nullptr;
}

void Zen::ZSandbox::Examples()
{
    if (ImGui::Button("zen_example_triangle"))
    {
        _activeSandbox = new Zen_Example_Triangle();
    }
    else if(ImGui::Button("zen_example_color"))
    {
        _activeSandbox = new Zen_Example_Color();
    }
}