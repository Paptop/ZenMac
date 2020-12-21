#ifndef ZMath_types_h
#define ZMath_types_h

namespace Zen { namespace Math {

    struct ZVec3f
    {
        float x = 0.0f, y = 0.0f, z = 0.0f;
    };

    struct ZMat4f
    {
        float m[4][4] = {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f,
        };
        
        ZMat4f& operator*=(const ZMat4f& right)
        {
            ZMat4f res;
            for(int i = 0; i < 4; ++i)
            {
                for(int j = 0; j < 4; ++j)
                {
                    res.m[i][j] = m[i][0] * right.m[0][j] +
                                  m[i][1] * right.m[1][j] +
                                  m[i][2] * right.m[2][j] +
                                  m[i][3] * right.m[3][j];
                }
            }
            
            (*this) = res;
            return (*this);
        }
        
        ZMat4f operator*(const ZMat4f& right)
        {
            ZMat4f res;
            for(int i = 0; i < 4; ++i)
            {
                for(int j = 0; j < 4; ++j)
                {
                    res.m[i][j] = m[i][0] * right.m[0][j] +
                                  m[i][1] * right.m[1][j] +
                                  m[i][2] * right.m[2][j] +
                                  m[i][3] * right.m[3][j];
                }
            }
            
            return res;
        }
        
        bool operator==(const ZMat4f& right)
        {
            bool bEqual = true;
            for(int i = 0 ; i < 4; ++i)
            {
                for(int j = 0 ; j < 4; ++j)
                {
                    bEqual &= m[i][j] == right[i][j];
                }
            }
            
            return bEqual;
        }
        
        const float* operator[](int row) const { return m[row]; }
        float* operator[](int row){ return m[row]; }
    };

    struct ZProjection
    {
        int         width = 800;
        int         height = 600;
        float       zNear = 0.0f;
        float       zFar = 1000.0f;
        float       fov = 45;
    };

    struct ZTransform
    {
        ZVec3f     scale;
        ZVec3f     pos;
        ZVec3f     rot;
    };

    struct ZCamera
    {
        ZVec3f     pos;
        ZVec3f     target;
        ZVec3f     up;
    };

}}
#endif // ZMath_types_h
