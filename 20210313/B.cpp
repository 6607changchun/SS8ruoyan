#include<iostream>
using namespace std;
int power(int r,int p){
	int result = 1;
	for(int i = 0;i < p;i++)
		result *= r;
	return result;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0; i < t;i++){
		int n;
		cin>>n;
		int lastBit = n%10;
		int loopSection = n%4;
		if(!loopSection) loopSection = 4; 
//		cout<<"lb:"<<lastBit<<" ls:"<<loopSection<<endl;
		cout<<power(lastBit,loopSection)%10<<endl;
	}
//cout<<power(2,3);
	return 0;
}
