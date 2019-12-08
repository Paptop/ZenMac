#include "IO/ZFileLoader.h"

#include <fstream>

#include "Utils/ZDebug.h"

std::string Zen::ZFileLoader::LoadTextFile(const char* path)
{
    std::fstream input;
    input.open(path);
    
    std::string line;
    std::string output;

    ASSERT(input.is_open(), "File not found");
    while (getline(input, line, '\0'))
    {
        output += line;
    }

    return output;
}

