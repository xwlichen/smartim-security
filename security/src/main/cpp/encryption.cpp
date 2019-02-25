/**
 * @date : 2019/2/25 上午10:09
 * @author: lichen
 * @email : 1960003945@qq.com
 * @description : 
 */
/**
 * @date : 2019/2/25 上午9:51
 * @author: lichen
 * @email : 1960003945@qq.com
 * @description : 加密实现
 */

#include <string>
#include "encryption.h"
#include "md5.h"



char *md5(const char *content) {
    char *result;
    string s(content);
    //在字符串开头添加干扰值
    s.insert(0, MD5_KEY);
    //去除后面两位
    s.substr(0, s.length() - 5);

    //md5 去加密 C++ 和 Java 是一样的，唯一不同就是需要自己回收内存
    MD5_CTX *ctx = new MD5_CTX();
    MD5Init(ctx);
    MD5Update(ctx, (unsigned char *) s.c_str(), s.length());
    unsigned char digest[16] = {0};
    MD5Final(digest, ctx);

    //生成32为的字符串
    char md5_str[32];
    for (int i = 0; i < 16; ++i) {
        // 不足的情况下补0 f = 0f, ab = ab  表示按照右对齐输出两位16进制，不足两位的左边以为补0
        sprintf(md5_str, "%s%02x", md5_str, digest[i]);
    }

    result= (char *)(malloc(strlen(md5_str) + 1));
    strcpy(result,md5_str);
    return result;
}
