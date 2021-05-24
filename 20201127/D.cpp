#include<iostream>
#include<cstring>
using namespace std;
int num[105];
const int maxN = 110;
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	//cout<<"s1"<<endl;
	cin>>n;
	char raw[maxN];
	for(int i = 0;i < n;i++){
		memset(num,0,sizeof(num));
		cin.get();
		//cout<<"s"<<endl;
		cin.get(raw,1e5,'\n');
		//scanf("%s\n",raw);
		//cout<<"raw:"<<raw<<endl;
		int j = 0;
		//cout<<"0:"<<raw[0];
		while(raw[j] != '\0'){
			//cout<<"j:"<<j<<"raw[j]:"<<raw[j]<<endl;
			if(raw[j] == 'a') num[1]++;
			else if(raw[j] == 'e') num[2]++;
			else if(raw[j] == 'i') num[3]++;
			else if(raw[j] == 'o') num[4]++;
			else if(raw[j] == 'u') num[5]++;
			j++;
		}
		//cout<<"i:"<<i<<endl;
		if(i != 0) cout<<endl;
		cout<<"a:"<<num[1]<<"\ne:"<<num[2]<<"\ni:"<<num[3]<<"\no:"<<num[4]<<"\nu:"<<num[5]<<endl;
		//cout<<"i:"<<i<<endl;
	}
	return 0;
}
