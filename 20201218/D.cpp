#include<iostream>
using namespace std;

int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	cin>>n;
	int last = n%4;
	switch(last){
		case 0:
		case 3:cout<<"0"<<endl;break;
		case 1:
		case 2:cout<<"1"<<endl;break;
	}
	return 0;
}
