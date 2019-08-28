#define LOG_TAG "android.hardware.foobar@1.0-service"

#include <android/log.h>
#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include <android/hardware/foobar/1.0/IFoobar.h>
#include "Foobar.h"

using android::hardware::foobar::V1_0::IFoobar;
using android::hardware::foobar::V1_0::implementation::Foobar;

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::sp;

int main() {
    android::sp<IFoobar> foo = Foobar::getInstance();
    configureRpcThreadpool(1, true);

    if (foo != nullptr) {
        if(::android::OK != foo->registerAsService()) {
	    return 1;
	}
    } else {
        ALOGE("Got null ptr for foobar instance");
    }

    joinRpcThreadpool();

    return 0;
}
