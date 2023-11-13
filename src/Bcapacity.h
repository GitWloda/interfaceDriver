#include <fstream>
#include <string>

using namespace std;

int BatteryCapacity(const string& filename) {
    string path = "/sys/class/power_supply/" + filename + "/capacity";
    ifstream capacityFile(path);

    if (capacityFile.is_open()) {
        string capacity;
        getline(capacityFile, capacity);
        capacityFile.close();
        return stoi(capacity);
    } else {
        return 0;
    }
}
