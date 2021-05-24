#include<iostream>
#include<cstring>
#include<algorithm>
//#include "windows.h"
using namespace std;
const int maxN = 1100;
int num[maxN];
int findNum(int a,int b,int n){
//	cout<<"i:"<<op1<<" j:"<<op2<<endl;
	int low = 0;
	int high = n-1;
	while(low < high){
		int mid = (low+high)>>1;
		if(num[mid] + a <= b) 
			low = mid+1;
		else if (num[mid] +a > b)
			high = mid-1;
		else return mid;
	}
//	cout<<"low:"<<low<<endl;
	if(num[low] + a > b) 
		return low;
	else if(low + 1 <= n-1 && num[low+1] + a > b)
		return low+1;
	else return -1;
}
int main(){
	memset(num,0,sizeof(num));
	int n;
	cin>>n;
	for(int i = 0;i < n;i++)
		cin>>num[i];
	sort(num,num+n);
	int count = 0;
	for(int i = n-1;i >= 0;i--)
		for(int j = i-1;j >= 0;j--){
			int result = findNum(num[j],num[i],j);
			if(result != -1)
				count += j-result;
		}
	cout<<count<<endl;
	return 0;
}
