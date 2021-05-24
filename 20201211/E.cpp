#include<iostream>
#include<cstring>
using namespace std;
int chess[10][10];//1为小红，2为小明，0为未落子 
inline int abs(int x){
	return (x>=0)? x: -x;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,y;
	int count = 0;
	memset(chess,0,sizeof(chess));
	for(int i = 0;i < n + m;i++){
		cin>>x>>y;
		if(i >= n) continue;
		else chess[x+3][y+3] = 1;		
	}
	for(int i = 0;i < 7;i++){
		if(i == 3) continue;
		if(chess[i][i]&&chess[i][3]&&chess[i][6-i]) count++;
		if(chess[i][i]&&chess[3][i]&&chess[6-i][i]) count++;
	}
	if(chess[3][4]&&chess[3][5]&&chess[3][6]) {count++;}
	if(chess[3][0]&&chess[3][1]&&chess[3][2]) {count++;}
	if(chess[4][3]&&chess[5][3]&&chess[6][3]) {count++;}
	if(chess[0][3]&&chess[1][3]&&chess[2][3]) {count++;}
	cout<<count;
}

