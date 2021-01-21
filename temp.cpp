#include <iostream>

class ghost{
public:
	void virtual func(){}
};

class A:public ghost{
private:
	int _a = 13;
public:
	int a;

	int get_a(){
		return _a;
	}

	void set_a(int rhs){
		_a=rhs;
	}

	void func() override {
		std::cout<<"Ghost from A\n";
	}

};

class B:public ghost{
private:
	int _b = 31;
public:
	int b;

	int get_b(){
		return _b;
	}

	void set_b(int rhs){
		_b=rhs;
	}

	void func() override {
		std::cout<<"Ghost from B\n";
	}
};

int main(){

	A A_obj;
	B B_obj;

	//Encapsulation
	// A_obj.a=0;
	// std::cout<<A_obj.get_a();

	//Inheritance

	//Abstraction
	// ghost g;

	//Polymorphism
	// A_obj.func();
	// B_obj.func();


	std::cout<<"----- End of program -----";


	return 0;
}