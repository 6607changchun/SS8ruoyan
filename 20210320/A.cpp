#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 11000;
int mm[maxN],nn[maxN],result[maxN];
int main(){
	int t;
	cin>>t;
	for(int times = 0;times < t;times++){
		memset(mm,0,sizeof(mm));
		memset(nn,0,sizeof(nn));
		memset(result,0,sizeof(result));
		int m,n;
		cin>>m>>n;
		for(int i = 0;i < m;i++)
			cin>>mm[i];
		for(int i = 0;i < n;i++)
			cin>>nn[i];
		int i = 0,j = 0;
		int l = 0;
		int len = m + n;
		while(l < len){
			if(i >= m){
				result[l] = nn[j];
				l++;
				j++;
				continue;
			}
			if(j >= n){
				result[l] = mm[i];
				l++;
				i++;
				continue;
			}
			if(mm[i] <= nn[j]){
				result[l] = mm[i];
				l++;
				i++;
			}
			else{
				result[l] = nn[j];
				l++;
				j++;
			}
		}
		for(int k = 0;k < len;k++)
			cout<<result[k]<<" ";
		cout<<endl; 
	}
	return 0;
}
