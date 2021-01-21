
#include <iostream>
#include <string>
using namespace std;

class update;

class data {

private:
	string name, clas, dob, blood, address, dlic;
	int roll;
	char div;
	float sgpa;
	long int tele;

public:

	class error{
	string msg;
	string clas;
	public:
		error(string m,string cl):msg(m),clas(cl){}
		void geterror(){
			cout<<"Error in "<<clas<<" class :"<<msg;
		}
	};

	static int cnt;

	data() :
			div('Z'), sgpa(0.0), tele(00000) {
		data::icnt();
	}

	~data() {
		cout << endl << "Database of " << this->name << " is lost!!";
	}

	void setdata() {
		cout << endl << "Enter the name of the student: ";
		cin.ignore();
		getline(cin, this->name);
		cout << "Roll no.: ";
		cin.ignore();
		cin >> this->roll;
		if(this->roll<0)throw data::error((string)("negative roll not allowed"),(string)("data"));
		cout << "Class: ";
		cin >> this->clas;
		cout << "Division: ";
		cin.ignore();
		cin >> this->div;
		cout << "DOB in (DD/MM/YYYY):";
		cin.ignore();
		cin >> this->dob;
		cout << "Blood type: ";
		cin >> this->blood;
		cout << "Contact address: ";
		cin.ignore();
		getline(cin, address);
		cout << "Telephone no.: ";
		cin >> this->tele;
		if(this->tele<0)throw error((string)("negative telephone no. not allowed"),(string)("data"));
		cout << "Driving license no.: ";
		cin >> this->dlic;
		cout << "Last semester's SGPA: ";
		cin >> this->sgpa;
		if(this->sgpa<0)throw error((string)("negative sgpa not allowed"),(string)("data"));

	}

	void show() {
		cout << endl << "Name of the student: ";
		cout << this->name << endl;
		cout << "Roll no.: ";
		cout << this->roll << endl;
		cout << "Class: ";
		cout << this->clas << endl;
		cout << "Division: ";
		cout << this->div << endl;
		cout << "DOB in (DD/MM/YYYY):";
		cout << this->dob << endl;
		cout << "Blood type: ";
		cout << this->blood << endl;
		cout << "Contact address: ";
		cout << this->address << endl;
		cout << "Telephone no.: ";
		cout << this->tele << endl;
		cout << "Driving license no.: ";
		cout << this->dlic << endl;
		cout << "Last semester's SGPA: ";
		cout << this->sgpa << endl;

	}

	string rname() {
		return this->name;
	}

	static void icnt() {
		data::cnt++;
	}

	friend class update;
};

class update {
public:
	void uname(data &obj) {
		cout << "Old name: " << obj.name << endl;
		cout << "New name:";
		cin.ignore();
		getline(cin, obj.name);
		cout << "Name updated!!";
	}

	void uroll(data &obj) {
		cout << "Old roll no.: " << obj.roll << endl;
		cout << "New name:";
		cin.ignore();
		cin>> obj.roll;
		if(obj.roll<0)throw data::error((string)("negative roll not allowed"),(string)("update"));
		cout << "Roll no. updated!!";
	}

	void uclas(data &obj) {
		cout << "Old class: " << obj.clas << endl;
		cout << "New clas:";
		cin.ignore();
		getline(cin, obj.clas);
		cout << "Class updated!!";
	}

	void udob(data &obj) {
		cout << "Old DOB: " << obj.dob << endl;
		cout << "New DOB:";
		cin.ignore();
		getline(cin, obj.dob);
		cout << "DOB updated!!";
	}

	void ublood(data &obj) {
		cout << "Old Blood type: " << obj.blood << endl;
		cout << "New Blood type:";
		cin.ignore();
		getline(cin, obj.blood);
		cout << "Blood type updated!!";
	}

	void uaddress(data &obj) {
		cout << "Old Address: " << obj.address << endl;
		cout << "New Address:";
		cin.ignore();
		getline(cin, obj.address);
		cout << "Address updated!!";
	}

	void udlic(data &obj) {
		cout << "Old License no: " << obj.dlic << endl;
		cout << "New License no:";
		cin.ignore();
		getline(cin, obj.dlic);
		cout << "License no. updated!!";
	}

	void udiv(data &obj) {
		cout << "Old Division: " << obj.div << endl;
		cout << "New Division:";
		cin.ignore();
		cin >> obj.div;
		cout << "Division updated!!";
	}

	void utele(data &obj) {
		cout << "Old Telephone no.: " << obj.tele << endl;
		cout << "New Telephone no.:";
		cin.ignore();
		cin >> obj.tele;
		if(obj.tele<0)throw data::error((string)("negative telephone no. not allowed"),(string)("update"));
		cout << "Telephone no. updated!!";
	}

	void usgpa(data &obj) {
		cout << "Old SGPA: " << obj.sgpa << endl;
		cout << "New SGPA:";
		cin.ignore();
		cin >> obj.sgpa;
		if(obj.sgpa<0)throw data::error((string)("negative sgpa not allowed"),(string)("update"));
		cout << "SGPA updated!!";
	}
};

int data::cnt = 0;

int main() {
	try{
	int a, c;
	int b = 0;
	bool flag = true;
	char f;
	cout << "Enter the maximum strength of class:";
	cin >> a;
	data* s[a];
	while (true) {
		cout<< "\n1)Create a database of students\n2)Search for student by name\n3)Update a field in student's profile \n4)Show whole database\n5)Delete whole database\nEnter choice number: ";
		cin >> c;
		if (c == 1) {
			while (flag) {
				s[b] = new data;
				s[b]->setdata();
				cout
						<< "\nEnter y to add database of one more student and p to proceed to main menu:";
				cin >> f;
				b++;
				if (f != 'y') {
					break;
				}
			}
		}

		if (c == 2) {
			string nn;
			cout << "Enter the name to be searched: ";
			cin.ignore();
			getline(cin, nn);
			for (int b = 0; b < data::cnt; b++) {
				if (nn == s[b]->rname()) {
					s[b]->show();
					break;
				}
			}
		}

		if (c == 3) {
			string nn;
			update me;
			int wow;
			cout << "Enter the name of student to be updated: ";
			cin.ignore();
			getline(cin, nn);
			for (int b = 0; b < (data::cnt); b++) {
				if (nn == s[b]->rname()) {
					break;
				}
			}

			cout<<"1)Name\n2)Roll no.\n3)Class\n4)DOB\n5)Blood\n6)Address\n7)Driving license\n8)Division\n9)SGPA\n10)Telephone no.\nEnter choice no.: ";
			cin.ignore();
			cin >> wow;
			if(wow== 1){
				me.uname(*s[b]);
			}
			if(wow==2){
				me.uroll(*s[b]);
			}
			if(wow== 3){
				me.uclas(*s[b]);
			}
			if(wow==4){
				me.udob(*s[b]);
			}
			if(wow==5){
				me.ublood(*s[b]);
			}
			if(wow==6){
				me.uaddress(*s[b]);
			}
			if(wow==7){
				me.udlic(*s[b]);
			}
			if(wow== 8){
				me.udiv(*s[b]);
			}
			if(wow==9){
				me.usgpa(*s[b]);
			}
			if(wow==10){
				me.utele(*s[b]);
			}
			else{
				cout << "\nInvalid choice";
			}
		}

		if (c == 4) {
			cout << "\n\nDatabase of " << data::cnt
					<< " students is as follows:\n";
			for (int b = 0; b < (data::cnt); b++) {
				s[b]->show();
			}
		}

		if (c == 5) {
			for (int b = 0; b < (data::cnt); b++) {
				delete s[b];
			}
			break;
		}
	}
	}catch(data::error& err){
		err.geterror();
	}
		return 0;

}
