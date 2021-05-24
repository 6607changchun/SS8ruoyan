#include<iostream>
#include<cstring>
using namespace std;
int balance[10] = {1,2,5,10,20,50,100};
int remain[10];
inline int minn(int a,int b){
	return (a>b)?b:a;
}
int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		int sum;
		cin>>sum;
		int count = 0;
		memset(remain,0,sizeof(remain));
		for(int j = 0;j < 7;j++){
			cin>>remain[j];
		}
		for(int j = 6;j >= 0;j--){
			int num = remain[j];
			int capacity = minn(sum/balance[j],num);
			count += capacity;
			sum -= capacity*balance[j];
		}
		if(sum) cout<<"-1"<<endl;
		else cout<<count<<endl;
	}
	return 0;
}