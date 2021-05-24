#include<iostream>
#include<cstring>
const int maxN = 22000;
int next[maxN];
using namespace std;
int main(){
	int times;
	cin>>times;
	for(int time = 0;time < times;time++){
		string s1,s2;
		cin>>s1>>s2;
		int cnt = 0;
		memset(next,0,sizeof(next));
		int i = 0,j = -1;
		next[0] = -1;
		while(i<(int)s1.length()){
			if(j == -1||s1[i] == s1[j]) {i++;j++;next[i] = j;}
			else j = next[j];
		}
		i = 0;j = 0;
		while(i<s2.length()){
			while(i<(int)s2.length()&&j<(int)s1.length()){
			if(j == -1||s1[j] == s2[i]) {i++;j++;}
			else j = next[j];
			}
			if(j == s1.length()) {
			cnt++;
			j = next[j];
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
