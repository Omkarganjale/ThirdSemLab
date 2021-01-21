//============================================================================
// Name        : DSL_assignment_7.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include <vector>

//circular doubly linked list
template <class T>
class cd_list{

protected:

    //LISTNODE CLASS
    class l_node{
        public:
        T data;
        l_node *next;
        l_node *prev;

        l_node():next(NULL),prev(NULL)
        {

        }

        l_node(T rhs)
        :data(rhs),next(NULL),prev(NULL)
        {

        }

    };

    l_node *head;

    int cnt;

public:

    cd_list():head(NULL),cnt(0){}

    cd_list(T fill,int size=1):head(NULL),cnt(0){
    	for(int i=0;i<size;i++){
    		this->add(fill);
    	}
    }

    inline l_node* returnheadptr() const {
        return head;
    }

    inline int size() const {
        return this->cnt;
    }

    void add(const T data){

        l_node *newnode = new l_node(data);
        if(!cnt){
            //this->tail=newnode;
            this->head=newnode;
            newnode->next=head;
            newnode->prev=head;
            this->cnt++;
        }else{
            newnode->next=head;
            newnode->prev=head->prev;
            this->head->prev->next=newnode;
            this->head->prev=newnode;
            this->cnt++;
        }
    }

    void showall() const {
        l_node *n_iterator=this->head;
        //std::cout<<"Elements in cd_list are as follows: "<<std::endl;
        goto a;
        while(n_iterator!=this->head){
            a:
            std::cout<<n_iterator->data<<" ";
            n_iterator=n_iterator->next;
        }
        std::cout<<std::endl;
    }

	T& at(int a) const {
		a = a % (this->cnt);

		l_node *n_iterator = this->head;
		for (int i = 1; i <= a; i++) {
			n_iterator = n_iterator->next;
		}
		return n_iterator->data;
	}

    T& operator[](int a) const {

        a=a%(this->cnt);

        l_node *n_iterator=this->head;
        for(int i=1;i<=a;i++){
            n_iterator=n_iterator->next;
        }
        return n_iterator->data;
    }

};

class theatre:public cd_list<int>{
private:
    std::array <cd_list<int>*,10> arr;
    std::array <l_node*,10> harr;

public:
    theatre(){
    	for(int i=0;i<10;i++){
    		arr[i]=new cd_list<int>(0,7);
    		harr[i]=arr[i]->returnheadptr();
    	}
    }

    void showgrid(int a=0,int z=9) const {
    	for(int i=a;i<=z;i++){
    		arr[i]->showall();
    		//std::cout<<std::endl;
    	}
    }

    int value(int r,int c) const {
    	return arr[r]->at(c);
    }

    int book(int r, int c){
    	if(arr[r]->at(c)==1)
    		return 0;
    	else
    		return (arr[r]->at(c)=1);
    }

    int cancel(int r, int c) {
		if (arr[r]->at(c) == 0)
			return 0;
		else{
			(arr[r]->at(c) = 0);
			return 1;
		}
	}

    int book_a_slot(int a,int b,int c){
    	while(c--){
    		if(this->book(a,b)){
    			b++;
    		}else{a++;++c;
    				if(a>9){break;}
    				else{continue;}
    			//this->book(a,b);
    		}
    	}
    	return c;
    }

    ~theatre(){
    	for(int i=0;i<10;i++){
    	    delete arr[i];
    	}
    }
};

using namespace std;
int main() {
	theatre t; //array is 10*7
	int ch,r,c,s;
	while (true){
	cout<<"1)Show current bookings\n"
		<<"2)Book a seat\n"
		<<"3)Cancel a booked seat\n"
		<<"4)Book a slot\n"
		<<"5)Quit\n"
		<<"Enter choice number: ";
	cin>>ch;
	switch(ch){
	case 1:
		cout<<"\n1 represents seat is booked and 0 as unbooked\n";
		cout<<endl;
		t.showgrid();
		cout<<endl;
		break;
	case 2:
		cout<<"\nEnter row number (0-9): ";
		cin>>r;
		cout<<"Enter column number (0-6): ";
		cin>>c;
		if(t.book(r,c))
			cout<<"\nBooking successfull!!\n\n";
		else
			cout<<"\nSeat is already booked\n\n";
		break;
		case 3:
			cout << "\nEnter row number (0-9): ";
			cin >> r;
			cout << "Enter column number (0-6): ";
			cin >> c;
			if (t.cancel(r, c))
				cout << "\nCancellation successfull!!\n\n";
			else
				cout << "\nSeat is already canceled\n\n";
			break;
		case 4:
			cout<<"\nEnter starting seat no:\nRow number: ";
			cin>>r;
			cout<<"Column number: ";
			cin>>c;
			cout<<"Total no. of seats: ";
			cin>>s;
			s=t.book_a_slot(r,c,s);
			cout<<"s: "<<s<<endl;
		} //switch case
		if(ch==5) break;
	} //end while
	return 0;
}
