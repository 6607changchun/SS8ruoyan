#include<iostream>
using namespace std;
const int maxN = 110;
int cost[maxN];
bool isValid(int n, int k,int targetCost){
	int count = 1;
	int sum = cost[0];
	for(int i = 1;i < n;i++){
		if(sum + cost[i] <= targetCost){
			sum += cost[i];
		}else{
			count++;
			sum = cost[i];
		}
	}
	if(count > k) return false;
	else return true;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i = 0;i < n;i++)
		cin>>cost[i];
	int low = cost[0];
	for(int i = 1;i < n;i++)
		if(cost[i] > low)
			low = cost[i];
	int high = 0;
	for(int i = 0;i < n;i++)
		high += cost[i];
	while(low < high){
		int mid = (low+high)>>1;
		if(!isValid(n,k,mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	if(isValid(n,k,low)) cout<<low<<endl;
	else cout<<low + 1<<endl;
	return 0;
}
