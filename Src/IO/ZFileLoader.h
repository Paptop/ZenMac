#ifndef ZFileLoader_h
#define ZFileLoader_h

#include <string>

namespace Zen
{
    class ZFileLoader
    {
    public:
        static std::string LoadTextFile(const char* path);
    };
}

#endif //ZFileLoader
