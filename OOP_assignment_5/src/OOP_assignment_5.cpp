//============================================================================
// Name        : OOP_assignment_5.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class item{
	int code;
	std::string name;
	float cost;
	int quantity;
public:

	item():code(0),name(""),cost(0.0),quantity(0){

	}

	item(int c,std::string n,float f,int q)
		:code(c),name(n),cost(f),quantity(q){
	}

	void getitem(){
		std::cout << "Enter item name: ";
		std::cin>>this->name;
		std::cout << "Enter item code: ";
		std::cin>>this->code;
		std::cout << "Enter item cost: ";
		std::cin>>this->cost;
		std::cout << "Enter item quantity: ";
		std::cin>>this->quantity;
	}

	void show() const {
		std::cout<<"Name: "<<this->name<<std::endl;
		std::cout<<"Code: "<<this->code<<std::endl;
		std::cout<<"Cost: "<<this->cost<<std::endl;
		std::cout<<"Quantity: "<<this->quantity<<std::endl;
	}

	int returncode(){
		return this->code;
	}

	bool operator<(item& rhs) const {
		return this->code<rhs.code;
	}

	bool operator==(item& rhs) const {

			return (this->name == rhs.name &&
				this->code == rhs.code &&
				this->cost == rhs.cost &&
				this->quantity == rhs.quantity);

	}

};

void sort(std::vector <item*>  & vec){
	int min;
	item* temp;
	int s= vec.size();
	for (int i=0;i<s-1;++i){
		min=i;
		for(int j=i+1;j<s;++j){
			if(*vec[j]<*vec[min]){
				min=j;
			}
		}
		temp=vec[i];
		vec[i]=vec[min];
		vec[min]=temp;
	}
}

int search(std::vector <item*> & vec,int code ){
	unsigned int i=0;
	for(;i<vec.size();++i){
		if(vec.at(i)->returncode()==code){
			break;
		}
	}
	return i;
}

int main() {
	std::vector<item*> vec;
	int ch=0;
	unsigned int a;
	while (ch<5) {
		std::cout <<"_________________________________________________________"<<std::endl
				<< "1)Add an item" << std::endl
				<< "2)Show an item"<< std::endl
				<< "3)Show all item" << std::endl
				<< "4)Sort by code" << std::endl
				<< "5)Quit" << std::endl
				<< "Enter choice: ";
		std::cin>>ch;
		std::cout<<endl;
/*		if (ch == 1) {
			item* nwitem = new item;
			nwitem->getitem();
			vec.push_back(nwitem);
		} else if (ch == 2) {
			std::cout << "Enter index: ";
			std::cin >> a;
			vec.at(a)->show();
		} else if (ch == 3) {
			for (auto& ele : vec) {
				ele->show();
				std::cout<<std::endl;
			}
		} else if (ch == 4) {
			sort(vec);
			std::cout<<"Sorted w.r.t. item code"<<std::endl;
		} else {
			vec.clear();
			break;
		}*/

		switch (ch) {
		case 1:
			{item* nwitem = new item;
			nwitem->getitem();
			vec.push_back(nwitem);
			break;}
		case 2:
			{std::cout << "Enter item code: ";
			std::cin >> a;
			a=search(vec,a);
			if(a<vec.size())
				vec.at(a)->show();
			else
				std::cout<<"Item code not available"<<std::endl;
			break;}
		case 3:
			{for (auto& ele : vec) {
				ele->show();
				std::cout << std::endl;
			}
			break;}
		case 4:
			{sort(vec);
			std::cout << "Sorted w.r.t. item code" << std::endl;
			break;}
		default:
			{vec.clear();}
		}
	}
	return 0;
}
