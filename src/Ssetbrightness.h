#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <filesystem>

//#include <Sstatus.h>

using namespace std;

bool isInteger(int argc, char *argv[], int num);
void errPermission(string brightnessPath);

void SetBrightness(int argc, char *argv[], int screenStatus){
	string entryName;
	string path = "/sys/class/backlight/";
	if (isInteger(argc, argv, 3)) {
		int i = 0;
		for (const auto& entry : filesystem::directory_iterator(path)) {
        		if (i == stoi(argv[3])) {
        			entryName = entry.path().filename().string();
        			break; // Esci dal ciclo una volta raggiunto n
        		}
			++i;
		}
	} else {
		entryName = argv[3];
	}
	char firstChar = argv[4][0];
	string brightnessPath = path + entryName + "/brightness";
	ofstream brightnessFile(brightnessPath);
	if ( firstChar == '-' || firstChar == '+' ) {
		if (brightnessFile.is_open()) {
			int newBrightness = stoi(argv[4]) + screenStatus;
        		brightnessFile << to_string(newBrightness);
        		brightnessFile.close();

    		} else {
			errPermission(brightnessPath);
    		}
	}
	else if (isInteger(argc, argv, 4)){
    		if (brightnessFile.is_open()) {
        		brightnessFile << to_string(stoi(argv[4]));
        		brightnessFile.close();
    		} else {
			errPermission(brightnessPath);
    		}
	} else {
		cout << argv[4] << " non supportato per " << entryName;
	}
}

void errPermission(string brightnessPath){
	string username = getenv("USER");
        cerr << "Impossibile aprire il file di luminosità.\nProva a eseguire il programma con permessi maggiori o prova a dare i permessi di scrittura all'utente: "<< username << " sul file: " << brightnessPath << " \nusando con il comando \"chmod +x "<< brightnessPath <<"\"" << endl;

}

bool isInteger(int argc, char *argv[], int num) {
	try {
        	int intValue = stoi(argv[num]);
        	return true; // hai inserito un numero
	} catch (const invalid_argument&) {
		return false; // hai inserito una stringa
	}
}
