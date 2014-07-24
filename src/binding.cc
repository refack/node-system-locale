#include <node.h>

#include "getSystemLocaleName.h"

using namespace v8;

void init(Handle<Object> exports, Handle<Object> module) {
  NODE_SET_METHOD(module, "exports", GetSystemLocaleName);
}

NODE_MODULE(get_system_locale_name, init);
