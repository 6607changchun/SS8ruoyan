#include<cstdio>
#include<cstring>
using namespace std;
const int maxN = 55000;
char s1[maxN],s2[maxN];
int next[maxN];
int main(){
	while(scanf("%s\n%s",s1,s2)!=EOF){
	memset(next,0,sizeof(next));
	int i = 0,j = -1;
	next[0] = -1;
	while(s2[i] != '\0'){
		if(j == -1||s2[i] == s1[j]) {i++;j++;next[i] = j;}
		else j = next[j];
	}
	if(!next[i-1]){
		printf("0\n");
	}
	else{
		int t = next[i-1];
		for(int k = 0;k <= t;k++)
			printf("%c",s1[k]);
		printf(" %d\n",t+1);
	}
	}
	return 0;
}
