#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 1100;
int num[maxN];
void setup(){
	memset(num,0,sizeof(num));
	for(int i = 100;i <= 999; i++)
		if(i == (i/100) * (i/100) * (i/100) + ((i/10)%10) * ((i/10)%10) * ((i/10)%10) + (i%10) * (i%10) * (i%10))
			num[i] = 1;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	setup();
	int n,m;
	while(cin>>n>>m){
		int count = 0;
		for(int i = n; i <= m;i++){
			//cout<<"i:"<<i<<" num[i]:"<<num[i]<<endl;
			if(num[i]){
				cout<<i<<" ";
				count++;
			}
		}
		if(count == 0) cout<<"no";
		cout<<endl;
	}
	return 0;
}
