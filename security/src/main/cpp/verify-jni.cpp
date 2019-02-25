/**
 * @date : 2019/2/25 上午11:47
 * @author: lichen
 * @email : 1960003945@qq.com
 * @description : 验证的jni调用入口
 */

#include <jni.h>
#include <string>
#include <android/log.h>

using namespace std;

static char *PACKNAME = "com.smart.im.security.test";
static char *APP_SIGNATURE = "sdfsd ";


extern "C" {
JNIEXPORT jint JNICALL
Java_com_smart_im_security_utils_VerifyUtil_signature(JNIEnv *env,
                                                      jclass type,
                                                      jobject context);
}

JNIEXPORT jint JNICALL
Java_com_smart_im_security_utils_VerifyUtil_signature(JNIEnv *env,
                                                      jclass type,
                                                      jobject context) {
    jclass j_clz;
    jmethodID j_mid;


    //获取包名
    j_clz = env->GetObjectClass(context);
    j_mid = env->GetMethodID(j_clz, "getPackageName", "()Ljava/lang/String;");
    jstring j_package_name = (jstring) (env->CallObjectMethod(context, j_mid));

    //比较包名是否一直
    const char *c_package_name = env->GetStringUTFChars(j_package_name, 0);
    if (strcmp(c_package_name, PACKNAME) != 0) {
        return 0;
    }

    //获取签名
    j_mid = env->GetMethodID(j_clz, "getPackageManager", "()Landroid/content/pm/PackageManager;");
    jobject j_package_manager = env->CallObjectMethod(context, j_mid);
    //获取packageinfo
    j_clz = env->GetObjectClass(j_package_manager);
    j_mid = env->GetMethodID(j_clz, "getPackageInfo",
                             "(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");
    jobject j_packeage_info = env->CallObjectMethod(j_package_manager, j_mid, j_package_name,
                                                    0x00000040);
    //获取签名数组
    j_clz = env->GetObjectClass(j_packeage_info);
    jfieldID j_fid = env->GetFieldID(j_clz, "signatures", "[Landroid/content/pm/Signature;");
    jobjectArray signatures = static_cast<jobjectArray>(env->GetObjectField(j_packeage_info,
                                                                            j_fid));
    //获取signatures[0]
    jobject signature_first = env->GetObjectArrayElement(signatures, 0);
    //调用signature[0].toCharString();
    j_clz = env->GetObjectClass(signature_first);
    j_mid = env->GetMethodID(j_clz, "toCharsString", "()Ljava/lang/String;");
    jstring j_signature_str = static_cast<jstring>(env->CallObjectMethod(signature_first, j_mid));

    //转换成char *用strcmp 进行一个比较
    const char *c_signature_str = env->GetStringUTFChars(j_signature_str, 0);
    if (strcmp(c_signature_str, APP_SIGNATURE) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, "JNI_TAG", "签名校验失败");
        return 0;
    }

    __android_log_print(ANDROID_LOG_ERROR, "JNI_TAG", "签名校验成功: %s", c_signature_str);
    // 签名认证成功
    return 1;
}


