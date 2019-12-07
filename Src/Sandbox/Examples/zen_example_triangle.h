#ifndef zen_example_triangle_h
#define zen_example_triangle_h

#include "imgui.h"

#include "Sandbox/ZSandbox.h"

#include <glad/glad.h>

namespace Zen
{
    class Zen_Example_Triangle : public ISandbox
    {
    public:
        Zen_Example_Triangle()
        {
        }
        
        ~Zen_Example_Triangle()
        {
        }
        
        virtual void Render()
        {
            
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        
        virtual void RenderGUI()
        {
            ImGui::Begin("Zen_Example_Triangle");
            ImGui::Text("TODO: implement drawing of a triangle !");
        }
    };
};

#endif // zen_example_triangle_h
