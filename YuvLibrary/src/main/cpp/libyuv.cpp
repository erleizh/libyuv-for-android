#include "jni.h"
#include "include/libyuv.h"
#include <android/log.h>
#include <string.h>

#define TAG "jni-log" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif
void Java_com_lll_yuvlibrary_YuvUtil_BGRAToNV21(JNIEnv *env, jclass clazz, jbyteArray bgraArray,
                                                jbyteArray yuvArray, jint w, jint h) {
    jbyte *bgr = env->GetByteArrayElements(bgraArray, NULL);
    jbyte *yuv = env->GetByteArrayElements(yuvArray, NULL);

    libyuv::ARGBToNV21((uint8 *) bgr, w << 2, (uint8 *) yuv, w, (uint8 *) &yuv[w * h], w, w, h);

    env->ReleaseByteArrayElements(yuvArray, yuv, 0);
    env->ReleaseByteArrayElements(bgraArray, bgr, 0);
}


void Java_com_lll_yuvlibrary_YuvUtil_RGBAToBGRA(JNIEnv *env, jclass clazz, jbyteArray rgba,
                                                jbyteArray bgra, jint w, jint h) {
    jbyte *rgb = env->GetByteArrayElements(rgba, NULL);
    jbyte *bgr = env->GetByteArrayElements(bgra, NULL);

    libyuv::ABGRToARGB((uint8 *) rgb, w << 2, (uint8 *) bgr, w << 2, w, h);

    env->ReleaseByteArrayElements(bgra, bgr, 0);
    env->ReleaseByteArrayElements(rgba, rgb, 0);
}

#ifdef __cplusplus
}
#endif
