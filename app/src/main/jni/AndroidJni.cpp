//
// Created by yanghai on 17/4/2.
//
#include <string.h>
#include <jni.h>
#include <stdio.h>
#include "jni_yh_com_jnidemo_AndroidJni.h"
#include "TestInclude.h"
#include "stdio.h"
/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/HelloJni/HelloJni.java
 */
//char *Jstring2CStr(JNIEnv *env, jstring jstr);
void customMethod(JNIEnv *, jstring);

JNIEXPORT jstring JNICALL
Java_jni_yh_com_jnidemo_AndroidJni_getHelloWordText(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF("Hello from JNI ，hello yh!");
}

JNIEXPORT jstring JNICALL
Java_jni_yh_com_jnidemo_AndroidJni_setUserName(JNIEnv *env, jobject thiz, jstring jstr) {
//    const char * str_buf = env->GetStringChars(result);
//    printf("constent is %s", str_buf);
//    int result1 = TestInclude::add(2, 3);
//    char *re = 't';
//    char *cstr = Jstring2CStr(env, jstr);
//    char *result1 = 'W';
//    strcat(cstr, result1); //拼接两个字符串
//    return env->NewStringUTF(cstr);
//    char buf[128];
//    const char *str;
//    str = env->GetStringUTFChars(jstr, NULL);
//    if (str == NULL) { //不要忘记检测，否则分配内存失败会抛出异常
//        return NULL; /* OutOfMemoryError already thrown */
//    }
//    printf("%s", str);
//
//    env->ReleaseStringUTFChars(jstr, str);
//
//    /* We assume here that the user does not type more than  * 127 characters */
//    scanf("%s", buf);

//    jstring  result = resVlaue+"this is test code";
    return env->NewStringUTF("test");
}

JNIEXPORT jint JNICALL Java_jni_yh_com_jnidemo_AndroidJni_getResult
        (JNIEnv *env, jobject, jstring) {
    TestInclude ti;
    int resVlaue = ti.add(3, 3);
    int resVlaue1 = ti.addV(3, 3, 1);
    printf("value---------------- = %d", resVlaue);
    return resVlaue + resVlaue1;
}

JNIEXPORT void JNICALL Java_jni_yh_com_jnidemo_AndroidJni_callMethod
        (JNIEnv *env, jobject thiz) {

    jstring str = env->NewStringUTF("这是c++中的一个字符串，调用通用的方法，传递给方法中");
    customMethod(env, str);
}

void customMethod(JNIEnv *env, jstring str) {
    jclass clazz = env->FindClass("jni/yh/com/jnidemo/AndroidJni");
    if (NULL == clazz) {
        printf("can't find clazz");
        return;
    }
    jmethodID callMethodStr = env->GetStaticMethodID(clazz, "callMethodStr",
                                                     "(Ljava/lang/String;)V");
    if (NULL == callMethodStr) {
        env->DeleteLocalRef(clazz);
        printf("can't find method callMethod from clazz ");
        return;
    }


    env->CallStaticVoidMethod(clazz, callMethodStr, str);
    env->DeleteLocalRef(clazz);
}