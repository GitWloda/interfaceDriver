#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void calculateChargingTime(const string filename) {
    string batteryPath = "/sys/class/power_supply/"+filename+"/";
    string energyNowPath = batteryPath + "energy_now";
    string powerNowPath = batteryPath + "power_now";
    string energyFullPath = batteryPath + "energy_full";

    ifstream file(energyNowPath);
    string value;
    file >> value;
    string energyNowStr = value;
    file.close();
    file.open(powerNowPath);
    file >> value;
    string powerNowStr = value;
    file.close();
    file.open(energyFullPath);
    file >> value;
    string energyFullStr = value;

    try {
        double energyNow = stod(energyNowStr);
        double powerNow = stod(powerNowStr);
        double energyFull = stod(energyFullStr);

        // Calcola il tempo stimato per la carica completa in ore
        double remainingTime = (energyFull - energyNow) / powerNow;

        int hours = static_cast<int>(remainingTime);
        int minutes = static_cast<int>((remainingTime - hours) * 60);

        // Stampa il tempo stimato per la carica completa
        cout << "carica completa: " << hours << "h " << minutes << "m" << endl;
    } catch (invalid_argument &e) {
        cerr << "Errore nella conversione del valore: " << e.what() << endl;
    }
}
