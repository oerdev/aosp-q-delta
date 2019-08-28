#include "android/hardware/foobar/1.0/Foobar.vts.h"
#include "vts_measurement.h"
#include <android-base/logging.h>
#include <android/hidl/allocator/1.0/IAllocator.h>
#include <fmq/MessageQueue.h>
#include <sys/stat.h>
#include <unistd.h>


using namespace android::hardware::foobar::V1_0;
namespace android {
namespace vts {
bool FuzzerExtended_android_hardware_foobar_V1_0_IFoobar::GetService(bool get_stub, const char* service_name) {
    static bool initialized = false;
    if (!initialized) {
        LOG(INFO) << "HIDL getService";
        if (service_name) {
          LOG(INFO) << "  - service name: " << service_name;
        }
        hw_binder_proxy_ = ::android::hardware::foobar::V1_0::IFoobar::getService(service_name, get_stub);
        if (hw_binder_proxy_ == nullptr) {
            LOG(ERROR) << "getService() returned a null pointer.";
            return false;
        }
        LOG(DEBUG) << "hw_binder_proxy_ = " << hw_binder_proxy_.get();
        initialized = true;
    }
    return true;
}


::android::hardware::Return<uint32_t> Vts_android_hardware_foobar_V1_0_IFoobar::getVersion(
    ) {
    LOG(INFO) << "getVersion called";
    AndroidSystemCallbackRequestMessage callback_message;
    callback_message.set_id(GetCallbackID("getVersion"));
    callback_message.set_name("Vts_android_hardware_foobar_V1_0_IFoobar::getVersion");
    RpcCallToAgent(callback_message, callback_socket_name_);
    return static_cast<uint32_t>(0);
}

sp<::android::hardware::foobar::V1_0::IFoobar> VtsFuzzerCreateVts_android_hardware_foobar_V1_0_IFoobar(const string& callback_socket_name) {
    static sp<::android::hardware::foobar::V1_0::IFoobar> result;
    result = new Vts_android_hardware_foobar_V1_0_IFoobar(callback_socket_name);
    return result;
}

bool FuzzerExtended_android_hardware_foobar_V1_0_IFoobar::Fuzz(
    FunctionSpecificationMessage* /*func_msg*/,
    void** /*result*/, const string& /*callback_socket_name*/) {
    return true;
}
bool FuzzerExtended_android_hardware_foobar_V1_0_IFoobar::GetAttribute(
    FunctionSpecificationMessage* /*func_msg*/,
    void** /*result*/) {
    LOG(ERROR) << "attribute not found.";
    return false;
}
bool FuzzerExtended_android_hardware_foobar_V1_0_IFoobar::CallFunction(
    const FunctionSpecificationMessage& func_msg,
    const string& callback_socket_name __attribute__((__unused__)),
    FunctionSpecificationMessage* result_msg) {
    const char* func_name = func_msg.name().c_str();
    if (hw_binder_proxy_ == nullptr) {
        LOG(ERROR) << "hw_binder_proxy_ is null. ";
        return false;
    }
    if (!strcmp(func_name, "getVersion")) {
        LOG(DEBUG) << "local_device = " << hw_binder_proxy_.get();
        uint32_t result0 = hw_binder_proxy_->getVersion();
        result_msg->set_name("getVersion");
        VariableSpecificationMessage* result_val_0 = result_msg->add_return_type_hidl();
        result_val_0->set_type(TYPE_SCALAR);
        result_val_0->set_scalar_type("uint32_t");
        result_val_0->mutable_scalar_value()->set_uint32_t(result0);
        return true;
    }
    if (!strcmp(func_name, "notifySyspropsChanged")) {
        LOG(INFO) << "Call notifySyspropsChanged";
        hw_binder_proxy_->notifySyspropsChanged();
        result_msg->set_name("notifySyspropsChanged");
        return true;
    }
    return false;
}

bool FuzzerExtended_android_hardware_foobar_V1_0_IFoobar::VerifyResults(const FunctionSpecificationMessage& expected_result __attribute__((__unused__)),
    const FunctionSpecificationMessage& actual_result __attribute__((__unused__))) {
    if (!strcmp(actual_result.name().c_str(), "getVersion")) {
        if (actual_result.return_type_hidl_size() != expected_result.return_type_hidl_size() ) { return false; }
        if (actual_result.return_type_hidl(0).scalar_value().uint32_t() != expected_result.return_type_hidl(0).scalar_value().uint32_t()) { return false; }
        return true;
    }
    return false;
}

extern "C" {
android::vts::DriverBase* vts_func_4_android_hardware_foobar_V1_0_IFoobar_() {
    return (android::vts::DriverBase*) new android::vts::FuzzerExtended_android_hardware_foobar_V1_0_IFoobar();
}

android::vts::DriverBase* vts_func_4_android_hardware_foobar_V1_0_IFoobar_with_arg(uint64_t hw_binder_proxy) {
    ::android::hardware::foobar::V1_0::IFoobar* arg = nullptr;
    if (hw_binder_proxy) {
        arg = reinterpret_cast<::android::hardware::foobar::V1_0::IFoobar*>(hw_binder_proxy);
    } else {
        LOG(INFO) << " Creating DriverBase with null proxy.";
    }
    android::vts::DriverBase* result =
        new android::vts::FuzzerExtended_android_hardware_foobar_V1_0_IFoobar(
            arg);
    if (arg != nullptr) {
        arg->decStrong(arg);
    }
    return result;
}

}
}  // namespace vts
}  // namespace android
