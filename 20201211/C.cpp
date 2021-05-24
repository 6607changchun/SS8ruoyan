#include<iostream>
#include<cstring>
using namespace std;
int num[100][50];
int main(){
	//freopen("in","r",stdin);
//	freopen("out","w",stdout);
	int n;
	cin>>n;
	for(int t = 0;t < n;t++){
		//cout<<"t:"<<t<<endl;
		memset(num,0,sizeof(num));
		string a,b;
		cin>>a>>b;
		//cout<<a<<endl;
		//cout<<b<<endl;
		int k;
		cin>>k;
		for(int i = 0;i < a.size();i++)
			num[0][a[i]-'a']++;
		for(int i = 0;i < b.size();i++)
			num[1][b[i]-'a']++;
		for(int i = 2;i <= k;i++)
			for(int j = 0;j < 25;j++)
				num[i][j] = num[i-2][j] + num[i-1][j];
		for(int j = 0;j <= 25;j++)
			cout<<(char)('a'+j)<<":"<<num[k][j]<<endl;
		cout<<endl;
		}
	}
