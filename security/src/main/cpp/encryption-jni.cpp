/**
 * @date : 2019/2/25 上午9:51
 * @author: lichen
 * @email : 1960003945@qq.com
 * @description : 加密的jni 入口
 */

#include <jni.h>
#include <string>
#include "encryption.h"
#include "md5.h"

using namespace std;




extern "C" {

JNIEXPORT jstring JNICALL
Java_com_smart_im_security_utils_EncryptionUtil_md5(JNIEnv *env,
                                                    jclass type,
                                                    jstring content_);

}


/**
 *md5加密
 *@params jstring 需要加密的内容
 */
JNIEXPORT jstring JNICALL
Java_com_smart_im_security_utils_EncryptionUtil_md5(JNIEnv *env,
                                                    jclass type,
                                                    jstring content_) {

    const char *content = env->GetStringUTFChars(content_, 0);
    char *restlt = md5(content);
    free(restlt);
    // 释放资源
    env->ReleaseStringUTFChars(content_, content);
    return env->NewStringUTF(restlt);


}
