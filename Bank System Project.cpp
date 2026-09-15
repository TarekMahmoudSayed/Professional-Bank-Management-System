#include <iostream>

#include "clsLoginScreen.h"
#include "Global.h"

#include <iomanip>

clsUser CurrentUser = clsUser::Find("", "");

using namespace std;

int main() {


	while (true) {
		clsLoginScreen::ShowLoginScreen();
	}

	return 0;
}