//============================================================================
// Name        : DSL_assignment-8A.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <utility>
using namespace std;

bool operator<(std::pair<int,int>& lhs,std::pair<int,int>& rhs){
	return lhs.first<rhs.first;
}

//doubly linked list
template <class T>
class d_list{
    private:

    //LISTNODE CLASS
    class l_node{
        public:
        T data;
        l_node *next;
        l_node *prev;

        l_node()
        :next(NULL),prev(NULL)
        {
        }

        l_node(T rhs)
        :data(rhs),next(NULL),prev(NULL)
        {
        }

    };

    int cnt;

    l_node *head;

    l_node *tail;

    public:

    d_list():cnt(0),head(NULL),tail(NULL){}

    inline int size() const {
        return this->cnt;
    }

    inline l_node returnheadptr() const {
        return this->head;
    }

    inline l_node returntailptr() const {
        return this->tail;
    }

    int indexof(const T rhsdata) const {
        bool flag = false;
        int a;

        l_node *n_iterator=this->head;
        for (a=0;a<this->cnt;a++){
            if(n_iterator->data==rhsdata){
                flag=true;
                break;
            }

            n_iterator=n_iterator->next;
        }

        if(flag)
        return a;
        else
        return -1;
    }

    void showall() const {

        if(!(this->cnt))
        return;

        l_node *n_iterator=this->head;

        cout<<this->cnt<<" Elements in d_list are as follows: "<<endl;

        while( n_iterator->next ){
            cout<<(n_iterator->data)<<" ";
            n_iterator=n_iterator->next;
        }
        cout<<(n_iterator->data)<<endl;
    }

    void push_front(const T data){
        l_node *newnode = new l_node(data);
        newnode->next=this->head;
        this->head->prev=newnode;
        this->head=newnode;
        this->cnt++;
    }

    void push_back(const T data){

        l_node *newnode = new l_node(data);
        if(!cnt){
            this->head=newnode;
            this->tail=newnode;
            this->cnt++;
        }else{
            newnode->prev=this->tail;
            this->tail->next=newnode;
            this->tail=newnode;
            this->cnt++;
        }
    }

    void insert(const int a,const T nwdata){
        if (a>cnt) {
            cout<<"error: index out of range"<<endl;
            exit(1);
        }

        else if (a==0){   //insertion at index 0
            this->push_front(nwdata);
            return;
        }

        else if(a==this->cnt){ //insertion at last position
            this->push_back(nwdata);
            return;
        }

        //insertion at remaining indices
        l_node *n_iterator=head;
        for(int i=1;i<=a-1;i++){
            n_iterator=n_iterator->next;
        }

        l_node *newnode=new l_node(nwdata);
        newnode->next=n_iterator->next;
        newnode->prev=n_iterator;
        n_iterator->next=newnode;

        n_iterator=newnode->next;
        n_iterator->prev=newnode;
        this->cnt++;
    }

    void sinsert(const T nwdata){

        //if newdata is sequentially first in position
        if (nwdata<(this->head->data)){
            this->push_front(nwdata);
            return;
        }

        //if newdata is sequentially last in position
        if (nwdata>(this->tail->data)){
            this->push_back(nwdata);
            return;
        }

        //if newdata is not first or last sequentially
        l_node *n_iterator=this->head;

        while(n_iterator->data<nwdata ){
            n_iterator=n_iterator->next;
        }

        l_node *newnode=new l_node(nwdata);
        newnode->next=n_iterator;
        newnode->prev=n_iterator->prev;
        n_iterator->prev=newnode;

        n_iterator=newnode->prev;
        n_iterator->next=newnode;
        this->cnt++;
    }

    void del_index(const int a){

        if (a>=cnt || a<0 || this->cnt==0) {
            cout<<"error: given index or element is not present"<<endl;
            exit(1);
        }

        if (a==0){  //deletion of position 0
            this->head = this->head->next;
            delete this->head->prev;
            this->head->prev=NULL;
            this->cnt--;
            return;
        }

        if (a==cnt-1){ //delete last element
            this->tail=this->tail->prev;
            delete tail->next;
            tail->next=NULL;
            this->cnt--;
            return;
        }

        //for other indices
        l_node *n_iterator=this->head;
        for(int i=1;i<=a;i++){
            ///prev=n_iterator;
            n_iterator=n_iterator->next;
        }

        n_iterator->prev->next=n_iterator->next;
        n_iterator->next->prev=n_iterator->prev;
        delete n_iterator;
        this->cnt--;
    }

    void del_ele(const T data){
        this->del_index(indexof(data));
    }

    void popfirst(){
        this->del_index(0);
    }

    void poplast(){
        this->del_index((this->cnt)-1);
    }

    T& at(const int a){
		if (a >= cnt) {
			cout << "error: index out of range" << endl;
			exit(1);
		}

		l_node *n_iterator = this->head;
		for (int i = 1; i <= a; i++) {
			n_iterator = n_iterator->next;
		}
		return n_iterator->data;
    }

    T& operator[](const int a) const {

        if (a>=cnt) {
            cout<<"error: index out of range"<<endl;
            exit(1);
        }

        l_node *n_iterator=this->head;
        for(int i=1;i<=a;i++){
            n_iterator=n_iterator->next;
        }
        return n_iterator->data;
    }

    void clear()
    	{
    		if(!cnt)return;

    		l_node* n_iterator=head;
    		while(n_iterator->next){
    			n_iterator=n_iterator->next;
    			delete n_iterator->prev;
    		}
    		delete n_iterator;
    	}

    void swap(const int ind1,const int ind2){
    	T temp=this->at(ind1);
    	this->at(ind1)=this->at(ind2);
    	this->at(ind2)=temp;
    }

    void sel_sort(){
    	int min;
		for (int i = 0; i < cnt; ++i) {
			min = cnt - 1;
			for (int j = i; j < cnt; j++) {
				if (this->at(j) < this->at(min))
					min = j;
			}
			this->swap(i,min);
    	}
    }

};

//schedule class
class schedule{
private:
	d_list<std::pair<int,int>> today;
public:

	int size() const { //total no. of slots
		return today.size();
	}

	int check(int a, int b) const { //returns 0 if it overlaps otherwise 1
		int s=today.size();
		int r=1;
		for(int i=0;i<s;++i){
			if((today[i].first<a && a<today[i].second) || (today[i].first<b && b<today[i].second) || (today[i].first<=a && b<=today[i].second)  ||  (a<today[i].first && today[i].second<b)){
				r=0;
				break;
			}
		}
		return r;

	}

	int add(int a,int b){ //returns index of newly added slot else -1
		if(a>=b){
			exit(1);
		}
		if(this->check(a,b)){
			today.push_back(make_pair(a,b));
			return today.size();
		}else{
			return -1;
		}
	}

	//problem when today[i].first<a<b<today[i].second, split up the slot in 2
	void freeup(int a,int b){

		if(this->check(a,b)==1){
			return;
		}


			int s = today.size();
			for (int i = 0; i < s; ++i) {
				if(today[i].first<a && today[i].first<b && b<today[i].second){

					today[i].second=a;
					std::cout<<__LINE__<<"l : "<<today[i].first<<"-"<<today[i].second<<std::endl;
				}else if(a<today[i].first && today[i].first<b && a<today[i].second && today[i].second<b){
					//std::cout<<__LINE__<<"l : "<<today[i].first<<"-"<<today[i].second<<std::endl;
					//std::cout<<__LINE__<<"l : above slot was deleted"<<std::endl;
					today.del_index(i);
				}else if(today[i].first<a && a<today[i].second && b<today[i].second){
					//std::cout<<__LINE__<<"l : "<<today[i].first<<"-"<<today[i].second<<std::endl;
					today[i].first=b;
					//std::cout<<__LINE__<<"l : "<<today[i].first<<"-"<<today[i].second<<std::endl;
				}else{
					continue;
				}
			}

	}

	void show() const {
		int s=today.size();
		for(int i=0;i<s;++i){
			printf("%02d : %04d - %04d \n",i,today[i].first,today[i].second);
			//std::cout<<i<<" : "<<today[i].first<<" - "<<today[i].second<<std::endl;
		}
	}

	void sort(){
		today.sel_sort();
	}

	void clear(){
		today.clear();
	}

	~schedule(){
		today.clear();
	}
};

int main() {
	//////////////////////////////////////////////////////////
//
//	schedule nov10;
//	std::cout<<nov10.add(1300,1400)<<std::endl;
//	std::cout<<nov10.add(1500,1600)<<std::endl;
//	std::cout<<nov10.add(1600,1700)<<std::endl;
//	std::cout<<nov10.add(1200,1300)<<std::endl;
//
//	nov10.show();
//	//cout<<nov10.check(1200,1500)<<endl;
//	nov10.sort();
//	//cout<<nov10.check(1200,1500)<<endl;
//	std::cout<<"updated:\n";
//	nov10.show();
//
	/////////////////////////////////////////////////////////
	int ch,a,b;
	schedule* today=new schedule;
	while(true){
		std::cout<<"\n1)Show booked appointments"<<std::endl
				<<"2)Check the status of a slot"<<std::endl
				<<"3)Freeup a slot"<<std::endl
				<<"4)Book a slot"<<std::endl
				<<"5)Sort the slots"<<std::endl
				<<"6)Clear all slots"<<std::endl
				<<"Enter choice number: ";
		std::cin>>ch;
		if(ch==1){
			today->show();
		}else if(ch==2){
			std::cout<<"Enter time in HHMM in 24hr time format"<<std::endl;
			std::cout<<"From: ";
			std::cin>>a;
			std::cout<<"To: ";
			std::cin>>b;
			if(today->check(a,b)){
				std::cout<<"Slot is free"<<std::endl;
			}else{
				std::cout<<"Slot is already occupied"<<std::endl;
			}
		}else if(ch==3){
			std::cout << "Enter time in HHMM in 24hr time format" << std::endl;
			std::cout << "From: ";
			std::cin >> a;
			std::cout << "To: ";
			std::cin >> b;
			today->freeup(a,b);
			std::cout<<"Slot is unbooked"<<std::endl;
		}else if(ch==4){
			std::cout << "Enter time in HHMM in 24hr time format" << std::endl;
			std::cout << "From: ";
			std::cin >> a;
			std::cout << "To: ";
			std::cin >> b;
			if(today->add(a,b)!=-1){
				std::cout<<"slot booked"<<std::endl;
			}else{
				std::cout<<"slot is already booked"<<std::endl;
			}
		}else if(ch==5){
			today->sort();
			std::cout<<"Slots are sorted now"<<std::endl;
		}else if(ch==6){
			today->clear();
		}else{
			break;
		}
	}
	return 0;
}
