#ifndef ZSandbox_h
#define ZSandbox_h

#include "Sandbox/ISandbox.h"

namespace Zen
{
    class ZSandbox : public ISandbox
    {
    public:
        static ISandbox* GetInstance()
        {
            if(_instance == nullptr)
            {
                _instance = new ZSandbox();
            }
            
            return _instance;
        }

        ~ZSandbox();
        virtual void Render()                        override;
        virtual void RenderGUI()                     override;
        virtual void KeyPressed(int key, int action) override;
        
    private:
        ZSandbox();
        
        void OnClose();
        void Examples();
        
    private:
        static ISandbox* _instance;
        ISandbox*        _activeSandbox;
    };

#define ZSANDBOX Zen::ZSandbox::GetInstance()
}

#endif /* Sandbox_h */
