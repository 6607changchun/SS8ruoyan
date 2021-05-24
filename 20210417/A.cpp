#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 220;
long long relation[maxN][maxN];
long long result[maxN][maxN];
inline int mins(int a, int b){
	return a<b?a:b;
}
int main(){
	int n,m;
	while(cin>>n>>m){
		memset(relation,0,sizeof(relation));
		memset(result,0,sizeof(result));
		for(int i = 0;i < m;i++){
			int x,y;
			cin>>x>>y;
			relation[x][y] = 1;
			relation[y][x] = 1;
		}
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				result[i][j] = relation[i][j];
		for(int t = 0;t < 6;t++)
			for(int k = 0;k < n;k++)
				for(int i = 0;i < n;i++)
					for(int j = 0;j < n;j++){
						if(result[i][j] == 6) continue;
						result[i][j] += result[i][k]*result[k][j];
						result[j][i]
					}
		bool flag = true;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++)
				cout<<result[i][j]<<" ";
			cout<<endl;
		}
		for(int i = 0;i < n&&flag;i++)
			for(int j = 0;j < n;j++)
				if(!result[i][j] || result[i][j] >= 8){
					flag = false;
					break;
				}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
