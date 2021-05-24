#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<string> back;
	stack<string> forward;
	string c = "http://www.acm.org/";
	string s;
	while(true){
		cin>>s;
		if(s == "QUIT") break;
		if(s == "BACK") {
			if(!back.empty()){
				forward.push(c);
				c = back.top();
				back.pop();
				cout<<c<<endl;
			}else
				cout<<"Ignored"<<endl;
		}
		if(s == "FORWARD"){
			if(!forward.empty()){
				back.push(c);
				c = forward.top();
				forward.pop();
				cout<<c<<endl;
			}else
				cout<<"Ignored"<<endl;
		}
		if(s == "VISIT"){
			back.push(c);
			cin>>c;
			cout<<c<<endl;
			while(!forward.empty())
				forward.pop();
		}
	}
	return 0;
}
