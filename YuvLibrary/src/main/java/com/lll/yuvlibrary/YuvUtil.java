package com.lll.yuvlibrary;

/**
 * Created by lll on 2017/11/15.
 * YUV Lib
 */
public class YuvUtil {

    static {
        System.loadLibrary("yuv");
    }

    /**
     * 将 ARGB 8888 格式的像素数据转换为 NV21 格式的数据
     *
     * @param rgbaArray rgbaArray.length =  width * height * 4
     * @param temp      临时存储空间 , 大小应跟 rgbaArray 保持一致
     * @param nv21Array nv21Array.length =  width * height * 3 / 2
     * @param width     width
     * @param height    height
     */
    public static void RGBAToNV21(byte[] rgbaArray, byte[] temp, byte[] nv21Array, int width, int height) {
        RGBAToBGRA(rgbaArray, temp, width, height);
        BGRAToNV21(temp, nv21Array, width, height);
    }

    private static native void RGBAToBGRA(byte[] rgba, byte[] bgra, int width, int height);

    /**
     * 将 BGRA 8888 格式的像素数据转换为 NV21 格式的数据,
     * 从glReadPixes获取的数据直接调用此方法即可
     *
     * @param bgra   bgra.length =  width * height * 4
     * @param yuv    yuv.length =  width * height * 3 / 2
     * @param width  width
     * @param height height
     */
    public static native void BGRAToNV21(byte[] bgra, byte[] yuv, int width, int height);
}
