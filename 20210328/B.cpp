#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 30;
int s[maxN];
int top = 0;
int circle[maxN];
bool visit[maxN];
bool primes[] = {0,
				0,1,1,0,1,
				0,1,0,0,0,
				1,0,1,0,0,
				0,1,0,1,0,
				0,0,1,0,0,
				0,0,0,1,0,
				1,0,0,0,0,
				0,1,0,0,0};
void pr(){
	for(int i = 0;i < top - 1;i++)
		cout<<s[i]<<" ";
	cout<<s[top-1]<<endl;
}
void resolve(int index,int n){
	if(index == 1){
		circle[1] = 1;
		visit[1] = 1;
		s[top++] = 1;
		resolve(2,n);
	}
	if(index == n) {
		int begin; 
		for(int i = 2;i <= n;i++){
			if(!visit[i]){
				begin = i;
				break;
			}
		}
		circle[index] = begin;
		s[top++]=begin;
		if(primes[circle[index]+circle[index-1]]&&primes[circle[index]+circle[1]])
			pr();
		s[--top] = 0;
		circle[index] = 0;
		return;
	}
	for(int i = 2;i <= n;i++){
		if(!visit[i]){
			circle[index] = i;
			s[top++] = i;
			visit[i] = 1;
			if(primes[circle[index]+circle[index-1]])
				resolve(index+1,n);
			visit[i] = 0;
			circle[index] = 0;
			s[--top] = 0;
		}
	}
}
int main(){
	int n,cnt;
	cnt = 1;
	while(cin>>n){
		memset(s,0,sizeof(s));
		memset(circle,0,sizeof(circle));
		memset(visit,0,sizeof(visit));
		top = 0;
		cout<<"Case "<<cnt<<":\n";
		if(n == 1) {cout<<"1\n"<<endl;cnt++;continue;}
		if(n % 2){
			cout<<endl;
			cnt++;
			continue;
		}
		resolve(1,n);
		cout<<endl;
		cnt++;
	}
	return 0;
}
