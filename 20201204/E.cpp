#include<iostream>
#include<cmath>
#include<cstring>
const int maxN = 1100;
int result[maxN];
using namespace std;
int getSum(int num,int n){
	int sum = 0;
	int i = 1;
	for(;i*i < num || i <= n;i++){
		if(!(num%i)){
			result[i] = 0;
			sum += i+num/i;
			}
		if(i*i == sum)
			sum -= i;
	}
	sum -= num;
	if(i > n) return -1;
	return sum;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	for(int i = 1;i < 1050;i++)
		result[i] = -1;
	int t;
	cin>>t;
	for(int i = 0;i < t;i++){
		int n;
		cin>>n;
		bool flag = true;
		if(result[n] != -1){
			if(result[n])
				cout<<"yes"<<endl;
			else 
				cout<<"no"<<endl;
			continue;
		}
		
		for(int j = 1;j <= n*n;j++){
			//cout<<"j:"<<j<<" sum:"<<getSum(j)<<endl;
			if(getSum(j,n) == n){
				result[n] = 0;
				flag = false;
				break;
			}
		}
		if(flag){
			result[n] = 1;
			cout<<"yes"<<endl;
			}
		else 
			cout<<"no"<<endl;
	}
	return 0;
}
