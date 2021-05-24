#include<iostream>
#include<algorithm>
using namespace std;
int s,n,m;
const int maxV = 110;
int result[maxV][maxV][maxV];
void pour(int cs,int cn,int cm,int cnt){
	int r = result[cs][cn][cm];
	if(cnt >= r) return;
	result[cs][cn][cm] = min(r,cnt);
	int pendingN = n - cn;
	int pendingM = m - cm;
	pour(cs-pendingN,n,cm,cnt+1);
	pour(cs-pendingM,cn,m,cnt+1);
	int pendingS = s - cs;
	int pendingS1 = min(pendingS,cn);
	int pendingS2 = min(pendingS,cm);
	pour(cs+pendingS1,cn-pendingS1,cm,cnt+1);
	pour(cs+pendingS2,cn,cm-pendingS2,cnt+1);
	int pendingNM = min(cn,pendingM);
	int pendingMN = min(cm,pendingN);
	pour(cs,cn-pendingNM,cm+pendingNM,cnt+1);
	pour(cs,cn+pendingMN,cm-pendingMN,cnt+1);
}
int main(){
	cin>>s>>n>>m;
	while(s!=0||n!=0||m!=0){
		for(int i = 0;i <= s;i++)
			for(int j = 0;j <= s;j++)
				for(int k = 0;k <= s;k++)
					result[i][j][k] = s*2;
		int target = s >> 1;
		if((target << 1) != s) {
			cout<<"NO"<<endl;
			cin>>s>>n>>m;
			continue;
		}
		pour(s,0,0,0);
		int sum = min(result[target][target][0],result[target][0][target]);
		if(sum == s*2) cout<<"NO"<<endl;
		else cout<<sum<<endl;
		cin>>s>>n>>m;
	}
}
