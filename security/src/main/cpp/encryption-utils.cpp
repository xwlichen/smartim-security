#include <jni.h>
#include <string>

extern "C" {

JNIEXPORT jstring JNICALL
Java_com_smart_im_security_utils_EncryptionUtil_md5
  (JNIEnv *, jclass, jstring);


  }


/**
 *md5加密
 *@params jstring 需要加密的内容
 */
JNIEXPORT jstring JNICALL
Java_com_smart_im_security_utils_EncryptionUtil_md5(JNIEnv *env,
                                                    jclass type,
                                                    jstring content_){

    const char *content=env->Get

    std::string hello = "Hello from C++111122";
    return env->NewStringUTF(hello.c_str());
    }

