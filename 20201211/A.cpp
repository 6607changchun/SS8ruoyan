#include<iostream>
#include<cstring>
//#include<cstdio>
using namespace std;
const int maxN = 90;
char target[maxN];
char sen[maxN];
//int times[500];
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	cin.getline(target,40);
	//cout<<target<<endl;
	while(target[0] != '#'){
		cin.getline(sen,85);
		//memset(times,0,sizeof(times));
		//scanf("%s\n",sen);
		//cout<<target<<endl;
		//cout<<sen<<endl;
		
		int indexOfTarget = 0;
		while(target[indexOfTarget] != '\0'){
			int times = 0;
			int indexOfSen = 0;
			while(sen[indexOfSen] != '\0')
				{
				 if(sen[indexOfSen] == target[indexOfTarget])
					times++;
				 indexOfSen++;
				}
			cout<<target[indexOfTarget]<<" "<<times<<endl;
			indexOfTarget++;
		}
		
		cin.getline(target,40);
	}
	return 0;
}
