#ifndef ZTestMath_h
#define ZTestMath_h

#include "gtest/gtest.h"

#include "ZMath.h"

TEST(Matrix, Matrix_Mult_0)
{
    Zen::Math::ZMat4f matrixA;
    
    matrixA[0][0] = 5; matrixA[0][1] = 7;  matrixA[0][2] = 9; matrixA[0][3] = 10;
    matrixA[1][0] = 2; matrixA[1][1] = 3;  matrixA[1][2] = 3; matrixA[1][3] = 8;
    matrixA[2][0] = 8; matrixA[2][1] = 10; matrixA[2][2] = 2; matrixA[2][3] = 3;
    matrixA[3][0] = 3; matrixA[3][1] = 3;  matrixA[3][2] = 4; matrixA[3][3] = 8;
    
    Zen::Math::ZMat4f matrixB;
    
    matrixB[0][0] = 3;  matrixB[0][1] = 10; matrixB[0][2] = 12; matrixB[0][3] = 18;
    matrixB[1][0] = 12; matrixB[1][1] = 1;  matrixB[1][2] = 4;  matrixB[1][3] = 9;
    matrixB[2][0] = 9;  matrixB[2][1] = 10; matrixB[2][2] = 12; matrixB[2][3] = 2;
    matrixB[3][0] = 3;  matrixB[3][1] = 12; matrixB[3][2] = 4;  matrixB[3][3] = 10;
    
    Zen::Math::ZMat4f matrixC;
    
    matrixC[0][0] = 210;  matrixC[0][1] = 267;  matrixC[0][2] = 236;   matrixC[0][3] = 271;
    matrixC[1][0] = 93;   matrixC[1][1] = 149;  matrixC[1][2] = 104;   matrixC[1][3] = 149;
    matrixC[2][0] = 171;  matrixC[2][1] = 146;  matrixC[2][2] = 172;   matrixC[2][3] = 268;
    matrixC[3][0] = 105;  matrixC[3][1] = 169;  matrixC[3][2] = 128;   matrixC[3][3] = 169;
    
    Zen::Math::ZMat4f res = matrixA * matrixB;
    EXPECT_TRUE(matrixC == res);
}

TEST(Matrix, Matrix_Mult_1)
{
    Zen::Math::ZMat4f matrixA;
    
    matrixA[0][0] = 5; matrixA[0][1] = 7;  matrixA[0][2] = 9; matrixA[0][3] = 10;
    matrixA[1][0] = 2; matrixA[1][1] = 3;  matrixA[1][2] = 3; matrixA[1][3] = 8;
    matrixA[2][0] = 8; matrixA[2][1] = 10; matrixA[2][2] = 2; matrixA[2][3] = 3;
    matrixA[3][0] = 3; matrixA[3][1] = 3;  matrixA[3][2] = 4; matrixA[3][3] = 8;
    
    Zen::Math::ZMat4f matrixB;
    
    matrixB[0][0] = 3;  matrixB[0][1] = 10; matrixB[0][2] = 12; matrixB[0][3] = 18;
    matrixB[1][0] = 12; matrixB[1][1] = 1;  matrixB[1][2] = 4;  matrixB[1][3] = 9;
    matrixB[2][0] = 9;  matrixB[2][1] = 10; matrixB[2][2] = 12; matrixB[2][3] = 2;
    matrixB[3][0] = 3;  matrixB[3][1] = 12; matrixB[3][2] = 4;  matrixB[3][3] = 10;
    
    Zen::Math::ZMat4f matrixC;
    
    matrixC[0][0] = 210;  matrixC[0][1] = 267;  matrixC[0][2] = 236;   matrixC[0][3] = 271;
    matrixC[1][0] = 93;   matrixC[1][1] = 149;  matrixC[1][2] = 104;   matrixC[1][3] = 149;
    matrixC[2][0] = 171;  matrixC[2][1] = 146;  matrixC[2][2] = 172;   matrixC[2][3] = 268;
    matrixC[3][0] = 105;  matrixC[3][1] = 169;  matrixC[3][2] = 128;   matrixC[3][3] = 169;
    
    
    matrixA *= matrixB;
    EXPECT_TRUE(matrixA == matrixC);
}

#endif
