//============================================================================
// Name        : DSL_assignment-8.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

//butterscotch and vanilla
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

//doubly linked list
template<class T>
class d_list {
private:

	//LISTNODE CLASS
	class l_node {
	public:
		T data;
		l_node *next;
		l_node *prev;

		l_node() :
				next(NULL), prev(NULL) {
		}

		l_node(T rhs) :
				data(rhs), next(NULL), prev(NULL) {
		}

	};

	int cnt;

	l_node *head;

	l_node *tail;

public:

	d_list():
			cnt(0), head(NULL), tail(NULL) {
	}

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

		l_node *n_iterator = this->head;
		for (a = 0; a < this->cnt; a++) {
			if (n_iterator->data == rhsdata) {
				flag = true;
				break;
			}

			n_iterator = n_iterator->next;
		}

		if (flag)
			return a;
		else
			return -1;
	}

	/*void showall() const {

		if (!(this->cnt))
			return;

		l_node *n_iterator = this->head;

		//cout << this->cnt << " Elements in d_list are as follows: " << endl;

		while (n_iterator->next) {
			std::cout << (n_iterator->data) <<" ";
			n_iterator = n_iterator->next;
		}
		std::cout << (n_iterator->data) << std::endl;
	}*/

	void push_front(const T data) {
		l_node *newnode = new l_node(data);
		newnode->next = this->head;
		this->head->prev = newnode;
		this->head = newnode;
		this->cnt++;
	}

	void push_back(const T data) {

		l_node *newnode = new l_node(data);
		if (!cnt) {
			this->head = newnode;
			this->tail = newnode;
			this->cnt++;
		} else {
			newnode->prev = this->tail;
			this->tail->next = newnode;
			this->tail = newnode;
			this->cnt++;
		}
	}

	int end_insert(const T& nw){
		//return -1,1 based on insertion at front or back or 0 if not suitable at any end no insertion
		if(this->cnt==0){
			this->push_front(nw);
			return -1;
		}else if(nw<=(head->data)){
			this->push_front(nw);
			return -1;
		}else if(nw>=(tail->data)){
			this->push_back(nw);
			return 1;
		}else return 0;
	}

	void insert(const int a, const T nwdata)
	{
		if (a > cnt) {
			cout << "error: index out of range" << endl;
			exit(1);
		}

		else if (a == 0) {   //insertion at index 0
			this->push_front(nwdata);
			return;
		}

		else if (a == this->cnt) { //insertion at last position
			this->push_back(nwdata);
			return;
		}

		//insertion at remaining indices
		l_node *n_iterator = head;
		for (int i = 1; i <= a - 1; i++) {
			n_iterator = n_iterator->next;
		}

		l_node *newnode = new l_node(nwdata);
		newnode->next = n_iterator->next;
		newnode->prev = n_iterator;
		n_iterator->next = newnode;

		n_iterator = newnode->next;
		n_iterator->prev = newnode;
		this->cnt++;
	}

	void sinsert(const T nwdata)
	{

		//if newdata is sequentially first in position
		if (nwdata < (this->head->data)) {
			this->push_front(nwdata);
			return;
		}

		//if newdata is sequentially last in position
		if (nwdata > (this->tail->data)) {
			this->push_back(nwdata);
			return;
		}

		//if newdata is not first or last sequentially
		l_node *n_iterator = this->head;

		while (n_iterator->data < nwdata) {
			n_iterator = n_iterator->next;
		}

		l_node *newnode = new l_node(nwdata);
		newnode->next = n_iterator;
		newnode->prev = n_iterator->prev;
		n_iterator->prev = newnode;

		n_iterator = newnode->prev;
		n_iterator->next = newnode;
		this->cnt++;
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

	void del_index(const int a)
	{

		if (a >= cnt || a < 0 || this->cnt == 0) {
			cout << "error: given index or element is not present" << endl;
			exit(1);
		}

		if (a == 0) {  //deletion of position 0
			this->head = this->head->next;
			delete this->head->prev;
			this->head->prev = NULL;
			this->cnt--;
			return;
		}

		if (a == cnt - 1) { //delete last element
			this->tail = this->tail->prev;
			delete tail->next;
			tail->next = NULL;
			this->cnt--;
			return;
		}

		//for other indices
		l_node *n_iterator = this->head;
		for (int i = 1; i <= a; i++) {
			///prev=n_iterator;
			n_iterator = n_iterator->next;
		}

		n_iterator->prev->next = n_iterator->next;
		n_iterator->next->prev = n_iterator->prev;
		delete n_iterator;
		this->cnt--;
	}

	void del_ele(const T data)
	{
		this->del_index(indexof(data));
	}

	void popfirst()
	{
		this->del_index(0);
	}

	void poplast()
	{
		this->del_index((this->cnt) - 1);
	}

	T& operator[](const int a) const
	{

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

};


class student{
private:
	d_list< std::pair<int,std::string> > van;
	d_list< std::pair<int,std::string> > but;

	std::vector<std::pair<int,string>> vec; //first->roll no. second->name;
public:
	student()
	{}
	~student(){
		van.clear();
		but.clear();
		vec.clear();
	}

	void addtoboth(int r,string n){
		van.push_back(make_pair(r,n));
		but.push_back(make_pair(r,n));
		vec.push_back(make_pair(r,n));
	}

	int add(){
		string n;
		int r,R=1;
		int val1,val2;
		std::cout<<"Enter name: ";
		std::cin>>n;
		std::cout<<"Enter roll no: ";
		std::cin>>r;
		std::cout<<"Enter 1 if he likes vanilla else 0: ";
		std::cin>>val1;
		std::cout<<"Enter 1 if he likes butterscotch else 0: ";
		std::cin>>val2;
		if(van.indexof(make_pair(r,n))==-1 && val1)
			van.push_back(make_pair(r,n));
		if(but.indexof(make_pair(r,n))==-1 && val2)
			but.push_back(make_pair(r,n));
		//val2=val1+val2*2;
		if(std::find(vec.cbegin(),vec.cend(),make_pair(r,n))==vec.cend() )
		{
			vec.push_back(std::pair<int,string>(r,n));
		}else{
			R=0;
		}
		return R;
	}

	void show1(int i){
		std::cout<<vec[i].first<<" "<<vec[i].second<<std::endl;
	}

	void select(int a=2,int b=2){

		if((a==0 && b==0) || (a==0 && b==2) || (a==2 && b==0)){
			for(auto& ele: vec){
				if(van.indexof(ele)==-1 && but.indexof(ele)==-1){
					std::cout<<ele.first<<" "<<ele.second<<std::endl;
				}
			}
		}
		if((a==0 && b==1) || (a==0 && b==2)|| (a==2 && b==1)){
			int bs=but.size();
			for(int i=0;i<bs;++i){
				std::cout<<but[i].first<<" "<<but[i].second<<std::endl;
			}
		}
		if((a==1 && b==0) || (a==1 && b==2) || (a==2 && b==0)){
			int vs=van.size();
			for(int i=0;i<vs;i++){
				std::cout<<van[i].first<<" "<<van[i].second<<std::endl;
			}
		}
		if((a == 1 && b == 1) || (a==1 && b==2) || (a==2 && b==1)) {
			for (auto& ele : vec) {
				if (van.indexof(ele) != -1 && but.indexof(ele) != -1) {
					std::cout << ele.first << " " << ele.second << std::endl;
				}
			}
		}

	}

	void draw(){
		std::cout<<"Registered students:\n";
		for(std::pair<int,string>& t:vec){
			std::cout<<t.first<<" "<<t.second<<std::endl;
		}
		std::cout<<"Roll no who choosed vanilla:\n";
		int vs=van.size();
					for(int i=0;i<vs;i++){
						std::cout<<van[i].first<<" "<<van[i].second<<std::endl;
					}
		std::cout<<"Roll no who choosed butterscotch:\n";
		int bs=but.size();
					for(int i=0;i<bs;++i){
						std::cout<<but[i].first<<" "<<but[i].second<<std::endl;
					}
	}
};

int main() {
	student* obj=new student;
	int ch;
	while (true){
	std::cout<<"\n===========================================================================================\n";
	std::cout<<"1)Add a student"<<std::endl
	         <<"2)show all students"<<std::endl
	         <<"3)show students who like both vanilla and butterscotch"<<std::endl
	         <<"4)show students who like either vanilla or either butterscotch or not both"<<std::endl
	         <<"5)show students who neither like vanilla nor butterscotch"<<std::endl
	         <<"6)show students with given choice"<<std::endl
			 <<"7)Quit"<<std::endl
			 <<"Enter choice: ";
	std::cin>>ch;
	if(ch==1){
	    if(obj->add()){
	        std::cout<<"Noted successfully"<<std::endl;
	    }else{
	        std::cout<<"This student was recorded previously hence not added"<<std::endl;
	    }
	}else if(ch==2){
	    obj->draw();
	}else if(ch==3){
		std::cout<<"students who like both vanilla and butterscotch"<<std::endl;
		obj->select(1,1);
	}else if(ch==4){
		std::cout<<"students who like either vanilla or either butterscotch or not both"<<std::endl;
		obj->select(1,0);
		obj->select(0,1);
	}else if(ch==5){
		std::cout<<"students who neither like vanilla nor butterscotch"<<std::endl;
		obj->select(0,0);
	}else if(ch==6){
		int a,b;
		std::cout<<"students with given choice"<<std::endl;
		std::cout<<"1-yes; 0-no; 2-don\'t know"<<std::endl;
		std::cout<<"vanilla: ";
		std::cin>>a;
		std::cout<<"butterscotch: ";
		std::cin>>b;
		obj->select(a,b);
	}else if(ch==7){
		delete obj;
		break;
	}
	}
	//obj.add();
	//obj.add();
	//obj.add();
	//obj.draw();
	return 0;
}
