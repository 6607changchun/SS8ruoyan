#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	string s;
	int times;
	cin>>times;
	for(int i = 0;i < times;i++){
		cin>>s;
		char m = s[0];
		for(int i = 1;i < s.length();i++)
			m = (m >= s[i]) ? m : s[i];
		for(int i = 0;i < s.length();i++){
			cout<<s[i];
			if(m == s[i]) cout<<"(max)";
		}
		cout<<endl;
	}
}
