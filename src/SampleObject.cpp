#include "SampleObject.h"

class SampleObject::SampleObjectNative
{
public:
    SampleObjectNative()
    : m_number(0.0)
    {
    }

    void setString(const std::string& value) {
        m_string = value;
    }

    const std::string& getString() {
        return m_string;
    }

    void setNumber(double value) {
        m_number = value;
    }

    double getNumber() {
        return m_number;
    }

private:
    std::string m_string;
    double m_number;
};

SampleObject::SampleObject(const Napi::CallbackInfo &info)
: ObjectWrap(info)
{
    m_native.reset(new SampleObjectNative());
}

Napi::Value SampleObject::GetStringProp(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, m_native->getString());
}

void SampleObject::SetStringProp(const Napi::CallbackInfo &info, const Napi::Value &value) {
    std::string nativeValue = value.As<Napi::String>().Utf8Value();
    m_native->setString(nativeValue);
}

Napi::Value SampleObject::GetNumberProp(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, m_native->getNumber());
}

void SampleObject::SetNumberProp(const Napi::CallbackInfo &info, const Napi::Value &value) {
    m_native->setNumber(value.As<Napi::Number>().DoubleValue());
}

void SampleObject::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("SampleObject", DefineClass(env, "SampleObject", {
        SampleObject::InstanceAccessor<&SampleObject::GetStringProp, &SampleObject::SetStringProp>("stringProp"),
        SampleObject::InstanceAccessor<&SampleObject::GetNumberProp, &SampleObject::SetNumberProp>("numberProp"),
    }));
}
