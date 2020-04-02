#ifndef ZPipeline_h
#define ZPipeline_h

#include "Math/ZVector.h"
#include "Math/ZMatrix.h"
#include "Math/ZProjection.h"
#include "Math/ZCamera.h"

namespace Zen
{
    class ZPipeline
    {
    public:
        ZPipeline();
        void SetTranslation(const ZVector3f& trans);
        void SetRotation(const ZVector3f& rotation);
        void SetScale(const ZVector3f& scale);
        
        void GetTransform(ZMatrix4f& transform);
        void GetPerspectiveProjection(ZMatrix4f& projection);
        void GetCameraTransform(ZMatrix4f& matrix, const ZVector3f& Target, const ZVector3f& Up);
        
        ZCamera& GetCamera() { return _camera;}
        const ZCamera& GetCamera() const { return _camera; }
    private:
        ZVector3f   _trans;
        ZVector3f   _rotation;
        ZVector3f   _scale;
        ZProjection _projection;
        ZCamera     _camera;
    };
}

#endif /* ZPipeline_h */
