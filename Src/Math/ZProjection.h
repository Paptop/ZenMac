#ifndef ZProjection_h
#define ZProjection_h

struct ZProjection
{
    int         _width = 800;
    int         _height = 600;
    float       _zNear = 0.0f;
    float       _zFar = 1000.0f;
    float       _fov = 45;
};

#endif /* ZProjection_h */
