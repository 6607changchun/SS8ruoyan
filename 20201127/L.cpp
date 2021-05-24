#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxN = 1e6;
char number[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n,r;
	while(cin>>n>>r){
			bool flag = (n < 0);
			if(flag) n *= -1;
			char result[maxN] = "";
			int size = 0;
			while(n >= r){
				//printf("result:%s\n",result);
				int pending = n%r;
				n /= r;
				char pendingconcat[2] = " ";
				pendingconcat[0] = number[pending];
				strcat(result,pendingconcat);
				size++;
			}
			char pendingconcat[2] = " ";
			pendingconcat[0] = number[n];
			strcat(result,pendingconcat);
			size++;
			int j = 0;
			int k = size-1;
			while(j < k)
				{swap(result[j],result[k]);j++;k--;}
			if(flag) cout<<"-";
			printf("%s\n",result);
		//cout<<"n:"<<n<<"r:"<<r<<endl;
	}
	return 0;	
}
