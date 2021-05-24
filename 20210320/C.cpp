#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int maxN = 1100;
stack<int> myStack;
int req[maxN];
int state[maxN];//0Î´ÈëÕ»£¬1ÈëÕ»£¬2³öÕ»
int main(){
	int r;
	cin>>r;
	while(r){
		while(true){
			memset(state,0,sizeof(state));
			memset(req,0,sizeof(req));
			bool flag = true;
			for(int i = 0; i < r;i++){
				int x;
				cin>>x;
//				cout<<"x:"<<x<<endl;
				if(!x) goto loop;
				req[i] = x;
			}
			for(int i = 0; i < r;i++){
				int pending = req[i];
//				cout<<"pending:"<<pending<<" state:"<<state[pending];
				if(state[pending] == 1){
					if(pending == myStack.top()){
//						cout<<" top:"<<myStack.top()<<endl;
						myStack.pop();
						state[pending] = 2;
					}
					else{
						flag = false;
						break;
					}
				}
				else if(state[pending] == 2){
					flag = false;
					break;
				}
				else if(state[pending] == 0){
					for(int k = 1;k < pending;k++){
						if(state[k] == 0){
						myStack.push(k);
						state[k] = 1;}
					}
					state[pending] = 2;
				}
			}
			if(flag) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		loop:cout<<endl;
		cin>>r;
	}
	return 0;
}
