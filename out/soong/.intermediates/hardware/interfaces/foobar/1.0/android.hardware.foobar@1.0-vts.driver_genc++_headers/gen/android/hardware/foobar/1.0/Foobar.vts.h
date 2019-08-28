#ifndef __VTS_DRIVER__android_hardware_foobar_V1_0_IFoobar__
#define __VTS_DRIVER__android_hardware_foobar_V1_0_IFoobar__

#undef LOG_TAG
#define LOG_TAG "FuzzerExtended_android_hardware_foobar_V1_0_IFoobar"

#include <log/log.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <driver_base/DriverBase.h>
#include <driver_base/DriverCallbackBase.h>

#include <VtsDriverCommUtil.h>

#include <android/hardware/foobar/1.0/IFoobar.h>
#include <hidl/HidlSupport.h>
#include <android/hidl/base/1.0/types.h>


using namespace android::hardware::foobar::V1_0;
namespace android {
namespace vts {

class Vts_android_hardware_foobar_V1_0_IFoobar : public ::android::hardware::foobar::V1_0::IFoobar, public DriverCallbackBase {
 public:
    Vts_android_hardware_foobar_V1_0_IFoobar(const string& callback_socket_name)
        : callback_socket_name_(callback_socket_name) {};

    virtual ~Vts_android_hardware_foobar_V1_0_IFoobar() = default;

    ::android::hardware::Return<uint32_t> getVersion(
        ) override;


 private:
    string callback_socket_name_;
};

sp<::android::hardware::foobar::V1_0::IFoobar> VtsFuzzerCreateVts_android_hardware_foobar_V1_0_IFoobar(const string& callback_socket_name);

class FuzzerExtended_android_hardware_foobar_V1_0_IFoobar : public DriverBase {
 public:
    FuzzerExtended_android_hardware_foobar_V1_0_IFoobar() : DriverBase(HAL_HIDL), hw_binder_proxy_() {}

    explicit FuzzerExtended_android_hardware_foobar_V1_0_IFoobar(::android::hardware::foobar::V1_0::IFoobar* hw_binder_proxy) : DriverBase(HAL_HIDL), hw_binder_proxy_(hw_binder_proxy) {}
    uint64_t GetHidlInterfaceProxy() const {
        return reinterpret_cast<uintptr_t>(hw_binder_proxy_.get());
    }
 protected:
    bool Fuzz(FunctionSpecificationMessage* func_msg, void** result, const string& callback_socket_name);
    bool CallFunction(const FunctionSpecificationMessage& func_msg, const string& callback_socket_name, FunctionSpecificationMessage* result_msg);
    bool VerifyResults(const FunctionSpecificationMessage& expected_result, const FunctionSpecificationMessage& actual_result);
    bool GetAttribute(FunctionSpecificationMessage* func_msg, void** result);
    bool GetService(bool get_stub, const char* service_name);

 private:
    sp<::android::hardware::foobar::V1_0::IFoobar> hw_binder_proxy_;
};


extern "C" {
extern android::vts::DriverBase* vts_func_4_android_hardware_foobar_V1_0_IFoobar_();
extern android::vts::DriverBase* vts_func_4_android_hardware_foobar_V1_0_IFoobar_with_arg(uint64_t hw_binder_proxy);
}
}  // namespace vts
}  // namespace android
#endif
