#ifndef HIDL_GENERATED_ANDROID_HARDWARE_FOOBAR_V1_0_BPHWFOOBAR_H
#define HIDL_GENERATED_ANDROID_HARDWARE_FOOBAR_V1_0_BPHWFOOBAR_H

#include <hidl/HidlTransportSupport.h>

#include <android/hardware/foobar/1.0/IHwFoobar.h>

namespace android {
namespace hardware {
namespace foobar {
namespace V1_0 {

struct BpHwFoobar : public ::android::hardware::BpInterface<IFoobar>, public ::android::hardware::details::HidlInstrumentor {
    explicit BpHwFoobar(const ::android::sp<::android::hardware::IBinder> &_hidl_impl);

    typedef IFoobar Pure;

    typedef android::hardware::details::bphw_tag _hidl_tag;

    virtual bool isRemote() const override { return true; }

    // Methods from ::android::hardware::foobar::V1_0::IFoobar follow.
    static ::android::hardware::Return<uint32_t>  _hidl_getVersion(::android::hardware::IInterface* _hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor);

    // Methods from ::android::hardware::foobar::V1_0::IFoobar follow.
    ::android::hardware::Return<uint32_t> getVersion() override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;
    ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;
    ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;
    ::android::hardware::Return<void> setHALInstrumentation() override;
    ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;
    ::android::hardware::Return<void> ping() override;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;
    ::android::hardware::Return<void> notifySyspropsChanged() override;
    ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

private:
    std::mutex _hidl_mMutex;
    std::vector<::android::sp<::android::hardware::hidl_binder_death_recipient>> _hidl_mDeathRecipients;
};

}  // namespace V1_0
}  // namespace foobar
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_FOOBAR_V1_0_BPHWFOOBAR_H
