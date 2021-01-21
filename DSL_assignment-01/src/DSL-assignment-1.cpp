//============================================================================
// Name        : DSL-assignment-1.cpp
// Author      : OMKAR
// Version     :
// Copyright   : free to use
// Description : Hello World in C++, Ansi-style
//============================================================================

/*psedocode:
 1)start
 2)create a class name student with private variables name ,isc ,isb, isf
 3)create a function named check
 4)create a function named createnstoreobj
 5)set the static variable scnt
 6)initiate main function
 */
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

//DECLARING A CLASS NAMED STUDENT

class student {
public:
	static int scnt;
	void getdetails(string tname, bool isc, bool isb, bool isf) {
		student::scnt=student::scnt+1;
		this->name = tname;
		this->c = isc;
		this->b = isb;
		this->f = isf;
	}
	string returnname() {
		return name;
	}
	bool returnc() {
		return c;
	}
	bool returnb() {
		return b;
	}
	bool returnf() {
		return f;
	}
private:
	string name;
	bool c;
	bool b;
	bool f;

};

//DECLARING A FUNCTION TO CHECK WHETHER NAME OF THE STUDENT EXISTS IN THE LIST OR NOT

bool check(string checkname, student scontainer[80]) {
	bool flag = false;
	for (int a = 0; a <= student::scnt; a++) {
		if (checkname == scontainer[a].returnname()) {
			flag = true;
		};
	}
	return flag;
}

student createnstoreobj(string fname,bool fc,bool fb,bool ff,student arr[80]){
	//student so(fname,fc,fb,ff);
	arr[student::scnt].getdetails(fname,fc,fb,ff);
	return arr[student::scnt];
}

int student::scnt = -1;

int main() {
	int choice, showname, cont;
	bool dc, db, df;
	student scontainer [80];
	cout << "Hello,";
	while (true) {
		cout<<"\n.-----------------------------------------------------------------\nPlease select one of the options from following: \n1)Create a student's profile\n2)Sort out few students\nEnter your number of your choice here: \n-----------------------------------------------------------------";
		cin >> choice;
		if (choice == 1) {
			string tname, tgame;
			bool tc, tb, tf;
			cout << "\nPlease enter the name of student: ";
			cin >> tname;
			transform(tname.begin(), tname.end(), tname.begin(), ::toupper);
			if (check(tname, scontainer)) {
				cout << "\nName " << tname << " already exists in the record";
			} else {
				cout << "\nDoes the student play Cricket:(Y/N): ";
				cin >> tgame;
				if (tgame == "Y" || tgame == "y") {
					tc = true;
				} else if (tgame == "N" || tgame == "n") {
					tc = false;
				} else {
					cout << "\nYou messed up please REPEAT";
					continue;
				}
				cout << "\nDoes the student play Badminton:(Y/N): ";
				cin >> tgame;
				if (tgame == "Y" || tgame == "y") {
					tb = true;
				} else if (tgame == "N" || tgame == "n") {
					tb = false;
				} else {
					cout << "\nYou messed up please REPEAT";
					continue;
				}
				cout << "\nDoes the student play Football:(Y/N): ";
				cin >> tgame;
				if (tgame == "Y" || tgame == "y") {
					tf = true;
				} else if (tgame == "N" || tgame == "n") {
					tf = false;
				} else {
					cout << "\nYou messed up please REPEAT from the beginning";
					continue;
				}
				createnstoreobj(tname, tc, tb, tf,scontainer);
				//student so(tname, tc, tb, tf);
				//scontainer[student::scnt].getdetails(tname, tc, tb, tf);
				//continue;
				//scontainer[student::scnt]=so;
			}
		;}
		if (choice == 2) {
			showname = 0;
			cout << "\nEnter 1 if the student plays Cricket :";
			cin >> dc;
			dc == 1 ? dc = true : dc = false;
			cout << "\nEnter 1 if the student plays Badminton :";
			cin >> db;
			db == 1 ? db = true : db = false;
			cout << "\nEnter 1 if the student plays Football :";
			cin >> df;
			df == 1 ? df = true : df = false;
			cout << "\nFollowing are the names of required students: ";
			for (int a = 0; a <= student::scnt; a++) {
				if (scontainer[a].returnc() == dc
						&& scontainer[a].returnb() == db
						&& scontainer[a].returnf() == df) {
					cout << endl << scontainer[a].returnname();
					showname++;
				}
			}
			cout << "\nShowing " << showname << " out of " << student::scnt+1;
		}
	}
	return 0;
}
