#include <iostream>
#include <string>
#include <filesystem>

using namespace std;

void BrightnessList () {
	string path = "/sys/class/backlight/";
	int i = 0;
	for (const auto& entry : filesystem::directory_iterator(path)) {
		string entryName = entry.path().filename().string();
        	cout <<i<<": "<< entryName << std::endl;
		++i;
    	}
}
