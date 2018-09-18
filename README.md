#### libyuv for Android

编译了[libyuv](https://chromium.googlesource.com/libyuv/libyuv)

```
       @Override
            public void run() {
                while (!isInterrupted()) {
                    if (mBuffers.isEmpty()) {
                        SystemClock.sleep(1);
                        continue;
                    }

                    PixelBuffer buffer = mBuffers.remove(0);

    //                long millis = System.currentTimeMillis();
                    byte[] data = buffer.getData();

                    byte[] nv21 = new byte[buffer.getWidth() * buffer.getHeight() * 3 / 2];
                    if (mMediaEncoder != null) {
                        YuvUtil.BGRAToNV21(buffer.getData(),nv21,buffer.getWidth(),buffer.getHeight());
                        mMediaEncoder.encode(nv21);
                        mMediaEncoder.frameAvailableSoon();
                    }
    //                YuvUtil.RGBAToNV21(data,temp, nv21, buffer.getWidth(), buffer.getHeight());
    //                Log.i(TAG, "nv21.length : " + nv21.length + "\t\t time :" + String.valueOf(System.currentTimeMillis() - millis));
    //                YuvImage yuvImage = new YuvImage(nv21, ImageFormat.NV21, buffer.getWidth(), buffer.getHeight(), null);
    //                ByteArrayOutputStream stream = new ByteArrayOutputStream();
    //                yuvImage.compressToJpeg(new Rect(0, 0, buffer.getWidth(), buffer.getHeight()), 80, stream);
    //
    //                Bitmap bmp = BitmapFactory.decodeByteArray(stream.toByteArray(), 0, stream.size());
    //                try {
    //                    stream.close();
    //                } catch (IOException e) {
    //                    e.printStackTrace();
    //                }
    ////                int width = buffer.getWidth();
    ////                int height = buffer.getHeight();
    ////                int pixelStride = buffer.getPixelStride();
    ////                int rowStride = buffer.getRowStride();
    ////
    ////                int size = width * height;
    ////                if (mPixelData == null || size != mPixelData.length) {
    ////                    mPixelData = new int[width * height];
    ////                }
    ////
    ////                int offset = 0;
    ////                int index = 0;
    ////                for (int i = 0; i < height; ++i) {
    ////                    for (int j = 0; j < width; ++j) {
    ////                        int pixel = 0;
    ////                        pixel |= (data[offset] & 0xff) << 16;     // R
    ////                        pixel |= (data[offset + 1] & 0xff) << 8;  // G
    ////                        pixel |= (data[offset + 2] & 0xff);       // B
    ////                        pixel |= (data[offset + 3] & 0xff) << 24; // A
    ////                        mPixelData[index++] = pixel;
    ////                        offset += 4;
    ////                    }
    ////                    offset += rowStride - width * pixelStride;
    ////                }
    ////
    ////                Bitmap bitmap = Bitmap.createBitmap(mPixelData,
    ////                        width, height,
    ////                        Bitmap.Config.ARGB_8888);
    //                sendMessage(obtainMessage(PREVIEW_BITMAP, bmp));


                    mReusableBuffers.add(data);
                }
                mBuffers.clear();
            }

```


```

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
```



