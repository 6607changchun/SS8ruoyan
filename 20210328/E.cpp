#include<iostream>
#include<cstring>
#include"Windows.h"
using namespace std;
int maze[5][5];
int steps[5][5];
int visit[5][5];
int num[5][5];
int minCnt;
bool walk(int x,int y,int cnt){
//	cout<<steps[x][y]<<endl;
	cout<<"x:"<<x<<" y:"<<y<<" cnt:"<<cnt<<endl;
	if(cnt > steps[x][y] || visit[x][y]) return false;
	visit[x][y] = 1;
	steps[x][y] = cnt;
	bool flag = false;
	if(x-1>=0 && !visit[x-1][y] && !maze[x-1][y]) {if(walk(x-1,y,cnt+1)) num[x][y] = 1,flag = true;}
	if(x+1<=4 && !visit[x+1][y] && !maze[x+1][y]) {if(walk(x+1,y,cnt+1)) num[x][y] = 1,flag = true;}
	if(y-1>=0 && !visit[x][y-1] && !maze[x][y-1]) {if(walk(x,y-1,cnt+1)) num[x][y] = 1,flag = true;}
	if(y+1<=4 && !visit[x][y+1] && !maze[x][y+1]) {if(walk(x,y+1,cnt+1)) num[x][y] = 1,flag = true;}
	cout<<"x:"<<x<<" y:"<<y<<" cnt:"<<cnt<<endl;
	cout<<num[x][y]<<endl;
	if(x == 4 && y == 4){
		num[4][4] = 1;
		return true;
	}
	if(!flag) num[x][y] = 0;
	if(!num[x][y]) {
		return false;
	}
	else return true;
}
int main(){
	for(int i = 0;i < 5;i++)
		for(int j = 0;j < 5;j++){
			cin>>maze[i][j];
			steps[i][j] = 25;
		}		
	memset(visit,0,sizeof(visit));
	memset(num,0,sizeof(num));
	num[0][0] = 1;
	visit[0][0] = 0;
	walk(0,0,0);
	int x = 0,y = 0;
	cout<<"(0, 0)"<<endl;
	memset(visit,0,sizeof(visit));
	for(int i = 0;i < 5;i++){
		for(int j = 0;j < 5;j++)
			cout<<num[i][j]<<" ";
		cout<<endl;
	}
	visit[0][0] = 1;
	while(x != 4 || y != 4){
		if(x-1>=0 && !visit[x-1][y] && num[x-1][y]) --x;
		else if(x+1<=4 && !visit[x+1][y] && num[x+1][y]) ++x;
		else if(y-1>=0 && !visit[x][y-1] && num[x][y-1]) --y;
		else if(y+1<=4 && !visit[x][y+1] && num[x][y+1]) ++y;
		visit[x][y] = 1;
		cout<<"("<<x<<" ,"<<y<<")"<<endl;
	}
	return 0;
}
