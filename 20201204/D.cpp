#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char inp[55];
int flag[10];
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	scanf("%d\n",&n);
	for(int i = 0; i < n;i++){
		memset(flag,0,sizeof(flag));
		scanf("%s\n",inp);
		int index = 0;
		while(inp[index] != '\0'){
			if(inp[index] >= 'A' && inp[index] <= 'Z')
				flag[1] = 1;
			else if(inp[index] >= 'a' && inp[index] <= 'z')
				flag[2] = 1;
			else if(inp[index] >= '0' && inp[index] <= '9')
				flag[3] = 1;
			else if(inp[index] == '~' || inp[index] == '!' || inp[index] == '@' || inp[index] == '#' || inp[index] == '$' || inp[index] == '%' || inp[index] == '^')
				flag[4] = 1;
			index++;
		}
		if(index < 8 || index > 16) {cout<<"NO"<<endl;continue;}
		if(flag[1] + flag[2] + flag[3] + flag[4] >= 3)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
