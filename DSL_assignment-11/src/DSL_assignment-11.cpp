//============================================================================
// Name        : DSL_assignment-11.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

//priority queue
#include <iostream>
using namespace std;

const int MAX=15;

template <class T>
class node{
	T data;
	int score;
public:
	node():score(0){}

	node(const T& rhs,int rk):data(rhs),score(rk){}

	void get(T rd,int rs){
		data=rd;
		score=rs;
	}

	bool operator<=(node& rhs){
		return (this->score <= rhs.score);
	}

	friend ostream& operator<<(ostream& out,node<string> emit);
};

ostream& operator<<(ostream& out,node<string>  emit){
	out<<"Task name: "<<emit.data<<"\nTask score: "<<emit.score<<std::endl;
	return out;
}

template <class T>
class PQ{
	T arr[MAX];
	int front,rear;
public:
	PQ():front(-1),rear(-1){}

	int push(T& nw){
		if(rear==MAX-1){
			std::cout<<"PQ overflow!!";
			exit(1);
		}else if(rear==-1 && front==-1){
			++front;
			arr[++rear]=nw;
			return rear;
		}else{ //general condition
			int i=rear;
			while(i>=0 && arr[i]<=nw){
				arr[i+1]=arr[i];
				--i;}
			arr[i+1]=nw;
			++rear;
			return i+1;
		}
	}

	T pop(){
		if(rear==-1 && front==-1){
			std::cout<<"PQ underflow!!";
			exit(1);
		}else if(rear==front){
			rear=front=-1;
			return arr[rear];
		}else{ //front<rear
			return arr[front++];
		}
	}

	T first(){
		if(rear==-1 && front==-1){
			std::cout<<"PQ is empty";
			exit(1);
		}else{
			return arr[front];
		}
	}

	T last(){
		if (rear == -1 && front == -1) {
			std::cout << "PQ is empty";
			exit(1);
		} else {
			return arr[rear];
		}
	}

	void showall(){
		for(int i=front;i<=rear;++i){
			std::cout<<arr[i]<<std::endl;
		}
	}

	bool empty(){
		return (rear==-1 && front==-1);
	}
};

int main() {
	PQ <node<string> > pq;
	int i,j;
	std::string str;
	node <string> temp;

	while(true){
	std::cout<<"______________________________________________________________\n"
			<<"1)Enter a task\n"
			<<"2)Show all task\n"
			<<"3)Pop the topmost\n"
			<<"Enter choice: ";
	std::cin>>i;
	std::cout<<std::endl;
	if(i==1){
		std::cout<<"Enter task name: ";
		cin.ignore();
		std::getline(cin,str);
		std::cout<<"Enter task priority: ";
		std::cin>>j;
		temp.get(str,j);
		pq.push(temp);
	}else if(i==2){
		pq.showall();
	}else if(i==3){
		std::cout<<"Following Task was popped:\n"<<pq.pop();
	}else{
		break;
	}
	}
	return 0;
}
