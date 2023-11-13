#include "Slist.h"
#include "Ssetbrightness.h"

using namespace std;

void BrightnessScreen(int argc, char *argv[], int screenStatus){
	if (!strcmp(argv[2], "-l") || !strcmp(argv[2], "--list")) {
		BrightnessList();
	} else if (!strcmp(argv[2], "-s") || !strcmp(argv[2], "--set")) {
		SetBrightness(argc, argv, screenStatus);
		
	} else if (!strcmp(argv[2], "-g") || !strcmp(argv[2], "--get")) {		
		cout << screenStatus;
	}
}
