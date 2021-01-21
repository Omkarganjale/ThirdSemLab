//============================================================================
// Name        : DSL_assignment-9.cpp
// Author      : OGan
// Version     :
// Copyright   : Free to use.
// Description : Hello World in C++, Ansi-style
//============================================================================

//infix to postfix
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

string infixToPostfix(string& s)
{
    stack <char> st;
    char c;
    st.push('\0');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++)
    {


        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        	{ns+=s[i];}

        //scanned character is an ‘(‘
        else if(s[i] == '(')
        	st.push('(');

        // scanned character is an ‘)’,
        else if(s[i] == ')')
        {
            while(st.top() != '\0' && st.top() != '(')
            {
                c = st.top();
                st.pop();
                ns += c;
            }
            if(st.top() == '(')
            {
                c = st.top();
                st.pop();
            }
        }

        //operator is scanned
        else{
            while(st.top() != '\0' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }

    }

    while(st.top() != '\0')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }

    return ns;

}

int chartoint(char ch){
	switch (ch){
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	}
}

int evaluate(string str){
	std::cout<<__LINE__<<std::endl;
	//char* t;
	unsigned int ch;
	int op1,op2;
	stack<int> stk;
	for(ch=0;ch<str.size();++ch){
		switch (str[ch]) {
		case '+': std::cout<<__LINE__<<std::endl;
			op1 = chartoint(stk.top()); //chartoint(stk.top())
			stk.pop();
			std::cout<<__LINE__<<std::endl;
			op2 = chartoint(stk.top());
			stk.pop();
			stk.push(op2 + op1);
			break;
		case '-':  std::cout<<__LINE__<<std::endl;
			op1 = chartoint(stk.top());
			stk.pop();
			op2 = chartoint(stk.top());
			stk.pop();
			stk.push(op2 - op1);
			break;
		case '*':  std::cout<<__LINE__<<std::endl;
			op1 = chartoint(stk.top());
			stk.pop();
			op2 = chartoint(stk.top());
			stk.pop();
			stk.push(op2 * op1);
			break;
		case '/':  std::cout<<__LINE__<<std::endl;
			op1 = chartoint(stk.top());
			stk.pop();
			op2 = chartoint(stk.top());
			stk.pop();
			stk.push(op2 / op1);
			break;
		default:  std::cout<<__LINE__<<std::endl;
			//t=str[ch];
			//op1=atoi(t);
			stk.push(chartoint(str[ch]));
		}
	}
	std::cout<<__LINE__<<std::endl;
	return stk.top();
}

int main() {
	string str;
	cout<<"Enter equation: ";
	//cin.ignore();
	cin>>str;
	str=infixToPostfix(str);
	cout<<str<<endl;

	cout<<"Result : "<<evaluate(str);
	return 0;
}
