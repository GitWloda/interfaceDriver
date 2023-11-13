#include <dirent.h>
#include <string>

#include "Bstatus.h"
#include "Bcapacity.h"
#include "Bdischargetime.h"
#include "Bchargetime.h"

using namespace std;

void BatteryInterface() {
    string directory = "/sys/class/power_supply/";

    DIR* dir;
    struct dirent* ent;
    int numBat = 0; // Numero di batterie
    string filename;
    if ((dir = opendir(directory.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            filename = ent->d_name;
            if (filename.rfind("BAT", 0) == 0) {
                numBat += 1;
            }
        }
        if (numBat > 1) {
            cerr << "E: multi battery not supported yet" << endl;
        } else {
            cout << BatteryStatus(filename);
            cout << BatteryCapacity(filename) << "\n";
	    calculateChargingTime(filename);
	    calculateBatteryTime(filename);
        }
        closedir(dir);
    }
}
