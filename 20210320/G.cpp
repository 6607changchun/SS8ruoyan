#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		int cnt = 0;
		for(int i = 0; i < s.length();i++){
			if(s[i] == '(') cnt++;
			else if(s[i] == ')') cnt--;
			else break;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
