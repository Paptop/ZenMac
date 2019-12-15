#ifndef ZPipeline_h
#define ZPipeline_h

#include "Math/ZVector.h"
#include "Math/ZMatrix.h"

namespace Zen
{
    class ZPipeline
    {
    public:
        void SetTranslation(const ZVector3f& trans);
        void SetRotation(const ZVector3f& rotation);
        void SetScale(const ZVector3f& scale);
        
        void GetTransform(ZMatrix4f& transform);
    private:
        ZVector3f   _trans;
        ZVector3f   _rotation;
        ZVector3f   _scale;
    };
}

#endif /* ZPipeline_h */
