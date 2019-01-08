// hello.cc
#include <node.h>
using namespace std;

namespace demo
{

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value> &args)
{
  Isolate *isolate = args.GetIsolate();
  const auto value = args[0]->IntegerValue();
  const auto result = "Hello Electron from native V8 C: " + std::to_string(value);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, result.c_str()));
}

void Initialize(Local<Object> exports)
{
  NODE_SET_METHOD(exports, "hello", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} // namespace demo