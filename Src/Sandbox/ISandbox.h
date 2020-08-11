#ifndef ISANDBOX
#define ISANDBOX

namespace Zen
{
    class ISandbox
    {
    public:
        virtual void Render() {};
        virtual void RenderGUI(){};
        virtual void KeyPressed(int key, int action){};
    };
}

#endif // ISANDBOX
