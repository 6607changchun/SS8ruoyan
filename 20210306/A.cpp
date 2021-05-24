#include<iostream>
bool isEven(int year){
	bool flag = false;
	if(year%400 == 0)
		flag = true;
	else if(year%4 ==0 && year%100 != 0)
		flag = true;
	return flag;
}
int main(){
	int n,year;
	std::cin>>n;
	for(int i = 0;i < n;i++){
		std::cin>>year;
		if(isEven(year))
			std::cout<<"Yes"<<std::endl;
		else
			std::cout<<"No"<<std::endl;
	}
	return 0;
}
