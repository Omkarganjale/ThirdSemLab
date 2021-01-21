//============================================================================
// Name        : OOP_assignment_3.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>
//#include <typeinfo>
using namespace std;



class publication{
protected:
	string title;
	float price;
public:
	publication(string egg="",float yolk=0.0)
	:title(egg),price(yolk)
	{}


	virtual void show() const {}

	virtual ~publication(){}

};

class books:public publication{
private:
	unsigned int pc;
public:

	books():publication(),pc(0){}

	books(string egg,float yolk,unsigned int shell=0)
	:publication(egg,yolk),pc(shell)
	{}

	class error{
	string errormsg;
	public:

			error(string msg):errormsg(msg){
			}

			void geterror(){
				cout<<"\nError in book class :"<<this->errormsg;
			}
		};

	void get(){
		cout<<"Enter Title: ";
		cin.ignore();
		getline(cin,title);
		cout<<"Enter Price: ";
		cin>>price;
		if (price<0)throw error("Price of book cannot be negative\n");
		cout<<"Enter count: ";
		cin>>pc;
		if (pc<0)throw error("page count of book cannot be negative\n");
	}

	void show() const override{

			cout<<"\nBook Title:"<<this->title<<endl;
			cout<<"Price:"<<this->price<<endl;
			cout<<"Page count: "<<this->pc;
		}
};

class tape:public publication{
private:
	unsigned int min;
public:

	tape():publication(),min(0){}

	tape(string egg,float yolk,unsigned int shell=0)
	:publication(egg,yolk),min(shell)
	{}

	class error{
		string errormsg;
		public:

				error(string msg=""):errormsg(msg){
				}

				void geterror(){
					cout<<"\nError in tape class :"<<this->errormsg;
				}
			};

	void get(){
			cout<<"Enter Title: ";
			cin.ignore();
			getline(cin,title);
			cout<<"Enter Price: ";
			cin>>price;
			if (price<0)throw error("Price of tape cannot be negative\n");
			cout<<"Enter Time duration in minutes: ";
			cin>>min;
			if (min<0)throw error("Time duration of tape cannot be negative\n");
		}

	void show() const override{

				cout<<"\nTape Title:"<<this->title<<endl;
				cout<<"Price:"<<this->price<<endl;
				cout<<"Time (min): "<<this->min;
			}

};

int main() {

	vector<publication*> vec;

	int ch;

	//a:
	try{

	while(true){

	cout<<"\n1)Include a book\n2)Include a tape\n3)Show all\n4)Quit\nEnter choice number: ";

	cin>>ch;

	if (ch>4){
		throw ("Choice number is out of range");
	}

	cout<<endl;

	if (ch == 1){
		books* bk= new books;
		bk->get();
		vec.push_back(bk);
	}

	else if (ch == 2){
		tape* tp= new tape;
		tp->get();
		vec.push_back(tp);
	}

	else if (ch == 3){
		int ipl=vec.size();
		for(int h=0;h<ipl;h++){
			//cout<<"."<< typeid(vec[h]).name() << endl;
			vec[h]->show();
			cout<<endl;

		}
	}

	else if (ch == 4){
		int ipl=vec.size();
		for(int h=0;h<ipl;h++){
			delete vec[h];
		}
		vec.clear();
		cout<<"Data Base cleared!!"<<endl;
		break;
	}

	}
	}catch(string& kt){
			cout<<kt;
			//goto a;
	}
	catch(books::error& abc){
		abc.geterror();
		//goto a;
	}
	catch(tape::error& abc){
		abc.geterror();
		//goto a;
	}
	return 0;
}
