#include<iostream>
using namespace std;
const int maxN = 110;
int num[maxN];
void sorts(int size){
	for(int i = 0;i < size; i++)
		for(int j = i + 1;j < size;j++)
			if(num[i] > num[j])
				swap(num[i],num[j]);
}
int search(int target,int size){
	int begin = 0;
	int end = size - 1;
	while(begin <= end && begin >= 0 && end <= size-1){
		int mid = begin + ((end - begin) >> 1);
		if(num[mid] == target) return mid;
		else if(num[mid] < target) begin = mid + 1;
		else if(num[mid] > target) end = mid - 1;
	}
	return -1;
}
int del(int target,int size){
	int index = search(target,size);
	if(index == -1) return size;
	for(int i = index;i < size-1 ; i++)
		num[i] = num[i+1];
	return size-1;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n,m;
	cin>>n>>m;
	while(n != 0 || m != 0){
		if(n == 0) {cout<<"NULL"<<endl;cin>>n>>m;continue;}
		for(int i = 0 ; i < n;i++)
			cin>>num[i];
		sorts(n);
		int size = n;
		int x;
		for(int i = 0;i < m;i++){
			cin>>x;
			size = del(x,size);
		}
		if(size == 0) {cout<<"NULL"<<endl;cin>>n>>m;continue;}
		for(int i = 0;i < size;i++)
			cout<<num[i]<<" ";
		cout<<endl;
		cin>>n>>m;
	}
	return 0;
}
