#include "Math/ZMath.h"

float Zen::fLerp(float A, float B, float fProgress)
{
    return (1.0f - fProgress) * A + fProgress * B;
}
