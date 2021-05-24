#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxN = 220;
int floor[maxN];
int minop[maxN];
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	for(int i = 1;i <= n;i++){
		cin>>floor[i];
		minop[i] = -1;
	}
	queue<int> q;
	q.push(a);
	minop[a] = 0;
	while(!q.empty()){
		int cf = q.front();
		q.pop();
		int cop = minop[cf];
		if(cf == b) break;
		if(cf - floor[cf] > 0 && minop[cf - floor[cf]] == -1) {
			minop[cf - floor[cf]] = cop + 1;
			q.push(cf - floor[cf]);
		}
		if(cf + floor[cf] <= n && minop[cf + floor[cf]] == -1){
			minop[cf + floor[cf]] = cop+1;
			q.push(cf + floor[cf]);
		}
	}
	cout<<minop[b]<<endl;
	return 0;
}
