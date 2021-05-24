#include<iostream>
int cards[] = {0,4,4,4,4,4,4,4,4,4,4,4,4,4};
int main(){
	int t;
	std::cin>>t;
	for(int i = 0;i < t;i++){
		int n;
		std::cin>>n;
		for(int j = 0;j <= 14;j++)
			cards[j] = 4;
		for(int j = 0;j < n;j++){
			int lost;
			std::cin>>lost;
			std::cin>>lost;
			cards[lost]--;
		}
		int sum = 0;
		for(int j = 1;j <= 11;j++)
			sum += cards[j]*cards[j+1]*cards[j+2];
		std::cout<<sum<<std::endl;
	}
	return 0;
}
