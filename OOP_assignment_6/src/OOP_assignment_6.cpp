//============================================================================
// Name        : OOP_assignment_6.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

int main() {
	std::map <string,ull> mp;
	ull value;
	string key;
	std::map <string,ull>::iterator it;
	int ch=0;
	while(ch<6){
		std::cout<<"___________________________________________________________________________"<<std::endl
				<<"1)Add a state"<<std::endl
				<<"2)Show all states"<<std::endl
				<<"3)Get the population of a state"<<std::endl
				<<"4)Change population of a state"<<std::endl
				<<"5)Erase a state's data"<<std::endl
				<<"6)Quit"<<std::endl
				<<"Enter choice: ";
		std::cin>>ch;
		std::cout<<std::endl;
		switch(ch){
		case 1:
			std::cout<<"Enter state name: ";
			//std::cin>>key;
			cin.ignore();//
			std::getline(cin,key);
			std::cout<<"Enter population: ";
			std::cin>>value;
			mp[key]=value;
			break;
		case 2:
			std::cout<<"All recorded states are as follows:"<<std::endl;
			for(auto& ele:mp){
				std::cout<<ele.first<<" : "<<ele.second<<std::endl;
			}
			break;
		case 3:
			std::cout << "Enter state name: ";
			cin.ignore();
			std::getline(cin,key);
			it=mp.find(key);
			if(it!=mp.end()){
				std::cout<<it->first<<" : "<<it->second<<std::endl;
			}else{
				std::cout<<key<<"'s population data is not present!!"<<std::endl;
			}
			break;
		case 4:
			std::cout << "Enter state name: ";
			cin.ignore();
			std::getline(cin,key);
			std::cout << "Enter population: ";
			std::cin >> value;
			mp[key] = value;
			break;
		case 5:
			std::cout << "Enter state name: ";
			cin.ignore();
			std::getline(cin,key);
			mp.erase(key);
			break;
		default:
			mp.clear();
		}
	}
	return 0;
}
