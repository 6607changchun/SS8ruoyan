#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int maxN = 1100;
int maze[maxN][maxN];
struct stop{
	int x;
	int y;
}s[maxN];
bool isValid(int x,int y,int op){
	for(int i = 1;i < op;i++)
		if(s[i].x == x&&s[i].y == y) return false;
	return true;
}
int main(){
	int t;
	cin>>t;
	for(int times = 0;times < t;times++){
		int n;
		cin>>n;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				maze[i][j] = -1;
		for(int i = 1;i <= 2*n-2;i++){
			cin>>s[i].x;
			cin>>s[i].y;
			s[i].x--;
			s[i].y--;
		}
		queue<int> q;
		maze[0][0] = 0;
		q.push(0);
		while(!q.empty()){
			int index = q.front();
			q.pop();
			int i = index / n;
			int j = index-i*n;
			int ops = maze[i][j];
			if(i - 1 >= 0 && maze[i-1][j] == -1 && isValid(i-1,j,ops+1)){
				maze[i-1][j] = ops+1;
				q.push((i-1)*n+j);
			}
			if(i + 1 < n && maze[i+1][j] == -1 && isValid(i+1,j,ops+1)){
				maze[i+1][j] = ops+1;
				q.push((i+1)*n+j);
			}
			if(j - 1 >= 0 && maze[i][j-1] == -1 && isValid(i,j-1,ops+1)){
				maze[i][j-1] = ops+1;
				q.push(i*n+j-1);
			}
			if(j + 1 <n && maze[i][j+1] == -1 && isValid(i,j+1,ops+1)){
				maze[i][j+1] = ops+1;
				q.push(i*n+j+1);
			}
		}
		if(maze[n-1][n-1]!=-1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
