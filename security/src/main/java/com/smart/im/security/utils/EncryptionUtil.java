package com.smart.im.security.utils;

/**
 * @date : 2019/2/22 下午3:59
 * @author: lichen
 * @email : 1960003945@qq.com
 * @description :加密工具
 */
public class EncryptionUtil {

    static{
        System.loadLibrary("smartim-security");
    }

    public static  native String md5(String content);
}
