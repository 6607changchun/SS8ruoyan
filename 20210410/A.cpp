#include<iostream>
#include<queue>
using namespace std;
const int maxN = 440;
int panel[maxN][maxN];
int n,m;
int getidx(int x,int y){
	return (x-1)*m+y;
}
int main(){
	cin>>n>>m;
	int x,y;
	cin>>x>>y;
	for(int i = 0;i < 420;i++)
		for(int j = 0;j <420;j++)
			panel[i][j] = -1;
	queue<int> q;
	q.push(getidx(x,y));
	panel[x][y] = 0;
	while(!q.empty()){
		int index = q.front();
		q.pop();
		int i = index/m + 1;
		int j = index - (i-1) * m;
		if(!j){
			i = index/m;
			j = m;
		}
		int cnt = panel[i][j];
		if(j - 2 > 0 && i - 1 > 0 && panel[i-1][j-2] == -1) 
			{panel[i-1][j-2] = cnt+1;q.push(getidx(i-1,j-2));}
		if(j - 2 > 0 && i + 1 <= n && panel[i+1][j-2] == -1)
			{panel[i+1][j-2] = cnt+1; q.push(getidx(i+1,j-2));}
		if(j - 1 > 0 && i + 2 <= n && panel[i+2][j-1] == -1)
			{panel[i+2][j-1] = cnt+1;q.push(getidx(i+2,j-1));}
		if(j + 1 <= m && i + 2 <= n && panel[i+2][j+1] == -1)
			{panel[i+2][j+1] = cnt+1;q.push(getidx(i+2,j+1));}
		if(j + 2 <= m && i + 1 <= n && panel[i+1][j+2] == -1)
			{panel[i+1][j+2] = cnt+1;q.push(getidx(i+1,j+2));}
		if(j + 2 <= m && i - 1 > 0 && panel[i-1][j+2] == -1)
			{panel[i-1][j+2] = cnt+1;q.push(getidx(i-1,j+2));}
		if(j + 1 <= m && i - 2 > 0 && panel[i-2][j+1] == -1)
			{panel[i-2][j+1] = cnt+1;q.push(getidx(i-2,j+1));}
		if(j - 1 > 0 && i - 2 > 0 && panel[i-2][j-1] == -1)
			{panel[i-2][j-1] = cnt+1;q.push(getidx(i-2,j-1));}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)
			cout<<panel[i][j]<<" ";
		cout<<endl;
	}
	return 0;		
}
