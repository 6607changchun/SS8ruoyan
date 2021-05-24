#include<iostream>
#include<queue>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i = 0;i < t;i++){
		queue<int> myQueue;
		int n,k;
		cin>>n>>k;
		for(int j = 1;j <= n;j++)
			myQueue.push(j);
		int cnt = 1;
		while(myQueue.size() > 1){
//			cout<<"front:"<<myQueue.front()<<" cnt:"<<cnt<<endl;
			if(cnt == k){
				myQueue.pop();
				cnt = 1;
			}else{
				int e = myQueue.front();
				myQueue.pop();
				myQueue.push(e);
				cnt++;
			}
		}
		cout<<"Case "<<i+1<<": "<<myQueue.front()<<endl;
	}
	return 0;
}
