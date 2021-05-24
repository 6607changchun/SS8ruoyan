#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int maxN = 440;
int visit[maxN][maxN];
int maze[maxN][maxN];
int main(){
	int n,t;
	cin>>n>>t;
	memset(maze,0,sizeof(maze));
	for(int i = 0;i < n;i++){
		cin.get();
		string s;
		cin>>s;
		for(int j = 0;j < n;j++)
			maze[i][j] = s[j]-'0';
	}
	for(int times = 0;times < t;times++){
		memset(visit,0,sizeof(visit));
		int x,y;
		cin>>x>>y;
		x--;y--;
		queue<int> q;
		int cnt = 0;
		q.push(x*n+y);
		while(!q.empty()){
			int index = q.front();
			q.pop();
			int i = index / n;
			int j = index - i * n;
			int val = maze[i][j];
			if(visit[i][j])continue;
			visit[i][j] = 1;
			if(j - 1 >= 0 && !visit[i][j-1] && maze[i][j-1]!=val) q.push(i*n+j-1);
			if(j + 1 < n && !visit[i][j+1] && maze[i][j+1]!=val) q.push(i*n+j+1);
			if(i - 1 >= 0 && !visit[i-1][j] && maze[i-1][j]!=val) q.push((i-1)*n+j);
			if(i + 1 < n && !visit[i+1][j] && maze[i+1][j]!=val) q.push((i+1)*n+j);
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
