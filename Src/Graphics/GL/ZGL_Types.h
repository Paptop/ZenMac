#ifndef ZGL_Types_h
#define ZGL_Types_h

namespace Zen { namespace GL{

struct ZShaderGL
{
    int _id = -1;
};

struct ZRenderable
{
    Math::ZVec3f*  aVertecies;
    int*           aIndicies;
    
    //ArrayObject
    int            vao;
    //BufferObject
    int            vbo;
    //IndexObject
    int            ibo;
};

}}

#endif // ZGL_Types.h
