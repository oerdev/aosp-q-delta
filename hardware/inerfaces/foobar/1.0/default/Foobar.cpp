// FIXME: your file license if you have one

#include "Foobar.h"

namespace android {
namespace hardware {
namespace foobar {
namespace V1_0 {
namespace implementation {

Foobar* Foobar::sInstance = nullptr;

Foobar::Foobar() {}
Foobar::~Foobar() {}
IFoobar* Foobar::getInstance() {
    if(!sInstance) {
        sInstance = new Foobar();
    }
    return sInstance;
}

// Methods from ::android::hardware::foobar::V1_0::IFoobar follow.
Return<uint32_t> Foobar::getVersion() {
    return 112;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//IFoobar* HIDL_FETCH_IFoobar(const char* /* name */) {
    //return new Foobar();
//}
//
}  // namespace implementation
}  // namespace V1_0
}  // namespace foobar
}  // namespace hardware
}  // namespace android
