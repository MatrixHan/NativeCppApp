//
// Created by zzr on 2019/6/5.
//
#pragma once
#ifndef NATIVECPPAPP_CUBELIGHT_HPP
#define NATIVECPPAPP_CUBELIGHT_HPP

#include "../common/CELLMath.hpp"
#include "../program/CubeIlluminateProgram.hpp"

class CubeIlluminate {
public:
    struct V3N3T2 {
        float x, y, z; //位置坐标
        float nx, ny, nz; //法向量
        float u,v; //纹理坐标
    };
public:
    CubeIlluminateProgram   sprogram;
    GLuint                  mCubeSurfaceTexId;
    V3N3T2                  _data[36];

    void        init(const CELL::float3 &halfSize, GLuint tex)
    {
        V3N3T2 verts[] =
        {
                {+halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  -1.0f, 0.0f,  1.0f,0.0f},
                {-halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  -1.0f, 0.0f,  0.0f,0.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  -1.0f, 0.0f,  0.0f,1.0f},

                {-halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 1.0f,0.0f},
                {+halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 1.0f,1.0f},
                {+halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 0.0f,1.0f},

                {+halfSize.x, +halfSize.y, -halfSize.z, +1.0f, 0.0f,  0.0f,  0.0f,0.0f},
                {+halfSize.x, +halfSize.y, +halfSize.z, +1.0f, 0.0f,  0.0f,  0.0f,1.0f},
                {+halfSize.x, -halfSize.y, +halfSize.z, +1.0f, 0.0f,  0.0f,  1.0f,1.0f},

                {-halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  +1.0f, 0.0f,  0.0f,1.0f},
                {+halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  +1.0f, 0.0f,  1.0f,1.0f},
                {+halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  +1.0f, 0.0f,  1.0f,0.0f},

                {-halfSize.x, +halfSize.y, +halfSize.z, -1.0f, 0.0f,  0.0f,  0.0f,0.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, -1.0f, 0.0f,  0.0f,  1.0f,1.0f},
                {-halfSize.x, -halfSize.y, +halfSize.z, -1.0f, 0.0f,  0.0f,  1.0f,0.0f},

                {-halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 0.0f,0.0f},
                {-halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 1.0f,0.0f},
                {+halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 0.0f,1.0f},

                {+halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  -1.0f, 0.0f,  1.0f,1.0f},
                {+halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  -1.0f, 0.0f,  1.0f,0.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  -1.0f, 0.0f,  0.0f,1.0f},

                {+halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 1.0f,0.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 1.0f,1.0f},
                {+halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 0.0f,0.0f},

                {+halfSize.x, -halfSize.y, -halfSize.z, +1.0f, 0.0f,  0.0f,  1.0f,0.0f},
                {+halfSize.x, +halfSize.y, -halfSize.z, +1.0f, 0.0f,  0.0f,  0.0f,0.0f},
                {+halfSize.x, -halfSize.y, +halfSize.z, +1.0f, 0.0f,  0.0f,  1.0f,1.0f},

                {-halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 1.0f,0.0f},
                {+halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 0.0f,0.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 1.0f,1.0f},

                {-halfSize.x, +halfSize.y, -halfSize.z, -1.0f, 0.0f,  0.0f,  0.0f,1.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, -1.0f, 0.0f,  0.0f,  1.0f,1.0f},
                {-halfSize.x, +halfSize.y, +halfSize.z, -1.0f, 0.0f,  0.0f,  0.0f,0.0f},

                {-halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  +1.0f, 0.0f,  0.0f,0.0f},
                {-halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  +1.0f, 0.0f,  0.0f,1.0f},
                {+halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  +1.0f, 0.0f,  1.0f,0.0f},
        };
        memcpy(_data, verts, sizeof(verts));

        mCubeSurfaceTexId = tex;

        sprogram.initialize();
    }

    void        render(Camera3D& camera)
    {
        sprogram.begin();
        static  float   angle = 0;
        //angle += 0.1f;
        CELL::matrix4   matRot;
        matRot.rotateYXZ(angle, 0, 0);
        CELL::matrix4   vp = camera.getProject() * camera.getView();
        CELL::matrix4   mvp = (vp * matRot);
        glUniformMatrix4fv(sprogram._mvp, 1, GL_FALSE, mvp.data());

        glActiveTexture(GL_TEXTURE0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,  mCubeSurfaceTexId);
        glUniform1i(sprogram._texture, 0);

        glUniform3f(sprogram._lightDiffuse, 0.1f, 0.1f, 0.1f); // 漫反射 环境光
        glUniform3f(sprogram._lightColor, 1.0f, 1.0f, 1.0f); // 定向光源的颜色
        glUniform3f(sprogram._lightDir, // 定向光源的方向
                    static_cast<GLfloat>(camera._dir.x),
                    static_cast<GLfloat>(camera._dir.y),
                    static_cast<GLfloat>(camera._dir.z));

        glVertexAttribPointer(static_cast<GLuint>(sprogram._position), 3, GL_FLOAT, GL_FALSE,
                              sizeof(CubeIlluminate::V3N3T2), &_data[0].x);
        glVertexAttribPointer(static_cast<GLuint>(sprogram._normal),   3, GL_FLOAT, GL_FALSE,
                              sizeof(CubeIlluminate::V3N3T2), &_data[0].nx);
        glVertexAttribPointer(static_cast<GLuint>(sprogram._uv),       2, GL_FLOAT, GL_FALSE,
                              sizeof(CubeIlluminate::V3N3T2), &_data[0].u);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        sprogram.end();
    }

};

#endif //NATIVECPPAPP_CUBELIGHT_H
