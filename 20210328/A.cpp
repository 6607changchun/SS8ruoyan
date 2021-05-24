#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 22;
int len[maxN];
bool visit[maxN];
int r;
bool isValid(int remainLen,int aNum,int n){
//	cout<<"remainLen:"<<remainLen<<" aNum:"<<aNum<<endl;
	if(!remainLen) {
		if(aNum == 4) return true;
		else return isValid(r,aNum+1,n);
	}
	int current = remainLen;
	for(int i = 0;i < n;i++){
		if(!visit[i] && len[i] <= remainLen){
			visit[i] = 1;
			if(!isValid(remainLen-len[i],aNum,n))
				visit[i] = 0;
			else return true;
		}
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	for(int time = 0;time < t;time++){
		memset(len,0,sizeof(len));
		memset(visit,0,sizeof(visit));
		int n;
		cin>>n;
		int suml = 0;
		for(int i = 0;i < n;i++){
			int temp;
			cin>>temp;
			len[i] = temp;
			suml += temp;
		}
		r = suml>>2;
		if((r<<2) != suml) {cout<<"no"<<endl;continue;}
		if(isValid(r,1,n)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
