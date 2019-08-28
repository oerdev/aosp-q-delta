#ifndef HIDL_GENERATED_ANDROID_HARDWARE_FOOBAR_V1_0_BNHWFOOBAR_H
#define HIDL_GENERATED_ANDROID_HARDWARE_FOOBAR_V1_0_BNHWFOOBAR_H

#include <android/hardware/foobar/1.0/IHwFoobar.h>

namespace android {
namespace hardware {
namespace foobar {
namespace V1_0 {

struct BnHwFoobar : public ::android::hidl::base::V1_0::BnHwBase {
    explicit BnHwFoobar(const ::android::sp<IFoobar> &_hidl_impl);
    explicit BnHwFoobar(const ::android::sp<IFoobar> &_hidl_impl, const std::string& HidlInstrumentor_package, const std::string& HidlInstrumentor_interface);

    virtual ~BnHwFoobar();

    ::android::status_t onTransact(
            uint32_t _hidl_code,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            uint32_t _hidl_flags = 0,
            TransactCallback _hidl_cb = nullptr) override;


    typedef IFoobar Pure;

    typedef android::hardware::details::bnhw_tag _hidl_tag;

    ::android::sp<IFoobar> getImpl() { return _hidl_mImpl; }
    // Methods from ::android::hardware::foobar::V1_0::IFoobar follow.
    static ::android::status_t _hidl_getVersion(
            ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
            const ::android::hardware::Parcel &_hidl_data,
            ::android::hardware::Parcel *_hidl_reply,
            TransactCallback _hidl_cb);



private:
    // Methods from ::android::hardware::foobar::V1_0::IFoobar follow.

    // Methods from ::android::hidl::base::V1_0::IBase follow.
    ::android::hardware::Return<void> ping();
    using getDebugInfo_cb = ::android::hidl::base::V1_0::IBase::getDebugInfo_cb;
    ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb);

    ::android::sp<IFoobar> _hidl_mImpl;
};

}  // namespace V1_0
}  // namespace foobar
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_FOOBAR_V1_0_BNHWFOOBAR_H
