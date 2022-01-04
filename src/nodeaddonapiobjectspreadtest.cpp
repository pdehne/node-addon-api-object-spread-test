#include <napi.h>
#include "SampleObject.h"

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    SampleObject::Init(env, exports);
    return exports;
}

NODE_API_MODULE(nodeaddonapiobjectspreadtest, Init)
