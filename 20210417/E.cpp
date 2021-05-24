#include<iostream>
#include<cstring> 
#include<algorithm>
#include<cstring>
using namespace std;
const int maxN = 20;
const int maxM = 20;
struct edge{
	int from;
	int to;
	int next;
}e[maxM];
int head[maxN],edgenum;
void add(int from, int to){
	edgenum++;
	e[edgenum].from = from;
	e[edgenum].to = to;
	e[edgenum].next = head[from];
	head[from] = edgenum;
}
int stack[maxN];
int top = 0;
void push(int x){
	stack[top++] = x;
}
int pop(){
	int result = stack[--top];
	stack[top] = 0;
	return result;
}
inline bool isEmpty(){
	return !top?true:false;
}
void print(){
	for(int i = 0;i < top;i++)
		cout<<stack[i]<<" ";
	cout<<endl;
}
bool visit[maxN];
int tempedge[maxM];
void route(int node,int n){
	if(visit[node]) return;
	push(node);
	if(node == n) {print();pop();return;}
	int tempedge[maxN];
	visit[node] = true;
	int i = 0;
	for(int j = head[node];j;j = e[j].next){
		tempedge[i++] = e[j].to; 
	}
	sort(tempedge,tempedge+i);
	for(int j = 0;j < i;j++)
		route(tempedge[j],n);
	visit[node] = false;
	pop();
}
int main(){
	memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));
	memset(stack,0,sizeof(stack));
	memset(visit,0,sizeof(visit));
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < m;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	route(1,n);
	return 0;
} 
