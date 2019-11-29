//
// Created by nicky on 2019/11/27.
//
#include <jni.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include "../egl/GLThread.h"
#include "components/NV21BufferPool.hpp"
#include "render/GpuFilterRender.h"

GLThread* glThread = NULL;
GpuFilterRender* render = NULL;


extern "C"
JNIEXPORT void JNICALL
Java_org_zzrblog_gpufilter_GpuFilterRender_onSurfaceCreate(JNIEnv *env, jobject instance, jobject surface)
{
    ANativeWindow* nativeWindow = ANativeWindow_fromSurface(env, surface);
    if(render==NULL) {
        render = new GpuFilterRender();
    }
    if(glThread==NULL) {
        glThread = new GLThread();
    }
    glThread->setGLRender(render);
    glThread->onSurfaceCreate(nativeWindow);
}

extern "C"
JNIEXPORT void JNICALL
Java_org_zzrblog_gpufilter_GpuFilterRender_onSurfaceChange(JNIEnv *env, jobject instance, jobject surface,
                                                           jint width, jint height)
{
    glThread->onSurfaceChange(width, height);
}

extern "C"
JNIEXPORT void JNICALL
Java_org_zzrblog_gpufilter_GpuFilterRender_onSurfaceDestroy(JNIEnv *env, jobject instance, jobject surface)
{
    glThread->onSurfaceDestroy();
    glThread->release();
    delete glThread;
    glThread = NULL;

    if( render==NULL) {
        delete render;
        render = NULL;
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_org_zzrblog_gpufilter_GpuFilterRender_setRotationCamera(JNIEnv *env, jobject instance,
                                                            jint rotation, jboolean flipHorizontal, jboolean flipVertical)
{
    render->setRotationCamera(rotation, flipHorizontal, flipVertical);
}

NV21BufferPool nv21_pool; // test
extern "C"
JNIEXPORT void JNICALL
Java_org_zzrblog_gpufilter_GpuFilterRender_feedVideoData(JNIEnv *env, jobject instance,
                                                         jbyteArray array,jint width, jint height)
{
    jbyte* nv21_buffer = env->GetByteArrayElements(array, NULL);
    jsize array_len = env->GetArrayLength(array);

    int size = width * height;
    int y_len = size;   // mWidth*mHeight
    int u_len = size / 4;   // mWidth*mHeight / 4
    int v_len = size / 4;   // mWidth*mHeight / 4
    // nv21数据中 y占1个width*mHeight，uv各占1/4个width*mHeight 共 3/2个width*mHeight
    if(array_len < y_len+u_len+v_len)
        return;
    ByteBuffer* p = new ByteBuffer(static_cast<size_t>(array_len));
    p->param1 = y_len;
    p->param2 = u_len;
    p->param3 = v_len;
    p->wrap(nv21_buffer, static_cast<size_t>(array_len));
    nv21_pool.put(p);

    env->ReleaseByteArrayElements(array, nv21_buffer, 0);
}