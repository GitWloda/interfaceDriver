#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void calculateBatteryTime(const string filename) {
    string batteryPath = "/sys/class/power_supply/"+filename+"/";
    string energyNowPath = batteryPath + "energy_now";
    string powerNowPath = batteryPath + "power_now";

    ifstream file(energyNowPath);
    string value;
    file >> value;
    string energyNowStr = value;
    file.close();
    file.open(powerNowPath);
    file >> value;
    string powerNowStr = value;

    try {
        double energyNow = stod(energyNowStr);
        double powerNow = stod(powerNowStr);

        double remainingTime = energyNow / powerNow;

        int hours = static_cast<int>(remainingTime);
        int minutes = static_cast<int>((remainingTime - hours) * 60);

        cout << "Tempo rimanente: " << hours << " ore e " << minutes << " minuti" << endl;
    } catch (invalid_argument &e) {
        cerr << "Errore nella conversione del valore: " << e.what() << endl;
	}
}
