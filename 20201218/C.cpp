#include<iostream>
using namespace std;
inline long maxn(long a,long b){return (a>b)?a:b;}
inline long minn(long a,long b){return (a<b)?a:b;}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int t;
	cin>>t;
	for(int i = 0;i < t;i++){
		long ta,tb,tc;
		cin>>ta>>tb>>tc;
		long a = minn(minn(ta,tb),tc);
		long c = maxn(maxn(ta,tb),tc);
		long b = ta-a+tb-c+tc;
		long currentDis = (c-b)+(b-a)+(c-a);
		cout<<maxn(currentDis-4,0)<<endl;
	}
	return 0;
}
