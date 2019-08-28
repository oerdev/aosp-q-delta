#include <android/hardware/foobar/1.0/AFoobar.h>
#include <hidladapter/HidlBinderAdapter.h>
#include <android/hardware/foobar/1.0/IFoobar.h>
#include <android/hidl/base/1.0/ABase.h>

namespace android {
namespace hardware {
namespace foobar {
namespace V1_0 {

AFoobar::AFoobar(const ::android::sp<::android::hardware::foobar::V1_0::IFoobar>& impl) : mImpl(impl) {}// Methods from ::android::hardware::foobar::V1_0::IFoobar follow.
::android::hardware::Return<uint32_t> AFoobar::getVersion(){
    auto _hidl_out = mImpl->getVersion(
    );
    if (!_hidl_out.isOkUnchecked()) {
        return _hidl_out;
    }return _hidl_out;
}

// Methods from ::android::hidl::base::V1_0::IBase follow.

}  // namespace V1_0
}  // namespace foobar
}  // namespace hardware
}  // namespace android

