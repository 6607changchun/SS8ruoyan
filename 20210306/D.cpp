#include<iostream>
#include<cstring>
int main(){
	int sum[11];
	memset(sum,0,sizeof(sum));
	int n,k;
	std::cin>>n;
	for(int i = 0;i < n;i++){
		std::cin>>k;
		memset(sum,0,sizeof(sum));
		for(int j = 1;j <= k;j++){
			int t = j;
			//std::cout<<"t:"<<t<<std::endl;
			while(t){
				//std::cout<<"t:"<<t<<std::endl;
				sum[t%10]++;
				t /= 10;
			}
		}
		for(int j = 0;j < 10;j++){
			std::cout<<sum[j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
