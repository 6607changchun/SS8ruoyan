#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 70;
long long result[maxN];
void setup(){
	memset(result,0,sizeof(result));
	result[0] = 0;
	result[1] = 1;
	result[2] = 2;
	result[3] = 3;
	result[4] = 4;
	for(int i = 5;i < 60;i++)
		result[i] = result[i-2]+result[i-3]+result[i-4];
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	setup();
	int n;
	//cout<<"n:"<<n<<endl;
	while(n){
		cout<<result[n]<<endl;
		cin>>n;
	}
	while(cin>>n){
		if(n == 0) break;
		cout<<result[n]<<endl;	
	}
	return 0;
}
