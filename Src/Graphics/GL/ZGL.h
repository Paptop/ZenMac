#ifndef ZGL_h
#define ZGL_h

#include <glad/glad.h>

namespace Zen { namespace GL {
    void GenBindVertexArray(uint32_t& obj, int num)
    {
        glGenVertexArrays(num, &obj);
        glBindVertexArray(obj);
    }

    template<typename T, size_t size>
    void GenBindBuffer(uint32_t type,
                       uint32_t& obj,
                       T (&array)[size],
                       uint32_t num = 1)
    {
        glGenBuffers(num, &obj);
        glBindBuffer(type, obj);
        glBufferData(type, sizeof(array), array, GL_STATIC_DRAW);
    }

    void EnableAttributes(uint32_t index,
                          uint32_t size,
                          uint32_t type,
                          uint32_t isNormalized,
                          uint32_t bytes,
                          const void* pointer)
    {
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, size, type, isNormalized, sizeof(Math::ZVec3f), 0);
    }

    void Clear(uint32_t flags,
               const Math::ZVec3f& color = {0.0f,0.0f,0.0f},
               float alpha = 0.0f)
    {
        glClearColor(color.x, color.y, color.z, alpha);
        glClear(flags);
    }
}};

#endif //ZGL.h
