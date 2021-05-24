#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
const int maxN = 550;
const int maxM = maxN * maxN;
struct edge{
	int from;
	int to;
	int val;
}e[maxM];
int edgenum;
void add(int from, int to,int val){
	edgenum++;
	e[edgenum].val = val;
	e[edgenum].from = from;
	e[edgenum].to = to;
}
int father[maxN];
int findfather(int x){
	return father[x]==x?x:father[x]=findfather(father[x]);
}
bool cmp(const edge& a, const edge& b){
	return a.val > b.val;
}
using namespace std;
int main(){
//	freopen("C.in","r",stdin);
	memset(e,0,sizeof(e));
	memset(father,0,sizeof(father));
	edgenum = 0;
	int n,m;
	while(cin>>n>>m){
		for(int i = 1;i <= m;i++){
				int x,y,dis;
				cin>>x>>y>>dis;
				add(x,y,dis);
			}
		sort(e+1,e+edgenum+1,cmp);
		int num = 0;
		int sum = 0;
		int start = e[1].from;
		int second = e[1].to;
		father[second] = start;
		father[start] = start;
		sum+=e[1].val;
		num++;
		for(int i = 2;i <= edgenum && num < n-1; i++){
			int s = e[i].from;
			int end = e[i].to;
			int sf = findfather(s);
			int endf = findfather(end);
			if(sf&&endf&&sf == endf) continue;
			if(sf)
				father[end] = sf;
			else{
				father[end] = end;
				father[s] = endf;
				}
			sum+=e[i].val;
			num++;
		}
		if(num == n-1)
			cout<<sum<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
