#include "Math/ZPipeline.h"

#include "Math/ZMath.h"


void Zen::ZPipeline::SetTranslation(const ZVector3f& trans)
{
    _trans = trans;
}

void Zen::ZPipeline::SetRotation(const ZVector3f& rotation)
{
    _rotation = rotation;
    _rotation.x = TO_RAD(rotation.x); _rotation.y = TO_RAD(rotation.y); _rotation.z = TO_RAD(rotation.z);
}

void Zen::ZPipeline::SetScale(const ZVector3f& scale)
{
    _scale = scale;
}

void Zen::ZPipeline::GetTransform(ZMatrix4f &transform)
{
    //TODO: optimise
    ZMatrix4f _Mtrans, _Mrot, _Mscale;
    _Mtrans.SetTranslation(_trans);
    _Mrot.SetRotation(_rotation);
    _Mscale.SetScale(_scale);
    transform = _Mtrans * _Mrot * _Mscale;
}
