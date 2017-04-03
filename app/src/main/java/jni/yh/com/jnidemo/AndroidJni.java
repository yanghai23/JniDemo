package jni.yh.com.jnidemo;

/**
 * User: YangHai (1454025171@qq.com)
 * Date: 2017-04-02
 * Time: 09:37
 */

public class AndroidJni {
    //这里的名字必须和Android.mk中的LOCAL_MODULE    := androidJni配置名字相同。
    static {
        System.loadLibrary("androidJni");
    }

    public native String getHelloWordText();

    public native String setUserName(String name);
}