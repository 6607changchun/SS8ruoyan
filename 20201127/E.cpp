#include<iostream>
#include<algorithm>
using namespace std;
const int maxN = 110;
int num[maxN];
int abstract(int a){
	return (a > 0)? a:(-1)*a;
}
void sorts(int size){
	for(int i = 0;i < size; i++)
		for(int j = i + 1;j < size;j++)
			if(abstract(num[i]) < abstract(num[j]))
				swap(num[i],num[j]);
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	cin>>n;
	while(n){
		for(int i = 0;i < n;i++)
			cin>>num[i];
		sorts(n);
		for(int i = 0;i < n;i++)
			cout<<num[i]<<" ";
		cout<<endl;
		cin>>n;
	}
	return 0;
}
