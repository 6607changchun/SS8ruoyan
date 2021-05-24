#include<iostream>
const int maxN = 44;
long long power2[maxN];
int main(){
	power2[0] = 1;
	for(int i = 1;i <= 42;i++)
		power2[i] = 2*power2[i-1];
	int t;
	std::cin>>t;
	for(int i = 0;i < t;i++){
		int n;
		std::cin>>n;
		std::cout<<power2[n]-1<<std::endl;
	}
	return 0;
}
