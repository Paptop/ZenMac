#ifndef zen_example_color_h
#define zen_example_color_h

#include "imgui.h"

#include "Sandbox/ZSandbox.h"

#include <glad/glad.h>

namespace Zen
{
    class Zen_Example_Color : public ISandbox
    {
    public:
        Zen_Example_Color()
        {
        }
        
        ~Zen_Example_Color()
        {
        }
        
        virtual void Render()
        {
            glClearColor(clear_color[0], clear_color[1], clear_color[2], clear_color[3]);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        
        virtual void RenderGUI()
        {
            ImGui::Begin("Zen_Example_Triangle");
            ImGui::Text("Pick a color!");
            ImGui::ColorEdit4("clear color", (float*)&clear_color);
        }
    private:
        float clear_color[4];
    };
}
#endif /* zen_example_color_h */
