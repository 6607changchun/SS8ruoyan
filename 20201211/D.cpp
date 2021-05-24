#include<iostream>
#include<cstring>
using namespace std;
string num[1100];
int isNum[1100];
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	string tar;
	cin>>tar;
	int n;
	cin>>n;
	cin.get();
	memset(isNum,1,sizeof(isNum));
	int count = n;
	for(int i = 0;i < n;i++)
		{cin>>num[i];
		 for(int j = 0;j < 8;j++){
		 	if(tar[j] == '*') continue;
		 	if(num[i][j] != tar[j]) {isNum[i] = 0;count--;break;}
		 }
		}
	cout<<count<<endl;
	for(int i = 0;i < n;i++){
		if(isNum[i])
			cout<<num[i]<<endl;
	}
	
	return 0;
}
