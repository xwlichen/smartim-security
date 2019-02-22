#include <jni.h>
#include <string>
#include "md5.h"
using namespace std;



static char *MD5_KEY="lichen";
static char *PACKNAME="com.smart.im.security";


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

    const char *content=env->GetStringUTFChars(content_,0);
    string s(content);
    //在字符串开头添加干扰值
    s.insert(0,MD5_KEY);
    //去除后面两位
    s.substr(0,s.length()-5);

    //md5 去加密 C++ 和 Java 是一样的，唯一不同就是需要自己回收内存
    MD5_CTX *ctx = new MD5_CTX();
    MD5Init(ctx);
    MD5Update(ctx, (unsigned char *) s.c_str(), s.length());
    unsigned char digest[16] = {0};
    MD5Final(digest, ctx);

    //生成32为的字符串
    char md5_str[32];
    for (int i = 0; i <16 ; ++i) {
        // 不足的情况下补0 f = 0f, ab = ab  表示按照右对齐输出两位16进制，不足两位的左边以为补0
        sprintf(md5_str, "%s%02x", md5_str, digest[i]);
    }
    // 释放资源
    env->ReleaseStringUTFChars(content_, content);
    return env->NewStringUTF(md5_str);
    }


