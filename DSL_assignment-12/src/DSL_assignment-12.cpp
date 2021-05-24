//============================================================================
// Name        : DSL_assignment-12.cpp
// Author      : Omkar Ganjale
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

//dequeue
#include <iostream>
using namespace std;

const int MAX=15;

template <class T>
class dequeue{
	int front,rear;
	T arr[MAX];
public:
	dequeue():front(-1),rear(-1){}

	int push_front(T nw){
		if(rear==MAX-1){
			std::cout<<"Dequeue overflow!";
			exit(1);
			return -1;
		}else if(front==-1 && rear==-1){
			++front;
			arr[++rear]=nw;
			return rear;
		}else if(front==0){
			++rear;
			for(int i=rear;i>=front;--i){
				arr[i+1]=arr[i];
			}
			arr[0]=nw;

			return 0;
		}else{//empty cell before front
			arr[--front]=nw;
			return front;
		}
	}

	T pop_front(){
		if(front==-1 && rear==-1){
			std::cout<<"Stack underflow!";
			exit(1);
			return arr[front++];
		}else if(front==rear){
			T temp=arr[rear];
			front=-1;
			rear=-1;
			return temp;
		}
		else{
			return arr[front++];
		}
	}

	int push_back(T nw){
		if(rear==MAX-1){
			std::cout<<"Dequeue overflow!";
			exit(1);
			return -1;
		}else if(front==-1 && rear==-1){
			++front;
			arr[++rear]=nw;
			return rear;
		}else{//empty cell before front
			arr[++rear]=nw;
			return rear;
		}
	}

	T pop_back(){
		if(front!=-1 && rear==-1){
			std::cout<<"Stack underflow!";
			exit(1);
			return arr[front++];
		}else if(front==rear){
			T temp=arr[rear];
			front=-1;
			rear=-1;
			return temp;
		}
		else{
			return arr[rear--];
		}
	}

	bool empty(){
		return (front==-1 && rear==-1);
	}

	int size(){
		return (rear-front+1);
	}

	void display(){
		for(int i=front;i<=rear;++i){
			std::cout<<arr[i]<<" ";
		}
		std::cout<<std::endl;
	}

};

int main() {
	dequeue<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
    dq.push_front(0);
	dq.push_front(12);
	dq.push_front(11);
	dq.pop_front();
	dq.pop_back();
	dq.display();
	return 0;
}
