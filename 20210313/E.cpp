#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxN = 1.1e5;
long long remain[maxN];
long long cap[maxN];
int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;i++)
		cin>>remain[i];
	for(int i = 0;i < n;i++)
		cin>>cap[i];
	long long remainAll =0;
	sort(cap,cap+n);
	for(int i = 0;i < n;i++)
		remainAll += remain[i];
//	cout<<"remain:"<<remainAll<<endl;
	long long sumAll = cap[n-1]+cap[n-2];
	if(remainAll > sumAll) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}
