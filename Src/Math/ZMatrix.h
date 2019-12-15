#ifndef ZMatrix_h
#define ZMatrix_h

#include <cmath>
#include "Math/ZVector.h"

namespace Zen
{
    struct ZMatrix4f
    {
        float m[4][4];
        
        ZMatrix4f()
        {
            MakeEmpty();
            MakeIdentity();
        }
        
        ZMatrix4f operator*(const ZMatrix4f& right)
        {
            ZMatrix4f res;
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
        
        ZMatrix4f& operator*=(const ZMatrix4f& right)
        {
            for(int i = 0; i < 4; ++i)
            {
                for(int j = 0; j < 4; ++j)
                {
                    m[i][j] = m[i][0] * right.m[0][j] +
                              m[i][1] * right.m[1][j] +
                              m[i][2] * right.m[2][j] +
                              m[i][3] * right.m[3][j];
                }
            }
            
            return (*this);
        }
        
        bool operator==(const ZMatrix4f& right)
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
        
        const float* operator[](int row) const
        {
            return m[row];
        }
        
        float* operator[](int row)
        {
            return m[row];
        }
        
        void MakeIdentity()
        {
            for(int i = 0; i < 4; ++i)
                m[i][i] = 1.0f;
        }
        
        void MakeEmpty()
        {
            for(int i = 0 ; i < 4; ++i)
                for(int j = 0; j < 4; ++j)
                    m[i][j] = 0.0f;
        }
        
        void SetScale(const ZVector3f& scale)
        {
            m[0][0] = scale.x; m[1][1] = scale.y; m[2][2] = scale.z;
        }
        
        void SetTranslation(const ZVector3f& translation)
        {
            /*
            [1] [0] [0] [X]
            [0] [1] [0] [Y]
            [0] [0] [1] [Z]
            [0] [0] [0] [1]*/
            m[0][3] = translation.x;
            m[1][3] = translation.y;
            m[2][3] = translation.z;
        }
        
        void SetRotation(const ZVector3f& rotation)
        {
            /*
                Z:
                cos(a) -sin(a) 0   0
                sin(a) cos(a)  0   0
                 0       0     1   0
                 0       0     0   1
                
                Y:
                cos(a)  0 -sin(a)  0
                0       1      0   0
                sin(a)  0  cos(a)  0
                0       0      0   1
             
                X:
                1       0           0   0
                0      cos(a)  -sin(a)  0
                0      sin(a)  cos(a)   0
                0       0          0    1
             */
            
            ZMatrix4f _rotX, _rotY, _rotZ;
            
            _rotZ[0][0] = cos(rotation.z);  _rotZ[0][1] = -sin(rotation.z);
            _rotZ[1][0] = sin(rotation.z);  _rotZ[1][1] = cos(rotation.z);
            
            _rotY[0][0] = cos(rotation.y);  _rotY[0][2] = -sin(rotation.y);
            _rotY[2][0] = sin(rotation.y);  _rotY[2][2] = cos(rotation.y);
            
            _rotX[1][1] = cos(rotation.x);  _rotX[1][2] = -sin(rotation.x);
            _rotX[2][1] = sin(rotation.x);  _rotX[2][2] = cos(rotation.x);
            
            (*this) *= _rotZ * _rotY * _rotX;
        }
        
    };// struct ZMatrix4f
}//namespace Zen

#endif //ZMATRIX_H
