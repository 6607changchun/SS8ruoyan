#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int t;
	cin>>t;
	for(int i = 0;i < t;i++){
		long long x;
		string tp;
		scanf("%lld.",&x);
		cin>>tp;
		for(int i = tp.size()-1;i>0;i--)
			{if(tp[i] >= '5') tp[i-1]++;
			//cout<<"i:"<<i<<" tp[i]:"<<tp[i]<<endl;
			}
		if(tp[0] >= '5') cout<<x+1<<endl;
		else cout<<x<<endl;
	}
	return 0;
}
