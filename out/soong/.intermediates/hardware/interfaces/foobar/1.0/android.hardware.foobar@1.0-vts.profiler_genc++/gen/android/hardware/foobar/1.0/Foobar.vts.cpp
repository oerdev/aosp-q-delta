#include "android/hardware/foobar/1.0/Foobar.vts.h"
#include <cutils/properties.h>

using namespace android::hardware::foobar::V1_0;
using namespace android::hardware;

#define TRACEFILEPREFIX "/data/local/tmp/"

namespace android {
namespace vts {

void HIDL_INSTRUMENTATION_FUNCTION_android_hardware_foobar_V1_0_IFoobar(
        details::HidlInstrumentor::InstrumentationEvent event __attribute__((__unused__)),
        const char* package,
        const char* version,
        const char* interface,
        const char* method __attribute__((__unused__)),
        std::vector<void *> *args __attribute__((__unused__))) {
    if (strcmp(package, "android.hardware.foobar") != 0) {
        LOG(WARNING) << "incorrect package. Expect: android.hardware.foobar actual: " << package;
    }
    std::string version_str = std::string(version);
    int major_version = stoi(version_str.substr(0, version_str.find('.')));
    int minor_version = stoi(version_str.substr(version_str.find('.') + 1));
    if (major_version != 1 || minor_version > 0) {
        LOG(WARNING) << "incorrect version. Expect: 1.0 or lower (if version != x.0), actual: " << version;
    }
    if (strcmp(interface, "IFoobar") != 0) {
        LOG(WARNING) << "incorrect interface. Expect: IFoobar actual: " << interface;
    }

    VtsProfilingInterface& profiler = VtsProfilingInterface::getInstance(TRACEFILEPREFIX);

    bool profiling_for_args = property_get_bool("hal.instrumentation.profile.args", true);
    if (strcmp(method, "getVersion") == 0) {
        FunctionSpecificationMessage msg;
        msg.set_name("getVersion");
        if (profiling_for_args) {
            if (!args) {
                LOG(WARNING) << "no argument passed";
            } else {
                switch (event) {
                    case details::HidlInstrumentor::CLIENT_API_ENTRY:
                    case details::HidlInstrumentor::SERVER_API_ENTRY:
                    case details::HidlInstrumentor::PASSTHROUGH_ENTRY:
                    {
                        if ((*args).size() != 0) {
                            LOG(ERROR) << "Number of arguments does not match. expect: 0, actual: " << (*args).size() << ", method name: getVersion, event type: " << event;
                            break;
                        }
                        break;
                    }
                    case details::HidlInstrumentor::CLIENT_API_EXIT:
                    case details::HidlInstrumentor::SERVER_API_EXIT:
                    case details::HidlInstrumentor::PASSTHROUGH_EXIT:
                    {
                        if ((*args).size() != 1) {
                            LOG(ERROR) << "Number of return values does not match. expect: 1, actual: " << (*args).size() << ", method name: getVersion, event type: " << event;
                            break;
                        }
                        auto *result_0 __attribute__((__unused__)) = msg.add_return_type_hidl();
                        uint32_t *result_val_0 __attribute__((__unused__)) = reinterpret_cast<uint32_t*> ((*args)[0]);
                        if (result_val_0 != nullptr) {
                            result_0->set_type(TYPE_SCALAR);
                            result_0->mutable_scalar_value()->set_uint32_t((*result_val_0));
                        } else {
                            LOG(WARNING) << "return value 0 is null.";
                        }
                        break;
                    }
                    default:
                    {
                        LOG(WARNING) << "not supported. ";
                        break;
                    }
                }
            }
        }
        profiler.AddTraceEvent(event, package, version, interface, msg);
    }
}

}  // namespace vts
}  // namespace android
