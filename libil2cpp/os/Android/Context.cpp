#include "il2cpp-config.h"

#if ENABLE_HMI_MODE && IL2CPP_TARGET_ANDROID

#include <string>
#include <android/log.h>
#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

jobject         sContext;
jobject         sJavaAssetManager;
AAssetManager*  sAssetManager;

void AndroidSetContext(JNIEnv* env, jobject context)
{
    sContext = env->NewGlobalRef(context);

    jclass contextClass = env->FindClass("android/content/Context");
    jmethodID getAssets = env->GetMethodID(contextClass, "getAssets", "()Landroid/content/res/AssetManager;");
    jobject assetManagerLocal = env->CallObjectMethod(context, getAssets);
    sJavaAssetManager = env->NewGlobalRef(assetManagerLocal); 
    sAssetManager = AAssetManager_fromJava(env, sJavaAssetManager);
}

AAssetManager* AndroidGetAssetManager()
{
    return sAssetManager;
}

#endif