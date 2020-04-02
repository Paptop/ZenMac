#include "Math/ZPipeline.h"

#include "Math/ZMath.h"

Zen::ZPipeline::ZPipeline()
{
    _camera.SetUp({0.0f, 1.0f, 0.0f});
    _camera.SetPos({1.0f, 1.0f, -3.0f});
    _camera.SetTarget({-0.45f, 0.0f, 1.0f});
}

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
    ZMatrix4f _Mtrans, _Mrot, _Mscale,
              _MProjection, _MCameraT, _MCameraR;
    
    const ZVector3f& camPos = _camera.GetPos();
    
    _Mtrans.SetTranslation(_trans);
    _Mrot.SetRotation(_rotation);
    _Mscale.SetScale(_scale);
    _MCameraT.SetTranslation({-camPos.x, -camPos.y, -camPos.z});
    
    
    GetPerspectiveProjection(_MProjection);
    GetCameraTransform(_MCameraR, _camera.GetTarget(), _camera.GetUp());
    
    transform = _MProjection * _MCameraT * _MCameraR * _Mtrans * _Mrot * _Mscale;
}

void Zen::ZPipeline::GetPerspectiveProjection(ZMatrix4f& projection)
{
    const float ar = _projection._width/ _projection._height;
    const float zNear = _projection._zNear;
    const float zFar = _projection._zFar;
    const float zRange = zNear - zFar;
    const float tanHalfFOV = tanf(TO_RAD(_projection._fov / 2.0));
    
    projection.m[0][0] = 1.0f / (tanHalfFOV * ar);
    projection.m[0][1] = 0.0f;
    projection.m[0][2] = 0.0f;
    projection.m[0][3] = 0.0f;
    
    projection.m[1][0] = 0.0f;
    projection.m[1][1] = 1.0f / tanHalfFOV;
    projection.m[1][2] = 0.0f;
    projection.m[1][3] = 0.0f;
    
    projection.m[2][0] = 0.0f;
    projection.m[2][1] = 0.0f;
    projection.m[2][2] = (-zNear - zFar) / zRange;
    projection.m[2][3] = 2.0f * zFar * zNear / zRange;
    
    projection.m[3][0] = 0.0f;
    projection.m[3][1] = 0.0f;
    projection.m[3][2] = 1.0f;
    projection.m[3][3] = 0.0f;
}

void Zen::ZPipeline::GetCameraTransform(ZMatrix4f& matrix, const ZVector3f& target, const ZVector3f& Up)
{
    ZVector3f N = target;
    N.Normalize();
    ZVector3f U = Up;
    U = U.Cross(target);
    U.Normalize();
    ZVector3f V = N.Cross(U);
    
    matrix.m[0][0] = U.x;
    matrix.m[0][1] = U.y;
    matrix.m[0][2] = U.z;
    matrix.m[0][3] = 0.0f;
    
    matrix.m[1][0] = V.x;
    matrix.m[1][1] = V.y;
    matrix.m[1][2] = V.z;
    matrix.m[1][3] = 0.0f;
    
    matrix.m[2][0] = N.x;
    matrix.m[2][1] = N.y;
    matrix.m[2][2] = N.z;
    matrix.m[2][3] = 0.0f;
    
    matrix.m[3][0] = 0.0f;
    matrix.m[3][1] = 0.0f;
    matrix.m[3][2] = 0.0f;
    matrix.m[3][3] = 1.0f;
}
