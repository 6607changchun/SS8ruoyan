#include<iostream>
#include<cstring>
int main(){
	int x,y;
	int n;
	std::cin>>n;
	for(int i = 0;i < n;i++){
		x = 0;
		y = 0;
		std::cin.get();
		std::string s;
		std::cin>>s;
		int len = s.length();
//		std::cout<<"string:"<<s<<std::endl;
		for(int j = 0;j < len;j++){
			switch(s[j]){
				case 'W':
					y += 1;
					break;
				case 'D':
					y -= 1;
					break;
				case 'A':
					x -= 1;
					break;
				case 'S':
					x += 1;
					break;
			}
//			std::cout<<x<<" "<<y<<std::endl;
		}
		std::cout<<x<<" "<<y<<std::endl;
	}
	return 0;
}
