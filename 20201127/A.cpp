#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 110;
int array[maxN];
int raw[maxN];
int search(int target,int size){
	int begin = 0;
	int end = size - 1;
	while(begin <= end && begin >= 0 && end <= size-1){
		int mid = begin + ((end - begin) >> 1);
		if(raw[mid] == target) return mid+1;
		else if(raw[mid] < target) begin = mid + 1;
		else if(raw[mid] > target) end = mid - 1;
	}
	if(end < 0) return 0;
	if(begin > size-1) return size;
	if(raw[begin] > target) return end+1;
	else return begin+1;
}
int main(){
	int n,m;
	cin>>n>>m;
	while(n != 0 || m != 0){
		if(n == 0) cout<<m<<endl;
		else{
			memset(raw,0,sizeof(raw));
			memset(array,0,sizeof(array));
			for(int i = 0;i < n;i++)
				cin>>raw[i];
			int index = search(m,n);
			//cout<<"index:"<<index<<endl;
			for(int i = 0; i < index;i++)
				array[i] = raw[i];
			array[index] = m;
			for(int i = index + 1;i <= n;i++)
				array[i] = raw[i-1];
			for(int i = 0;i <= n;i++)
				cout<<array[i]<<" ";
			cout<<endl;
		}
		cin>>n>>m;
	}
	return 0;
}
