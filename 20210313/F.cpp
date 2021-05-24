#include<iostream>
#include<cstring>
#include<algorithm>
//#include "windows.h"
using namespace std;
const int maxN = 1100;
int num[maxN];
int findNum(int target,int n,int op1,int op2){
//	cout<<"i:"<<op1<<" j:"<<op2<<endl;
	int low = 0;
	int high = n;
	while(low < high){
		int mid = (low+high)>>1;
		if(num[mid] < target) 
			low = mid+1;
		else if (num[mid] > target)
			high = mid-1;
		else 
			{
				if(mid == op1||mid == op2)
					return -1;
				return mid;
			}
	}
//	cout<<"low:"<<low<<endl;
	if(num[low] == target && low != op1 && low != op2) 
		return low;
	else 
		return -1;
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
		for(int j = i-1;j >= 0;j--)
			if(findNum(num[i]-num[j],n,i,j)!=-1){
				count++;break;}	
	cout<<count<<endl;
	return 0;
}
