#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 1100;
int times[maxN];
int cost[maxN][2];
inline int ma(int a,int b){
	return (a>b)?a:b;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	memset(times,0,sizeof(times));
	memset(cost,0,sizeof(cost));
	int n;
	cin>>n;
	for(int i = 0;i < n;i++)
		cin>>times[i];
	cost[0][0] = 0;
	cost[0][1] = times[0];
	for(int i = 1;i < n;i++){
		cost[i][1] = ma(cost[i-1][1],cost[i-1][0]+times[i]);
		cost[i][0] = ma(cost[i-1][1],cost[i-1][0]);
	}
	cout<<ma(cost[n-1][0],cost[n-1][1]);
	return 0;
}
