#include<iostream>
using namespace std;
const int maxN = 33;
long long num[maxN];
void setup(){
	num[1] = 4;
	for(int i = 2;i<=30;i++)
		num[i] = (num[i-1]-1)*2;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	setup();
	int n;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		int toll;
		cin>>toll;
		cout<<num[toll]<<endl;
	}
	return 0;
}
