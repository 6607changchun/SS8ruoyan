#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
const double ptk = 0.4536;
const double ktp = 2.2046;
const double ltg = 0.2642;
const double gtl = 3.7854;
char op[5];
int main(){
	int t;
	cin>>t;
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	for(int i = 0;i < t;i++){
		//cout<<"s\n";
		double num;
		op[0] = 'a';
		op[1] = 'a';
		scanf("%lf %s",&num,op);
		cout<<i+1<<" ";
		//cout<<"\nop:"<<op<<endl;
		cout<<setiosflags(ios::fixed)<<setprecision(4);
		if(op[0] == 'k' && op[1] == 'g')
			cout<<num * ktp<<" lb"<<endl;
		else if(op[0] == 'l' && op[1] == 'b')
			cout<<num * ptk<<" kg"<<endl;
		else if(op[0] == 'l')
			cout<<num * ltg<<" g"<<endl;
		else
			cout<<num * gtl<<" l"<<endl;
	}
	return 0;
}
