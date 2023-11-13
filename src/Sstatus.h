#include <cstring>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

int BrightnessStatus(int argc, char *argv[]) {
	string path = "/sys/class/backlight/";
	int i=0;
	for (const auto& entry : filesystem::directory_iterator(path)) {
		string entryName = entry.path().filename().string();
        	if (!strcmp(argv[3], to_string(i).c_str()) || !strcmp(argv[3], entryName.c_str())) {
			path = "/sys/class/backlight/" + entryName + "/brightness";
			ifstream file(path);
    			if (file.is_open()) {
       				string brightness;
       				file >> brightness;
       				file.close();
				return stoi(brightness);
			}
       		}
 	}	
	return -1;
}
