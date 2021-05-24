#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int result[40];
int realr[40];
int aa[40];
int ba[40];
int par(int num,int radius,int* result){
	int n = 0;
	while(num >= radius){
		int pending = num%radius;
		*(result+n) = pending;
		num /= radius;
		n++;
	}
	*(result+n) = num;
	n++;
	return n;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int m;
	cin>>m;
	while(m){
		memset(aa,0,sizeof(aa));
		memset(ba,0,sizeof(ba));
		memset(result,0,sizeof(result));
		int a;
		int b;
		cin>>a>>b;
		//cout<<"a:"<<a<<" b:"<<b<<endl;
		int alen = par(a,m,aa);
		int blen = par(b,m,ba);
		//cout<<"alen:"<<alen<<endl;
		int minlen = (alen > blen)? blen : alen;
		int maxlen = (alen > blen)? alen:blen;
		//cout<<"minlen:"<<minlen<<endl;
		for(int i = 0;i < maxlen;i++)
			result[i] = aa[i] + ba[i];
		//cout<<"result:"<<endl;
		//for(int i = 0;i < alen+1;i++)
		//	cout<<result[i]<<" ";
	//	cout<<endl;
		for(int i = 0;i < maxlen-1;i++)
			if(result[i] >= m){
				result[i+1] += result[i]/m;
				result[i] %= m;
			}
		if(result[maxlen-1] >= m){
			result[maxlen] = result[maxlen-1]/m;
			result[maxlen-1] %= m;
			maxlen++;
		}
		for(int i = 0,j = maxlen-1;i < j;i++,j--)
			swap(result[i],result[j]);
		//cout<<"alen:"<<alen<<endl;
		//cout<<"result:"<<endl;
		//for(int i = 0;i < alen+1;i++)
		//	cout<<result[i]<<" ";
		//cout<<endl;
		
		for(int i = 0;i < maxlen;i++)
			cout<<result[i];
		cout<<endl;
		cin>>m;
	}
	return 0;
}

