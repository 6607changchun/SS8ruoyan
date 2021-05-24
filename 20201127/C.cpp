#include<iostream>
#include<cstdio>
#include<cstring>
const int maxN = 1e6;
using namespace std;
void upper(char& c){
	if(c >= 'a' && c <= 'z')
		c -= 32;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	//cout<<"s1"<<endl;
	cin>>n;
	char raw[maxN];
	for(int i = 0;i < n;i++){
		cin.get();
		//cout<<"s"<<endl;
		cin.get(raw,1e5,'\n');
		//scanf("%s\n",raw);
		//cout<<"raw:"<<raw<<endl;
		int j = 0;
		upper(raw[j]);
		//cout<<"0:"<<raw[0];
		while(raw[j] != '\0'){
			if(raw[j] == ' ')
				upper(raw[j+1]);
			cout<<raw[j];
			j++;
		}
		cout<<endl;
		//cout<<"i:"<<i<<endl;
	}
	return 0;
}
