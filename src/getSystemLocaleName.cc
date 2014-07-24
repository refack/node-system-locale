#include <node.h>
#include <clocale>

#include "getSystemLocaleName.h"

using namespace v8;

void GetSystemLocaleName(const FunctionCallbackInfo<Value> &info) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  // Save current locale name
  const char *originalLocaleName = std::setlocale(LC_ALL, NULL);

  // Get system locale name
  const char *systemLocaleName = std::setlocale(LC_ALL, "");

  // Reset original locale if possible
  if ((const char *)NULL != originalLocaleName) {
    std::setlocale(LC_ALL, originalLocaleName);
  }

  if ((const char *)NULL == systemLocaleName) {
    info.GetReturnValue().SetUndefined();
  } else {
    info.GetReturnValue().Set(String::NewFromUtf8(isolate, systemLocaleName));
  }
}
