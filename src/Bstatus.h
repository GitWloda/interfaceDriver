#include <fstream>

using namespace std;

string BatteryStatus(const string& filename) {
    string path = "/sys/class/power_supply/" + filename + "/status";
    ifstream statusFile(path);

    if (statusFile.is_open()) {
        string status;
        getline(statusFile, status);
        statusFile.close();
        return status;
    } else {
        return "N/A";
    }
}
