#include "Binterface.h"
#include "Sscreen.h"
#include "Sstatus.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (!strcmp(argv[1], "-b") || !strcmp(argv[1], "--battery")) {
        BatteryInterface();
    } else if ( !strcmp(argv[1], "-sl") || !strcmp(argv[1], "--screenLight")) {
	BrightnessScreen(argc, argv, BrightnessStatus(argc, argv));
    } else {
        cerr << "Invalid option: " << argv[1] << endl;
        return 1;
    }

    return 0;
}

