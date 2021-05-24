#include<iostream>
using namespace std;
int f(int x){
	return !((x&(~0x7))^0x30)|!(x^0x38)|!(x^0x39);
}
int test(int x){
	if(x >= 0x30&& x <= 0x39) return 1;
	else return 0;
} 
int main(){
	for(int i = -2147483648;i <= 2147483646;i++){
		if(test(i)!=f(i)){
			cout<<"t:"<<test(i)<<" f:"<<f(i)<<endl;
		}
	}
	if(test(2147483647)!=f(2147483647)){
			cout<<"t:"<<test(2147483647)<<" f:"<<f(2147483647)<<endl;
	}
	return 0;
}
