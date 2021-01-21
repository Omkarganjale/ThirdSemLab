//============================================================================
// Name        : DSL_assignment-10.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

//queue
#include <iostream>
using namespace std;

const int MAX=50;

template <class T>
class queue{
	T arr[MAX];
	int front,rear,size;
public:
	queue():front(-1),rear(-1),size(0){}

	void enqueue(T nw){
		if(rear==MAX-1){
			std::cout<<"queue overflow!!";
			exit(1);
		}else if(front==-1 && rear==-1){
			front=0;
			arr[++rear]=nw;
			++size;
		}else{
			arr[++rear]=nw;
			++size;
		}
	}

	T dequeue(){

		if(front==-1 && rear==-1){
			std::cout<<"queue empty!!";
			exit(1);
		}else if(front<rear){
			--size;
			return arr[front++];
		}else{ //front==rear
			rear=-1;
			front=-1;
			--size;
			return arr[rear];
		}

	}

	T first(){
		if(size!=0)
			return arr[front];
		else{
			std::cout<<"queue is empty!!";
			exit(1);
		}
	}

	T last(){
		if (size!=0)
			return arr[rear];
		else {
			std::cout << "queue is empty!!";
			exit(1);
		}
	}

	bool empty(){
		return (front==-1 && rear==-1);
	}

	int length(){
		return size;
	}
};

int main() {
	queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(32);
	q.enqueue(56);
	q.enqueue(99);
	q.dequeue();
	q.dequeue();
	std::cout<<"List as follows:\n";

	while(!q.empty()){
		std::cout<<q.first()<<std::endl;
		q.dequeue();
	}
	return 0;
}
