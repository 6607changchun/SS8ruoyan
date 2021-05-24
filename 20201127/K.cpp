#include<iostream>
using namespace std;
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int a,b;
	cin>>a>>b;
	while(a != 0 || b != 0){
	int result = 1;
	for(int i = 1;i <= b;i++)
		result = (result * a)%1000;
	cout<<result<<endl;
	cin>>a>>b;
	}
	return 0;
}
