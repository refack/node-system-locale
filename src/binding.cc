#include <node.h>

#include "getSystemLocaleName.h"

using namespace v8;

void init(Handle<Object> exports, Handle<Object> module) {
#if V8_IS_PRE_3_20
  module->Set(String::NewSymbol("exports"),
      FunctionTemplate::New(GetSystemLocaleName)->GetFunction());
#else
  NODE_SET_METHOD(module, "exports", GetSystemLocaleName);
#endif
}

NODE_MODULE(get_system_locale_name, init);
