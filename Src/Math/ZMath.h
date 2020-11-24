#ifndef ZMath_h
#define ZMath_h

#define PI 3.14159265359
#define TO_RAD(deg) deg * PI / 180

#include "Math/ZMath_types.h"

namespace Zen{ namespace Math{

    float fLerp(float A, float B, float fProgress);

    //Vec3f
    float Length(const ZVec3f& vec);
    void Cross(const ZVec3f& res, const ZVec3f& v0, const ZVec3f& v1);
    void Normalize(ZVec3f& vec);
    void EmptyV3f(ZVec3f& vec);

    //Mat4f
    void SetScale(ZMat4f& res, const ZVec3f& scale);
    void SetTranslation(ZMat4f& res, const ZVec3f& trans);
    void SetRotation(ZMat4f& res, const ZVec3f& rotation);
    void EmptyM4f(ZMat4f& mat);
    void Identity(ZMat4f& mat);

    //3D
    void CalcProjection(ZMat4f& res, const ZProjection& proj);
    void CalcCameraTransform(ZMat4f& mat, const ZVec3f& target, const ZVec3f& up);

}}

#endif /* ZMath_h */
