#include<iostream>
using namespace std;
const int maxN = 44;
long long result[maxN];
void setup(){
	result[1] = 1;
	result[2] = 1;
	for(int i = 3;i <= 40;i++)
		result[i] = result[i-1]+result[i-2];
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	setup();
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		int q;
		cin>>q;
		cout<<result[q]<<endl;
	}
	return 0;
}
