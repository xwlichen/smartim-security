/**
 * @date : 2019/2/25 上午9:51
 * @author: lichen
 * @email : 1960003945@qq.com
 * @description : 加密头文件
 */
//
#ifndef SMARTIM_SECURITY_ENCRYPTION_UTILS_H
#define SMARTIM_SECURITY_ENCRYPTION_UTILS_H


#include <stdio.h>

using namespace std;
static char *MD5_KEY="lichen";


//md5加盐加密 返回32为的char字符串
char * md5(const char *content);


#endif //SMARTIM_SECURITY_ENCRYPTION_UTILS_H
