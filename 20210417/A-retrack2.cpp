#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 110;
int relation[maxN][maxN];
int main(){
	int n,m;
	while(cin>>n>>m){
		memset(relation,0x3f,sizeof(relation));
		for(int i = 0;i < m;i++){
			int x,y;
			cin>>x>>y;
			relation[x][y] = relation[y][x] = 1;
		}
		for(int i = 0;i < n;i++)
			relation[i][i] = 0;
		for(int k = 0;k < n;k++)
			for(int i = 0;i < n;i++)
				for(int j = 0;j < n;j++)
					if(relation[i][j] > relation[i][k]+relation[k][j])
						relation[i][j] = relation[i][k]+relation[k][j];
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j <n;j++)
//				cout<<relation[i][j]<<" ";
//			cout<<endl;
//		}
		bool flag = true;
		for(int i = 0;i < n&&flag;i++)
			for(int j = 0;j < n;j++)
				if(relation[i][j] > 7){
					flag = false;
					break;
				}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
