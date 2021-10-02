#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int monies = 0;
	int upgrade = 1;
	bool autoclick = false;
	bool shortcut = false;
	string x;
	cout << "type 'help.exe' for list of available programs\nC:/";
	while (true) {
		try {
			getline(cin, x);
			if (x == "help.exe") {
				cout << "click.exe -- cost: free!\n"
					"upgrade.exe -- cost: starts at five clicks\n"
					"autoclicker.exe -- cost: 100 clicks\n"
					"superupgrade.exe -- cost: starts at 1,000 clicks\n"
					"shortcut.exe -- cost: 10,000 clicks (type -c, -u, -s, or -m)\n"
					"megaupgrade.exe -- cost: starts at 100,000 clicks\n";
			}
			if (x == "click.exe") {
				monies += upgrade;
			}
			if (x == "-c" && shortcut) {
				monies += upgrade;
			}
			if (x == "upgrade.exe" && monies >= 5 + upgrade) {
				monies -= 4 + upgrade;
				upgrade += 1;
			}
			if (x == "superupgrade.exe" && monies >= 1000 + upgrade) {
				monies -= 1000 + upgrade;
				upgrade += 100;
			}
			if (x == "megaupgrade.exe" && monies >= 100000 + upgrade) {
				monies -= 100000 + upgrade;
				upgrade += 1000;
			}
			if (x == "-u" && shortcut && monies >= 5 + upgrade) {
				monies -= 4 + upgrade;
				upgrade += 1;
			}
			if (x == "-s" && shortcut && monies >= 1000 + upgrade) {
				monies -= 1000 + upgrade;
				upgrade += 100;
			}
			if (x == "-m" && shortcut && monies >= 1000 + upgrade) {
				monies -= 100000 + upgrade;
				upgrade += 1000;
			}
			if (x == "autoclicker.exe" && !autoclick && monies >= 100) {
				monies -= 100;
				autoclick = true;
			}
			if (x == "shortcut.exe" && !shortcut && monies >= 10000) {
				monies -= 10000;
				shortcut = true;
			}
			if (autoclick) {
				if (x.empty()) {
					Sleep(300);
					cout << "C:/autoclicker.exe ran in the background\n";
					monies += upgrade;
				}
				else {
					cout << "C:/autoclicker.exe ran in the background\n";
					monies += upgrade;
				}
			}
			if (monies < 0) {
				cout << "Stack Overflow! You win!!!";
				cin.ignore();
				break;
			}
			cout << "clicks: ";
			cout << monies;
			cout << "\nC:/";
		}
		catch (...) {
			cout << "error, program terminated";
			break;
		}
	}
	return 0;
}