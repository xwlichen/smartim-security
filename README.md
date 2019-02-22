# smartim-security
java层加密：对于很容易破解（xposed）
ndk层加密：相当比较难
  1、ndk层md5加密（加盐）
  由于so库不能被混淆，防止被人运动
  2、加一层签名和包名的校验（也只能防止90%的不被破解）
