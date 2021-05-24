#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
const int maxN = 440;
int cell[maxN][maxN];
int num[maxN][maxN];
int main(){
	int n,m;
	cin>>n>>m;
	memset(cell,0,sizeof(cell));
	memset(num,0,sizeof(num));
	for(int i = 0;i < n;i++){
		cin.get();
		string s;
		cin>>s;
		for(int j = 0;j < s.length();j++)
			cell[i][j] = s[j]-'0';
	}
	int cnt = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			if(num[i][j] || !cell[i][j]) continue;
			cnt++;
			queue<int> q;
			q.push(i*m+j);
			while(!q.empty()){
				int index = q.front();
				q.pop();
				int i = index / m;
				int j = index - i * m;
				num[i][j] = 1;
				if(j - 1 >= 0 && !num[i][j-1] && cell[i][j-1]) q.push(i*m+j-1);
				if(j + 1 < m && !num[i][j+1] && cell[i][j+1]) q.push(i*m+j+1);
				if(i - 1 >= 0 && !num[i-1][j] && cell[i-1][j]) q.push((i-1)*m+j);
				if(i + 1 < n && !num[i+1][j] && cell[i+1][j]) q.push((i+1)*m+j);
			}
		}
	cout<<cnt<<endl;
	return 0;
}
