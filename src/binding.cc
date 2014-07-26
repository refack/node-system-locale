#include <node.h>

#include "getSystemLocaleName.h"

using namespace v8;

#if (NODE_MODULE_VERSION <= 11)
Handle<Value> GetSystemLocaleName(const Arguments &args) {
  HandleScope scope;
#else
void GetSystemLocaleName(const FunctionCallbackInfo<Value> &args) {
  HandleScope scope(Isolate::GetCurrent());
#endif

  const char *systemLocaleName = getSystemLocaleName();

  if ((const char *)NULL == systemLocaleName) {
#if (NODE_MODULE_VERSION <= 11)
    return scope.Close(Undefined());
#else
    args.GetReturnValue().SetUndefined();
#endif
  } else {
#if (NODE_MODULE_VERSION <= 11)
    return scope.Close(Local<Value>::New(String::New(systemLocaleName)));
#else
    args.GetReturnValue().Set(String::NewFromUtf8(Isolate::GetCurrent(), systemLocaleName));
#endif
  }
}

void init(Handle<Object> exports, Handle<Object> module) {
#if (NODE_MODULE_VERSION <= 11)
  module->Set(String::NewSymbol("exports"),
      FunctionTemplate::New(GetSystemLocaleName)->GetFunction());
#else
  NODE_SET_METHOD(module, "exports", GetSystemLocaleName);
#endif
}

NODE_MODULE(get_system_locale_name, init);
