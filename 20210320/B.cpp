#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 5500;
int flag[maxN];
int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		int t;
		cin>>t;
		memset(flag,0,sizeof(flag));
		int loop = 2;
		int cnt = 1;
		int len = t;
		while(len > 3){
			for(int j = 0; j < t;j++){
				if(!flag[j]){
					if(cnt == loop) {flag[j] = 1;len--;cnt = 1;}
					else cnt++;
				}
			}
			if(loop == 2) loop = 3;
			else loop = 2;
			cnt = 1;
		}
		for(int j = 0; j < t;j++)
			if(!flag[j]) 
				cout<<j+1<<" ";
		cout<<endl;
	}
	return 0;
}
