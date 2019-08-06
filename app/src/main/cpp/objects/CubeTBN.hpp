//
// Created by nicky on 2019/7/11.
//
#pragma once
#ifndef NATIVECPPAPP_CUBETBN_HPP
#define NATIVECPPAPP_CUBETBN_HPP


#include <GLES3/gl3.h>
#include "../common/CELLMath.hpp"
#include "../program/CubeTbnProgram.hpp"
#include "../common/Camera3D.hpp"

class CubeTBN {
public:
    struct V3N3UV2 {
        float x, y, z; //位置坐标
        float nx, ny, nz; //法向量
        float u,v; //纹理坐标
    };

    struct V3N3UV2TB6
    {
        float x, y, z;
        float nx, ny, nz;
        float u, v;
        float tx,ty,tz;
        float bx,by,bz;
    };

public:
    V3N3UV2TB6       _data[36];
    GLuint           _texMaterial;
    GLuint           _texNormal;
    CubeTbnProgram   _program;
    CELL::matrix4    _modelMatrix;

    void        init(const CELL::float3 &halfSize)
    {
        V3N3UV2 verts[] =
        {
                // 前
                {-halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 0.0f,0.0f},
                {-halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 1.0f,0.0f},
                {+halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 0.0f,1.0f},
                {-halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 1.0f,0.0f},
                {+halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 1.0f,1.0f},
                {+halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  0.0f,  +1.0f, 0.0f,1.0f},
                // 后
                {+halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 1.0f,0.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 1.0f,1.0f},
                {+halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 0.0f,0.0f},
                {-halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 1.0f,0.0f},
                {+halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 0.0f,0.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  0.0f,  -1.0f, 1.0f,1.0f},
                // 左
                {-halfSize.x, +halfSize.y, +halfSize.z, -1.0f, 0.0f,  0.0f,  0.0f,0.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, -1.0f, 0.0f,  0.0f,  1.0f,1.0f},
                {-halfSize.x, -halfSize.y, +halfSize.z, -1.0f, 0.0f,  0.0f,  1.0f,0.0f},
                {-halfSize.x, +halfSize.y, -halfSize.z, -1.0f, 0.0f,  0.0f,  0.0f,1.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, -1.0f, 0.0f,  0.0f,  1.0f,1.0f},
                {-halfSize.x, +halfSize.y, +halfSize.z, -1.0f, 0.0f,  0.0f,  0.0f,0.0f},
                // 右
                {+halfSize.x, +halfSize.y, -halfSize.z, +1.0f, 0.0f,  0.0f,  0.0f,0.0f},
                {+halfSize.x, +halfSize.y, +halfSize.z, +1.0f, 0.0f,  0.0f,  0.0f,1.0f},
                {+halfSize.x, -halfSize.y, +halfSize.z, +1.0f, 0.0f,  0.0f,  1.0f,1.0f},
                {+halfSize.x, -halfSize.y, -halfSize.z, +1.0f, 0.0f,  0.0f,  1.0f,0.0f},
                {+halfSize.x, +halfSize.y, -halfSize.z, +1.0f, 0.0f,  0.0f,  0.0f,0.0f},
                {+halfSize.x, -halfSize.y, +halfSize.z, +1.0f, 0.0f,  0.0f,  1.0f,1.0f},
                // 上
                {-halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  +1.0f, 0.0f,  0.0f,1.0f},
                {+halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  +1.0f, 0.0f,  1.0f,1.0f},
                {+halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  +1.0f, 0.0f,  1.0f,0.0f},
                {-halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  +1.0f, 0.0f,  0.0f,0.0f},
                {-halfSize.x, +halfSize.y, +halfSize.z, 0.0f,  +1.0f, 0.0f,  0.0f,1.0f},
                {+halfSize.x, +halfSize.y, -halfSize.z, 0.0f,  +1.0f, 0.0f,  1.0f,0.0f},
                // 下
                {+halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  -1.0f, 0.0f,  1.0f,1.0f},
                {+halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  -1.0f, 0.0f,  1.0f,0.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  -1.0f, 0.0f,  0.0f,1.0f},
                {+halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  -1.0f, 0.0f,  1.0f,0.0f},
                {-halfSize.x, -halfSize.y, +halfSize.z, 0.0f,  -1.0f, 0.0f,  0.0f,0.0f},
                {-halfSize.x, -halfSize.y, -halfSize.z, 0.0f,  -1.0f, 0.0f,  0.0f,1.0f}
        };
        // 根据位置/纹理 -> TBN
        convertTBN(verts, _data);
        _program.initialize();
        _modelMatrix.identify();
    }

    void setMaterialTexID(GLuint material_texID) {
        _texMaterial = material_texID;
    }
    void setMormalTexID(GLuint normal_texID) {
        _texNormal = normal_texID;
    }

    void        render(Camera3D& camera)
    {
        _program.begin();
        static  float   angle = 0;
        angle += 0.1f;
        CELL::matrix4   matRot;
        matRot.rotateYXZ(angle, 0.0f, 0.0f);
        CELL::matrix4   model   =   _modelMatrix * matRot;
        glUniformMatrix4fv(_program._matModel, 1, GL_FALSE, model.data());

        CELL::matrix4   vp = camera.getProject() * camera.getView();
        CELL::matrix4   mvp = (vp * model);
        glUniformMatrix4fv(_program._mvp, 1, GL_FALSE, mvp.data());

        CELL::matrix3   matNormal = mat4_to_mat3(model)._inverse();
        //CELL::matrix3   matNormal = mat4_to_mat3(model)._inverse()._transpose();
        glUniformMatrix3fv(_program._normalMatrix, 1, GL_FALSE, matNormal.data());

        glUniform3f(_program._lightDiffuse, 0.1f, 0.1f, 0.1f); // 漫反射 环境光
        glUniform3f(_program._lightColor, 1.0f, 1.0f, 1.0f);  // 定向光源的颜色

        glActiveTexture(GL_TEXTURE0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,  _texMaterial);
        glUniform1i(_program._texture, 0);

        glActiveTexture(GL_TEXTURE1);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,  _texNormal);
        glUniform1i(_program._texNormal, 1);

        glUniform3f(_program._lightPos, camera._eye.x, camera._eye.y, camera._eye.z);
        glUniform3f(_program._cameraPos, camera._eye.x, camera._eye.y, camera._eye.z);

        glVertexAttribPointer(_program._position, 3, GL_FLOAT, GL_FALSE, sizeof(V3N3UV2TB6), _data);
        glVertexAttribPointer(_program._normal, 3, GL_FLOAT, GL_FALSE, sizeof(V3N3UV2TB6), &_data[0].nx);
        glVertexAttribPointer(_program._uv, 2, GL_FLOAT, GL_FALSE, sizeof(V3N3UV2TB6), &_data[0].u);
        glVertexAttribPointer(_program._tagent, 3, GL_FLOAT, GL_FALSE, sizeof(V3N3UV2TB6), &_data[0].tx);
        glVertexAttribPointer(_program._biTagent, 3, GL_FLOAT, GL_FALSE, sizeof(V3N3UV2TB6), &_data[0].bx);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        _program.end();
    }

private:
    void convertTBN(V3N3UV2* vertices,V3N3UV2TB6* target_verts)
    {
        for (size_t i = 0; i <36; i += 3) // 一次操作一个三角形的三个点
        {
            // copy xyz normal uv
            target_verts[i + 0].x  = vertices[i + 0].x;
            target_verts[i + 0].y  = vertices[i + 0].y;
            target_verts[i + 0].z  = vertices[i + 0].z;
            target_verts[i + 0].nx = vertices[i + 0].nx;
            target_verts[i + 0].ny = vertices[i + 0].ny;
            target_verts[i + 0].nz = vertices[i + 0].nz;
            target_verts[i + 0].u  = vertices[i + 0].u;
            target_verts[i + 0].v  = vertices[i + 0].v;

            target_verts[i + 1].x  = vertices[i + 1].x;
            target_verts[i + 1].y  = vertices[i + 1].y;
            target_verts[i + 1].z  = vertices[i + 1].z;
            target_verts[i + 1].nx = vertices[i + 1].nx;
            target_verts[i + 1].ny = vertices[i + 1].ny;
            target_verts[i + 1].nz = vertices[i + 1].nz;
            target_verts[i + 1].u  = vertices[i + 1].u;
            target_verts[i + 1].v  = vertices[i + 1].v;

            target_verts[i + 2].x  = vertices[i + 2].x;
            target_verts[i + 2].y  = vertices[i + 2].y;
            target_verts[i + 2].z  = vertices[i + 2].z;
            target_verts[i + 2].nx = vertices[i + 2].nx;
            target_verts[i + 2].ny = vertices[i + 2].ny;
            target_verts[i + 2].nz = vertices[i + 2].nz;
            target_verts[i + 2].u  = vertices[i + 2].u;
            target_verts[i + 2].v  = vertices[i + 2].v;

            // Shortcuts for vertices
            CELL::float3  v0  = CELL::float3(vertices[i + 0].x,vertices[i + 0].y,vertices[i + 0].z);
            CELL::float3  v1  = CELL::float3(vertices[i + 1].x,vertices[i + 1].y,vertices[i + 1].z);
            CELL::float3  v2  = CELL::float3(vertices[i + 2].x,vertices[i + 2].y,vertices[i + 2].z);
            CELL::float2  uv0 = CELL::float2(vertices[i + 0].u, vertices[i + 0].v);
            CELL::float2  uv1 = CELL::float2(vertices[i + 1].u, vertices[i + 1].v);
            CELL::float2  uv2 = CELL::float2(vertices[i + 2].u, vertices[i + 2].v);
            // 构建triangle平面的方向向量 (position delta, δ)
            CELL::float3  deltaPos1 = v1 - v0;
            CELL::float3  deltaPos2 = v2 - v0;
            // 构建UV平面的两个方向的向量 (uv delta, δ)
            CELL::float2 deltaUV1   = uv1 - uv0;
            CELL::float2 deltaUV2   = uv2 - uv0;

            float   r               = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x); // uv叉积作底
            CELL::float3 tangent    = (deltaPos1 * deltaUV2.y - deltaPos2 * deltaUV1.y)*r; // 得出切线
            CELL::float3 binormal   = (deltaPos2 * deltaUV1.x - deltaPos1 * deltaUV2.x)*r; // 得出副切线

            // 赋值到t b
            target_verts[i + 0].tx = tangent.x;  target_verts[i + 0].bx = binormal.x;
            target_verts[i + 0].ty = tangent.y;  target_verts[i + 0].by = binormal.y;
            target_verts[i + 0].tz = tangent.z;  target_verts[i + 0].bz = binormal.z;

            target_verts[i + 1].tx = tangent.x;  target_verts[i + 1].bx = binormal.x;
            target_verts[i + 1].ty = tangent.y;  target_verts[i + 1].by = binormal.y;
            target_verts[i + 1].tz = tangent.z;  target_verts[i + 1].bz = binormal.z;

            target_verts[i + 2].tx = tangent.x;  target_verts[i + 2].bx = binormal.x;
            target_verts[i + 2].ty = tangent.y;  target_verts[i + 2].by = binormal.y;
            target_verts[i + 2].tz = tangent.z;  target_verts[i + 2].bz = binormal.z;
        }
    }
};


#endif //NATIVECPPAPP_CUBETBN_HPP
