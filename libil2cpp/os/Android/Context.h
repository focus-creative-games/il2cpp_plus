#pragma once

#include "il2cpp-config.h"

#if ENABLE_HMI_MODE && IL2CPP_TARGET_ANDROID

#include <jni.h>
#include <android/asset_manager.h>

void AndroidSetContext(JNIEnv* env, jobject context);
AAssetManager* AndroidGetAssetManager();

#endif