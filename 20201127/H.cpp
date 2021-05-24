#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
	if(a == b) return a;
	if(a > b) swap(a,b);
	return gcd(a,b-a);
}
int lcm(int a,int b){
	return (a/gcd(a,b))*b;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	while(cin>>n){
		int num;
		cin>>num;
		int result = num;
		for(int i = 1;i < n;i++){
			cin>>num;
			result = lcm(result,num);
		}
		cout<<result<<endl;
	}
	return 0;
}
