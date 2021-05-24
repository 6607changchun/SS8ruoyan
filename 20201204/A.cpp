#include<iostream>
using namespace std;
int getSum(int num){
	int sum = 0;
	for(int i = 1;i < num;i++)
		if(!(num%i))
			sum += i;
	return sum;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		int a,b;
		cin>>a>>b;
		if(getSum(a) == b && getSum(b) == a)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
