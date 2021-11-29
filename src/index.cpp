// #include "../node_modules/node-addon-api/napi.h"
#include <napi.h>
#include <string>
#include "crc32.h"

Napi::String IEEE(const Napi::CallbackInfo& info){
    Napi::Env env = info.Env();
    std::string txt = (std::string) info[0].ToString();
    std::string result = crc32IEEE( txt );
    return Napi::String::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports){
    exports.Set(
        Napi::String::New(env, "IEEE"),
        Napi::Function::New(env, IEEE)
    );
    return exports;
}
//  Регистрация crc32 модуля с вызовом метода Init
NODE_API_MODULE(crc32_base64, Init)
