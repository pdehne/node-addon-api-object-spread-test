#ifndef SAMPLEOBJECT_H
#define SAMPLEOBJECT_H

#include <napi.h>

class SampleObject : public Napi::ObjectWrap<SampleObject>
{
public:
    SampleObject(const Napi::CallbackInfo &info);

    Napi::Value GetStringProp(const Napi::CallbackInfo &info);
    void SetStringProp(const Napi::CallbackInfo &info, const Napi::Value &value);

    Napi::Value GetNumberProp(const Napi::CallbackInfo &info);
    void SetNumberProp(const Napi::CallbackInfo &info, const Napi::Value &value);

    static void Init(Napi::Env env, Napi::Object exports);

private:
    class SampleObjectNative;
    friend class SampleObjectNative;
    std::unique_ptr<SampleObjectNative> m_native;
};

#endif
