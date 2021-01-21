//============================================================================
// Name        : OOP_assignment_7.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fs("something.txt");
	string inp="";
	std::cout<<"Enter lines to enter in something.txt and enter -1 to end\n";
	while(true){
		std::getline(cin,inp);
		if(inp=="-1")
			break;
		fs<<inp<<endl;
	}
	//fs<<ends;
	fs.close();

	ifstream fss("something.txt");
	fss.seekg(0,ios::beg);
	//std::cout<<fss.tellg();
	std::cout<<"Reading from something.txt"<<std::endl;
	while(!fss.eof()){
		std::getline(fss,inp);
		std::cout<<inp;
	}

	fss.close();
	return 0;
}
/*
this is line 1
this is line 2
this is line 3
*/

