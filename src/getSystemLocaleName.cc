#include <node.h>
#include <clocale>

#include "getSystemLocaleName.h"

using namespace v8;

#if (NODE_MODULE_VERSION <= 11)
Handle<Value> GetSystemLocaleName(const Arguments &args) {
  HandleScope scope;
#else
void GetSystemLocaleName(const FunctionCallbackInfo<Value> &args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
#endif

  // Save current locale name
  const char *originalLocaleName = std::setlocale(LC_ALL, NULL);

  // Get system locale name
  const char *systemLocaleName = std::setlocale(LC_ALL, "");

  // Reset original locale if possible
  if ((const char *)NULL != originalLocaleName) {
    std::setlocale(LC_ALL, originalLocaleName);
  }

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
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, systemLocaleName));
#endif
  }
}
