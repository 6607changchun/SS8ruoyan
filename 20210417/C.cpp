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
int inTree[maxN];
bool cmp(const edge& a, const edge& b){
	return a.val < b.val;
}
using namespace std;
int main(){
	freopen("C.in","r",stdin);
	memset(e,0,sizeof(e));
	memset(inTree,0,sizeof(inTree));
	edgenum = 0;
	int n;
	while(cin>>n){
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++){
				int dis;
				cin>>dis;
				if(i!=j)
					add(i,j,dis);
			}
		sort(e+1,e+edgenum+1,cmp);
		int num = 0;
		int sum = 0;
		for(int i = 1;i <= edgenum && num < n-1; i++){
			int s = e[i].from;
			int end = e[i].to;
			if(inTree[s]&&inTree[end]) continue;
			if(!inTree[s]) inTree[s] = 1;
			if(!inTree[end]) inTree[end] = 1;
			sum+=e[i].val;
			num++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
