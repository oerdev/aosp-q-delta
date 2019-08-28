#ifndef __VTS_PROFILER_android_hardware_foobar_V1_0_IFoobar__
#define __VTS_PROFILER_android_hardware_foobar_V1_0_IFoobar__


#include <android-base/logging.h>
#include <hidl/HidlSupport.h>
#include <linux/limits.h>
#include <test/vts/proto/ComponentSpecificationMessage.pb.h>
#include "VtsProfilingInterface.h"

// HACK: NAN is #defined by math.h which gets included by
// ComponentSpecificationMessage.pb.h, but some HALs use
// enums called NAN.  Undefine NAN to work around it.
#undef NAN

#include <android/hardware/foobar/1.0/IFoobar.h>
#include <android/hidl/base/1.0/types.h>


using namespace android::hardware::foobar::V1_0;
using namespace android::hardware;

namespace android {
namespace vts {
extern "C" {

    void HIDL_INSTRUMENTATION_FUNCTION_android_hardware_foobar_V1_0_IFoobar(
            details::HidlInstrumentor::InstrumentationEvent event,
            const char* package,
            const char* version,
            const char* interface,
            const char* method,
            std::vector<void *> *args);
}

}  // namespace vts
}  // namespace android
#endif
