#include<iostream>
bool isEven(int year){
	bool flag = false;
	if(year%400 == 0)
		flag = true;
	else if(year%4 ==0 && year%100 != 0)
		flag = true;
	return flag;
}
const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int n;
	std::cin>>n;
	for(int i = 0; i < n;i++){
		int y,m,d;
		std::cin>>y>>m>>d;
		bool flag = isEven(y);
		int sum = 0;
		for(int j = 0; j < m-1;j++){
			if(j == 1 && flag) sum += 1;
			sum += days[j];
		}
		sum += d;
		std::cout<<sum<<std::endl;
	}
	return 0;
}
