#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 10;
int panel[maxN][maxN];
int row[maxN];
int line[maxN]; 
//int result[maxN][maxN][maxN];//第k棋子放在x,y坐标后的方案数 
int solution(int line,int ck,int k,int n){
//	cout<<"line:"<<line<<" ck:"<<ck<<endl;
	//即将处理第line行时要放第ck个棋子，总计k个棋子，n*n棋盘
	int sum = 0;
	if(line > n) return 0; 
	if(ck == k){
		for(int i = line;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(panel[i][j] && !row[j])
					sum++;
		return sum;
	}
	for(int i = line;i <= n;i++){
		for(int j = 1;j <= n;j++){
//			cout<<"panel:"<<panel[i][j]<<endl;
			if(!panel[i][j] || row[j]) continue;
			row[j] = 1;
			sum += solution(i+1,ck+1,k,n);
			row[j] = 0;
		}
	}
//	cout<<"line:"<<line<<" ck:"<<ck<<" sum:"<<sum<<endl;
//	cout<<"sum:"<<sum<<endl;
	return sum;
}
int main(){
	int n,k;
	cin>>n>>k;
	while(n!=-1||k!=-1){
		memset(panel,0,sizeof(panel));
		memset(row,0,sizeof(row));
		for(int i = 1;i <= n;i++){
			cin.get();
			string s;
			cin>>s;
			for(int j = 0;j < s.length();j++){
				switch(s[j]){
					case '#':
						panel[i][j+1] = 1;
						break;
					case '.':
						panel[i][j+1] = 0;
				}
//				result[1][i][j]= 1;
			}
		}
//		for(int i = 2;i <= k;i++){
//			for(int )
//		}
		cout<<solution(1,1,k,n)<<endl;
		cin>>n>>k;
	}
	return 0;
}
