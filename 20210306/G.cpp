#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 1100;
int prefix[maxN];
int arr[maxN];
int main(){
	int t;
	cin>>t;
	for(int i = 0;i < t;i++){
		memset(prefix,0,sizeof(prefix));
		memset(arr,0,sizeof(arr));
		int n,p;
		cin>>n>>p;
		for(int j = 0;j < n;j++)
			cin>>arr[j];
		prefix[0] = arr[0];
		for(int j = 1;j < n;j++)
			prefix[j] = prefix[j-1]+arr[j];
		int num = 0;
		for(int b = 0;b < n;b++)
			for(int e = b;e < n;e++){
				if(!b){
					if(prefix[e] == p)
						num++;
				}
				else{
					if(prefix[e]-prefix[b-1] == p)
						num++;
				}
			}
		cout<<num<<endl;
	}
	return 0;
}
