#include "Math/ZMath.h"

#include <cmath>

namespace Zen { namespace Math {

    float fLerp(float A, float B, float fProgress)
    {
        return (1.0f - fProgress) * A + fProgress * B;
    }

    float Length(const ZVec3f& vec)
    {
        return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    }

    void Cross(ZVec3f& res, const ZVec3f& v0, const ZVec3f& v1)
    {
        res.x = v0.y * v1.z - v0.z * v1.y;
        res.y = v0.z * v1.x - v0.x * v1.z;
        res.z = v0.x * v1.y - v0.y * v1.x;
    }

    void Normalize(ZVec3f& vec)
    {
        const float fLength = Length(vec);
        vec.x /= fLength ; vec.y /= fLength ; vec.z /= fLength;
    }

    void EmptyV3f(ZVec3f& vec)
    {
        vec.x = 0.0f; vec.y = 0.0f; vec.z = 0.0f;
    }

    void SetScale(ZMat4f& res, const ZVec3f& scale)
    {
        res.m[0][0] = scale.x; res.m[1][1] = scale.y; res.m[2][2] = scale.z;
    }

    void SetTranslation(ZMat4f& res, const ZVec3f& trans)
    {
        res.m[0][3] = trans.x;
        res.m[1][3] = trans.y;
        res.m[2][3] = trans.z;
    }

    void SetRotation(ZMat4f& res, const ZVec3f& rotation)
    {
        ZMat4f rotX, rotY, rotZ;
        
        float rx = TO_RAD(rotation.x);
        float ry = TO_RAD(rotation.y);
        float rz = TO_RAD(rotation.z);
        
        rotZ[0][0] = cos(rz);  rotZ[0][1] = -sin(rz);
        rotZ[1][0] = sin(rz);  rotZ[1][1] = cos(rz);
        
        rotY[0][0] = cos(ry);  rotY[0][2] = -sin(ry);
        rotY[2][0] = sin(ry);  rotY[2][2] = cos(ry);
        
        rotX[1][1] = cos(rx);  rotX[1][2] = -sin(rx);
        rotX[2][1] = sin(rx);  rotX[2][2] = cos(rx);
        
        res = rotZ * rotY * rotX;
    }

    void EmptyM4f(ZMat4f& mat)
    {
        for(int i = 0 ; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                mat[i][j] = 0.0f;
    }

    void Identity(ZMat4f& mat)
    {
        EmptyM4f(mat);
        for(int i = 0; i < 4; ++i)
            mat[i][i] = 1.0f;
    }

    void CalcProjection(ZMat4f& res, const ZProjection& proj)
    {
        const float ar = proj.width / proj.height;
        const float zNear = proj.zNear;
        const float zFar = proj.zFar;
        const float zRange = zNear - zFar;
        const float tanHalfFOV = tanf(TO_RAD(proj.fov / 2.0f));
        
        res.m[0][0] = 1.0f / (tanHalfFOV * ar);
        res.m[0][1] = 0.0f;
        res.m[0][2] = 0.0f;
        res.m[0][3] = 0.0f;
        
        res.m[1][0] = 0.0f;
        res.m[1][1] = 1.0f / tanHalfFOV;
        res.m[1][2] = 0.0f;
        res.m[1][3] = 0.0f;
        
        res.m[2][0] = 0.0f;
        res.m[2][1] = 0.0f;
        res.m[2][2] = (-zNear - zFar) / zRange;
        res.m[2][3] = 2.0f * zFar * zNear / zRange;
        
        res.m[3][0] = 0.0f;
        res.m[3][1] = 0.0f;
        res.m[3][2] = 1.0f;
        res.m[3][3] = 0.0f;
    }

    void CalcCameraTransform(ZMat4f& mat, const ZVec3f& target, const ZVec3f& up)
    {
        ZVec3f N = target;
        Normalize(N);
        ZVec3f U;
        Cross(U,up,target);
        Normalize(U);
        ZVec3f V;
        Cross(V,N,U);
        
        mat[0][0] = U.x;
        mat[0][1] = U.y;
        mat[0][2] = U.z;
        mat[0][3] = 0.0f;
        
        mat[1][0] = V.x;
        mat[1][1] = V.y;
        mat[1][2] = V.z;
        mat[1][3] = 0.0f;
        
        mat[2][0] = N.x;
        mat[2][1] = N.y;
        mat[2][2] = N.z;
        mat[2][3] = 0.0f;
        
        mat[3][0] = 0.0f;
        mat[3][1] = 0.0f;
        mat[3][2] = 0.0f;
        mat[3][3] = 1.0f;
    }


    void CalcMVP(ZMat4f& mvp, const Math::ZTransform& transform,
                              const Math::ZCamera& camera,
                              const Math::ZProjection& projection)
    {
        
        ZMat4f trans, rot, scale, proj, cameraT, cameraR;
        
        SetTranslation(trans, transform.pos);
        SetRotation(rot, transform.rot);
        SetScale(scale, transform.scale);
        
        SetTranslation(cameraT, {-camera.pos.x, -camera.pos.y, -camera.pos.z});
        CalcProjection(proj, projection);
        CalcCameraTransform(cameraR, camera.target, camera.up);
        
        mvp = proj * cameraT * cameraR * trans * rot * scale;
    }
}}
