/*#include<iostream>
using namespace std;
int am[2200];
int used[2200];
void setans(){
	am[0] = 0;
	am[1] = 1;
	for(int i = 2;i < 2100;i++)
		am[i]=(1007-1007/i)*am[1007%i]%1007;
}
void ini(){
	for(int i = 0;i <= 2100;i++)
		used[i] = 0;
}
int com(int a,int b){
	if(a > b) return 0;
	int ans = 1;
	if(a*2 > b) a = b-a;
	if(a == 0) return 1;
	for(int i = 1;i <= a;i++)
		used[i] = i;
	for(int i = b;i >= b-a+1;i--)
		used[i] = i;
	for(int i = 1;i <= a;i++){
		//cout<<"i:"<<i<<" used[i]"<<used[i]<<endl;
		if(used[i]){
			for(int j = b-a+1;j <= b;j++){
				if(used[j] != 1 && used[j]%i == 0){
					used[j] = used[j]/i;
					//cout<<"j:"<<j<<" used[j]"<<used[j]<<endl;
					}
			}
		}
	}
	for(int i = b-a+1;i <= b;i++){
		//cout<<"i:"<<i<<" used[i]"<<used[i]<<endl;
		ans = (ans*used[i])%1007;
		//cout<<"s"<<ans<<endl;
		}
	/*
	int ans = 1;
	for(int i = b;i >= b-a+1;i--){
		if(i %19 ==0 || i %53 == 0) continue;
		ans = (ans*i)%1007;}
	for(int i = a;i >= 1;i--){
		if(i %19 ==0 || i %53 == 0) continue;
		ans = (ans*am[i])%1007;}
	for(int i = 53;i >= 1;i--){
		if(a >= i*19) {
			for(int i = )
		}
	
	}
	
	return ans;
} 
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	//cout<<"s\n";
	//setup();
	//setans();
	//cout<<am[53]<<endl;
	ini();
	int t;
	cin>>t;
	int m,n;
	for(int i = 0;i < t;i++){
		cin>>m>>n;
		cout<<com(m,n)<<endl;
		}
	return 0;
}
*/



