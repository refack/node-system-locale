#ifndef __GET_SYSTEM_LOCALE_NAME_H__
#define __GET_SYSTEM_LOCALE_NAME_H__

#include <node.h>

#if (NODE_MODULE_VERSION <= 11)
v8::Handle<v8::Value> GetSystemLocaleName(const v8::Arguments &args);
#else
void GetSystemLocaleName(const v8::FunctionCallbackInfo<v8::Value> &args);
#endif

#endif//__GET_SYSTEM_LOCALE_NAME_H__
