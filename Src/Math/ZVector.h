#ifndef ZVector_h
#define ZVector_h

#include <cmath>

namespace Zen
{
    struct ZVector3f
    {
        float x, y, z;
        
        ZVector3f()
        : x(0)
        , y(0)
        , z(0)
        {
        }
        
        ZVector3f(float xx, float yy, float zz)
        : x(xx)
        , y(yy)
        , z(zz)
        {
        }
        
        ZVector3f Cross(const ZVector3f& v) const
        {
            const float xx = y * v.z - z * v.y;
            const float yy = z * v.x - x * v.z;
            const float zz = x * v.y - y * v.x;
            
            return ZVector3f(xx, yy, zz);
        }
        
        ZVector3f& Normalize()
        {
            const float fLength = sqrt(x * x + y * y + z * z);
            
            x /= fLength;
            y /= fLength;
            z /= fLength;
            
            return *this;
        }
    };
}

#endif /* ZVector_h */
