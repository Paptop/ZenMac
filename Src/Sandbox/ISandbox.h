#ifndef ISANDBOX
#define ISANDBOX

namespace Zen
{
    class ISandbox
    {
    public:
        virtual void Render() {};
        virtual void RenderGUI(){};
    };
}

#endif // ISANDBOX
