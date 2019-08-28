#include <hidladapter/HidlBinderAdapter.h>
#include <android/hardware/foobar/1.0/AFoobar.h>
int main(int argc, char** argv) {
    return ::android::hardware::adapterMain<
        ::android::hardware::foobar::V1_0::AFoobar>("android.hardware.foobar@1.0", argc, argv);
}
