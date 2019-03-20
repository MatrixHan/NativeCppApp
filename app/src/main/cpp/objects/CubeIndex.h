//
// Created by nicky on 2019/3/18.
//

#ifndef NATIVECPPAPP_CUBEINDEX_H
#define NATIVECPPAPP_CUBEINDEX_H


#include "../program/CubeShaderProgram.h"

class CubeIndex {
public:
    static const int POSITION_COMPONENT_COUNT = 3;
    static const int COLOR_COMPONENT_COUNT = 3;
    static const int STRIDE = 3+3;
public:
    CubeIndex();
    ~CubeIndex();

    void draw();
    void bindData(CubeShaderProgram * shaderProgram);

public:
    float * modelMatrix;

private:
    int8_t * CUBE_VERTEX_DATA;
    int8_t * CUBE_INDEX;


};


#endif //NATIVECPPAPP_CUBEINDEX_H
