#include<iostream>
#include<cstring>
#include<queue>
const int maxN = 550;
const int maxM = maxN * maxN;
struct edge{
	int from;//win
	int to;//lose
	int next;
}e[maxM];
int head[maxN],edgenum,degree[maxN],result[maxN];
void add(int from, int to){
	edgenum++;
	e[edgenum].from = from;
	e[edgenum].to = to;
	e[edgenum].next = head[from];
	head[from] = edgenum;
}
bool isValid(int from, int to){
	for(int i = 1;i < edgenum;i++)
		if(e[i].from == from&& e[i].to == to)
			return false;
	return true;
}
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	memset(head,0,sizeof(head));
	memset(e,0,sizeof(0));
	memset(degree,0,sizeof(degree));
	memset(result,0,sizeof(result));
	edgenum = 0;
	for(int i = 0;i < m;i++){
		int x,y;
		cin>>x>>y;
		if(isValid(x,y)){
			add(x,y);
			degree[y]++;
		}
	}
	queue<int> q;
	for(int i = 1;i <= n;i++)
		if(!degree[i]){
			q.push(i);
			break;
		}
	int cnt = 0;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		degree[f] = -1;
		result[cnt++] = f;
		for(int j = head[f];j;j = e[j].next){
			int t = e[j].to;
			if(degree[t] > 0) degree[t]--;
		}
		for(int i = 1;i <= n;i++)
			if(!degree[i]){
				q.push(i);
				break;
			}
	}
	for(int i = 0;i < cnt-1;i++)
		cout<<result[i]<<" ";
	cout<<result[cnt-1]<<endl;
	return 0;
}
