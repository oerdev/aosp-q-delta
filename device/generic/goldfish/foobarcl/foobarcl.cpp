#define LOG_TAG "android.hardware.foobar@1.0-service"
//_headers/gen/android/hardware/foobar/1.0/IFoobar.h
#include <android/hardware/foobar/1.0/IFoobar.h>
#include <hidl/Status.h>
#include <hidl/LegacySupport.h>
#include <utils/misc.h>
#include <utils/Log.h>
//#include <hardware/hardware.h>
#include <hidl/HidlSupport.h>


#include<stdio.h>


using android::hardware::foobar::V1_0::IFoobar;
using android::sp;


int main() {
      uint32_t res;
      android::sp<IFoobar> ser = IFoobar::getService();

      res = ser->getVersion();

      printf("val=%d\n", res);

      return 0; 
}
