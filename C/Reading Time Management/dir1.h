#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>

using namespace std;

//front page
void dirMessage() {
	char timestring[26];
	system("cls");
	time_t ct = time(0);
	ctime_s(timestring, sizeof(timestring), &ct);
	cout << "    The current time is" << timestring << "\n" << endl;
	cout << "***Welcome to Extracurriculum Reading Time Management System***" << "\n\n" << endl;
	cout << "    Start(Option s)" << endl;
	cout << "    Menu(Option m)" << endl;
	cout << "\n" << "Exit(Option E)" << endl;
	cout << "\n" << "Choose:";
}
