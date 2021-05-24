//============================================================================
// Name        : OOP_assignment_1.cpp
// Author      : OGan
// Version     :
// Copyright   : free to use
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

//declaring a class named complex
class complex{

	public:
	//integer data members R and I
	int R,I;
	//default constructor with no parameters
	complex():R(0),I(0){
	}
	//parameterized constructor
	complex(int r,int i):R(r),I(i){
	}

	//overloading operator +
	complex operator+(complex b){
		complex c;
		c.R=this->R+b.R;
		c.I=this->I+b.I;
		return c;
	}

	//overloading operator -
	complex operator-(complex b){
			complex c;
			c.R=this->R-b.R;
			c.I=this->I-b.I;
			return c;
	}

	//overloading operator *
	complex operator*(complex b){
			complex c;
			c.R=(this->R*b.R)-(this->I*b.I);
			c.I=(this->R*b.I)+(this->I*b.R);
			return c;
	}

	//declaring friend & overloading operator <<
	friend ostream & operator<<(ostream & out,const complex & c );


	//declaring friend & overloading operator >>
	friend istream & operator>>(istream & in,complex & c);

};

//function to output a complex number
ostream & operator<<(ostream & out,const complex & c ){
	c.I<0?out<<"\n"<<c.R<<c.I<<"i":out<<"\n"<<c.R<<"+"<<c.I<<"i";
	return out;
}

//function to input a complex number
istream & operator>>(istream & in,complex & c){
	cout<<"Real part: ";
	in>>c.R;
	cout<<"Imaginary part: ";
	in>>c.I;
	return in;
}

//main function
int main() {
	char s;
	complex x,y,z;
	cout<<"Enter first complex number: ";
	cin>>x;                               //getting first complex number
	cout<<"Enter second complex number: ";
	cin>>y;                               //getting second complex number
	try{
	for(int i=0;i<2;i++){
	cout<<"\nEnter the operation to be performed:(+/-/*): ";
	cin>>s;                               //getting operator
	switch(s){                            //operation according to input
	case '+':
		z=x+y;
		cout<<"First complex number is:"<<x<<endl;
		cout<<"Second complex number is:"<<y<<endl;
		cout<<"Result: "<<z;
		break;
	case '-':
		z=x-y;
		cout<<"First complex number is:"<<x<<endl;
		cout<<"Second complex number is:"<<y<<endl;
		cout<<"Result: "<<z;
		break;
	case '*':
		z=x*y;
		cout<<"First complex number is:"<<x<<endl;
		cout<<"Second complex number is:"<<y<<endl;
		cout<<"Result: "<<z;
		break;
	default:
		//cout<<"NO SUCH OPERATOR WAS MENTIONED ";
		throw (string)("NO SUCH OPERATOR WAS MENTIONED");
	}               //end switch cases
	}               //end for loop
	}
	catch(string& i){
		cout<<i;
	}
	return 0;
}
