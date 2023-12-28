#include "il2cpp-config.h"

#if ENABLE_HMI_MODE && IL2CPP_TARGET_ANDROID

#include <string>
#include <android/log.h>
#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

jobject         sContext;
AAssetManager*  sAssetManager;

void AndroidSetContext(JNIEnv* env, jobject context)
{
    sContext = env->NewGlobalRef(context);

    jclass contextClass = env->FindClass("android/content/Context");
    jmethodID getAssets = env->GetMethodID(contextClass, "getAssets", "()Landroid/content/res/AssetManager;");
    jobject assetManager = env->CallObjectMethod(context, getAssets);

    sAssetManager = AAssetManager_fromJava(env, assetManager);
}

AAssetManager* AndroidGetAssetManager()
{
    return sAssetManager;
}

#endif