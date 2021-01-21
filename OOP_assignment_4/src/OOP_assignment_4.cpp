//============================================================================
// Name        : OOP_assignment_4.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>


template<class T>
class ss {
private:
	int s;
	T arr[10];
public:
	ss() :
			s(0) {
	}

	//ss(std::vector<T& rhs):arr(rhs),s(rhs.size()){}

	int size() {
		return s;
	}

	void sel(bool str = false) {

		//preparing an container

		int cs;

		std::cout << "Enter total no. of elements: ";
		std::cin >> cs;
		T vec[cs];
		std::string st;

		for (int i = 0; i < cs; i++) {
			std::cin >> vec[i];

		}

		//selection sort on container
		int min;
		T temp;
		for (int i = 0; i < cs; ++i) {
			min = cs - 1;
			for (int j = i; j < cs; j++) {
				if (vec[j] < vec[min])
					min = j;
			}
			temp = vec[min];
			vec[min] = vec[i];
			vec[i] = temp;

		}

		//displaying container
		for (int i = 0; i < cs; i++) {
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
	}
};
int main() {

	int a;
	std::cout << "1)int" << std::endl << "2)float" << std::endl << "3)char"
			<< std::endl << "4)string" << std::endl << "Enter choice no: ";
	std::cin >> a;
	if (a == 1) {
		ss<int> i;
		i.sel();
	}
	if (a == 2) {
		ss<float> f;
		f.sel();
	}
	if (a == 3) {
		ss<char> c;
		c.sel();
	}
	if (a == 4) {
		ss<std::string> s;
		s.sel();
	}
	return 0;
}
