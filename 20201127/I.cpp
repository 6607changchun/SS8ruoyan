#include<iostream>
#include<cstring>
using namespace std;
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		string s;
		cin>>s;
		int len = s.length();
		int begin = 0;
		int end = len - 1;
		bool flag = true;
		while(begin < end){
			if(s[begin] != s[end]){
				flag = false;
				break;
			}
			begin++;
			end--;
		}
		if(flag) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
