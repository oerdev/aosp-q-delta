// FIXME: your file license if you have one

#pragma once

#include <android/hardware/foobar/1.0/IFoobar.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace foobar {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Foobar : public IFoobar {
public:
    Foobar();
    ~Foobar();
    static IFoobar* getInstance();
    // Methods from ::android::hardware::foobar::V1_0::IFoobar follow.
    Return<uint32_t> getVersion() override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

private:
    static Foobar* sInstance;
};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IFoobar* HIDL_FETCH_IFoobar(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace foobar
}  // namespace hardware
}  // namespace android
