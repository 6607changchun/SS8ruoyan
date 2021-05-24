#include<iostream>
#include<cstring>
#include<queue>
#include<cstring>
using namespace std;
const int maxN = 110;
const int maxM = 220;
struct edge{
	int from;
	int to;
	int next;
}e[maxM];
int head[maxN],edgenum;
int steps[maxN][maxN];
int visit[maxM];
void add(int from,int to){
	edgenum++;
	e[edgenum].to = to;
	e[edgenum].from = from;
	e[edgenum].next = head[from];
	head[from] = edgenum;
}
int main(){
	int n,m;
	while(cin>>n>>m){
		memset(e,0,sizeof(0));
		memset(head,0,sizeof(0));
		edgenum = 0;
		for(int i = 0;i < m;i++){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				steps[i][j] = -1;
		queue<int> q;
		for(int i = 0;i < n;i++){
			memset(visit,0,sizeof(visit));
			q.push(i);
			steps[i][i] = 0;
			while(!q.empty()){
				int x = q.front();
				q.pop();
				int step = steps[i][x];
				for(int j = head[x];j&&!visit[j];j = e[j].next){
					visit[j] = 1;
					int t = e[j].to;
					if(steps[i][t]==-1){
//						printf("i:%d,t:%d,x:%d,steps:%d,step:%d\n",i,t,x,steps[i][t],step);
						steps[i][t] = step+1;
						q.push(t);
					}
				}
			}
		}
		bool flag = true;
		for(int i = 0;i < n&&flag;i++)
			for(int j = 0; j < n;j++)
				if(steps[i][j]>7){
					flag = false;
					break;
				}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++)
				cout<<steps[i][j]<<" ";
			cout<<endl;
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
