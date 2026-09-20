#include <iostream>

#include "clsLoginScreen.h"
#include "Global.h"


clsUser CurrentUser = clsUser::Find("", "");

using namespace std;

int main() {

	while (true) {
		if (!(clsLoginScreen::ShowLoginScreen())) {
			break;
		}
	}

	//clsCurrecnyCalculatorScreen::ShowCurrecnyCalculator();


return 0;
}