package org.zzrblog.nativecpp;

import android.content.Context;
import android.view.Surface;

/**
 * Created by zzr on 2019/3/14.
 */
public class NativeEGL {

    static {
        System.loadLibrary("native-egl");
    }

    private Context ctx;
    public NativeEGL(Context context) {
        ctx = context;
    }

    public String getPackageResourceAPK() {
        return ctx.getPackageResourcePath();
        // /data/app/org.zzrblog.nativecpp-zzIu0MPPws9Df9SN-U1BRA==/base.apk
        // 类似这种以根目录开头的，apk后缀的压缩文件，然后再NDK层用zip库解压缩。
    }

    public native void onSurfaceCreate(Surface surface);

    public native void onSurfaceChange(int width, int height);

    public native void onSurfaceDestroy();


    public native void handleMultiTouch(float distance);

    public native void handleTouchDown(float x, float y);

    public native void handleTouchDrag(float x, float y);

    public native void handleTouchUp(float x, float y);



}
