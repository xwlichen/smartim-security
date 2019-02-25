package com.smart.im.security.utils;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;

/**
 * @date : 2019/2/25 上午11:54
 * @author: lichen
 * @email : 1960003945@qq.com
 * @description : 校验工具类
 */
public class VerifyUtil {

    static{
        System.loadLibrary("smartim-security");
    }

    public static native int signature(Context context);


}
