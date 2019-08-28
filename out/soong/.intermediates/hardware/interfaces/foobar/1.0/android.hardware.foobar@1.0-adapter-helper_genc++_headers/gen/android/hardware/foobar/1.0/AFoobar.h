#ifndef HIDL_GENERATED_ANDROID_HARDWARE_FOOBAR_V1_0_AFOOBAR_H
#define HIDL_GENERATED_ANDROID_HARDWARE_FOOBAR_V1_0_AFOOBAR_H

#include <android/hardware/foobar/1.0/IFoobar.h>
namespace android {
namespace hardware {
namespace foobar {
namespace V1_0 {

class AFoobar : public ::android::hardware::foobar::V1_0::IFoobar {
    public:
    typedef ::android::hardware::foobar::V1_0::IFoobar Pure;
    AFoobar(const ::android::sp<::android::hardware::foobar::V1_0::IFoobar>& impl);
    // Methods from ::android::hardware::foobar::V1_0::IFoobar follow.
    virtual ::android::hardware::Return<uint32_t> getVersion() override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

    private:
    ::android::sp<::android::hardware::foobar::V1_0::IFoobar> mImpl;
};

}  // namespace V1_0
}  // namespace foobar
}  // namespace hardware
}  // namespace android
#endif // HIDL_GENERATED_ANDROID_HARDWARE_FOOBAR_V1_0_AFOOBAR_H
