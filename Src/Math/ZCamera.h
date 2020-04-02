#ifndef ZCamera_h
#define ZCamera_h

#include "Math/ZVector.h"

namespace Zen
{
    class ZCamera
    {
    public:
        void SetPos(const ZVector3f& vec){ _pos = vec; }
        void SetTarget(const ZVector3f& vec){ _target = vec;}
        void SetUp(const ZVector3f& vec){ _up = vec;}
        
        const ZVector3f& GetPos() const { return _pos;}
        const ZVector3f& GetTarget() const { return _target; }
        const ZVector3f& GetUp() const { return _up;}
    private:
        ZVector3f _pos;
        ZVector3f _target;
        ZVector3f _up;
    };
}

#endif /* ZCamera_h */
