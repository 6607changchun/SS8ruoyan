#include<iostream>
const int maxN = 66;
long long fibo[maxN];
int main(){
	fibo[0] = 0;
	fibo[1] = 1;
	for(int i = 2;i <= 63;i++)
		fibo[i] = fibo[i-1]+fibo[i-2];
	int t;
	std::cin>>t;
	for(int i = 0; i < t;i++){
		int n;
		std::cin>>n;
		std::cout<<fibo[n]<<std::endl;
	}
	return 0;
}
