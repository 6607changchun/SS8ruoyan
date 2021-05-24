#include<iostream>
#include<cstring>
using namespace std;
int mapping[10];
int main(){
	memset(mapping,0,sizeof(mapping));
	int n;
	cin>>n;
	cin.get();
	string s;
	cin>>s;
	cin.get();
	for(int i = 1;i <= 9;i++)
		cin>>mapping[i];
	bool flag = false;
	for(int i = 0;i < n;i++){
//		cout<<"mapping:"<<mapping[(s[i]-'0')]<<" s:"<<s[i]<<endl;
		if(mapping[(s[i]-'0')] >= (s[i]-'0')){
			s[i] = mapping[(s[i]-'0')]+'0';
			flag = true;
		}
		else if(flag && mapping[(s[i]-'0')] < (s[i]-'0'))
			break;
	}
	cout<<s;
	return 0;
}
