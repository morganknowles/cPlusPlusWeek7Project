#include "ArrayList.h"
/*
Morgan Knowles
12/11/2016
Microsoft Visual Studio


*/

int main() {
	char userOpt = '?';
	string userString;

	ArrayList<string>joe(0);
	ArrayList<string>sally(0);
	ArrayList<string> temp(joe.size() + sally.size());

	cout << "Enter m for menu or q to quit" << endl;




	do {
		cout << endl << "__________________________________________" << endl;
		cin >> userOpt;
		switch (userOpt) {
		case 'a'://"Add a name to Joe's list (a)"
			cout << "Enter a baby name to add to Joe's list: " << endl;
			cin >> userString;
			try {
				joe.add(userString);
			}
			catch (invalid_argument ia) {
				cout << ia.what();
			}
			break;
		case 'b'://"Add a name to Sallys's list (b)"
			cout << "Enter a baby name to add to Sallys's list: " << endl;
			cin >> userString;
			try {
				sally.add(userString);
			}
			catch (invalid_argument ia) {
				cout << ia.what();
			}
			break;
		case 'c'://"View all names in Joe's list (c)
			if (joe.isEmpty()) {
				cout << "Joes's list is empty." << endl;
			}
			else {
				cout << "Joe's list:" << endl;
				for (int i = 0; i < joe.size(); i++) {
					cout << i + 1 << ": " << joe.get(i) << endl;
				}
			}
			break;
		case 'd'://"View all names in Sally's list (d)"
			if (sally.isEmpty()) {
				cout << "Sally's list is empty." << endl;
			}
			else {
				cout << "Sally's list:" << endl;
				for (int i = 0; i < sally.size(); i++) {
					cout << i + 1 << ": " << sally.get(i) << endl;
				}
			}
			break;
		case 'e'://"View all names that are only in Joe's list (but not Sally's) (e)" 
			if (joe.isEmpty()) {
				cout << "Joe's list is empty." << endl;
			}
			else {
				cout << "Names that are only in Joe's list:" << endl;
				for(int i = 0; i < joe.size(); i++){
					if (!(sally.contains(joe.get(i)))) {
						cout << joe.get(i) << endl;
					}
				}
			}
			break;
		case 'f'://"View all names that are only in Sally's list (but not Joe's) (f)"
			if (sally.isEmpty()) {
				cout << "Sally's list is empty." << endl;
			}
			else {
				cout << "Names that are only in Sally's list:" << endl;
				for (int i = 0; i < sally.size(); i++) {
					if (!(joe.contains(sally.get(i)))) {
						cout << sally.get(i) << endl;
					}
				}
			}
			break;
		case 'g'://"View all names that are contained in both lists (g)" 
			

			if (sally.isEmpty()) {
				cout << "Sally's list is empty." << endl;
			}
			else if (joe.isEmpty()) {
				cout << "Joe's list is empty." << endl;
			}
			else {
				cout << "Names that are in both Sally and Joe's lists: " << endl;
				for (int i = 0; i < joe.size(); i++) {
					if (sally.contains(joe.get(i))) {
						cout << joe.get(i) << endl;
					}
				}
			}
			break;
		case 'h'://"Replace Joe's list with Sally's (h)"
			if (joe.isEmpty()) {
				cout << "Joes's list is empty." << endl;
			}
			else {
				joe = sally;
				cout << "Joe's new list:" << endl;
				for (int i = 0; i < joe.size(); i++) {
					cout << i+ 1<<": " << joe.get(i) << endl;
				}
			}
			break;
		case 'm':
			cout << "MENU" << endl;
			cout << "Add a name to Joe's list (a)" << endl;
			cout << "Add a name to Sallys's list (b)" << endl;
			cout << "View all names in Joe's list (c)" << endl;
			cout << "View all names in Sally's list (d)" << endl;
			cout << "View all names that are only in Joe's list (but not Sally's) (e)" << endl;
			cout << "View all names that are only in Sally's list (but not Joe's) (f)" << endl;
			cout << "View all names that are contained in both lists (g)" << endl;
			cout << "Replace Joe's list with Sally's (h)" << endl;
			cout << "View menu (m)" << endl;
			cout << "Quit (q)" << endl;
			break;
		default:
			break;
		}
	} while (userOpt != 'q');
}