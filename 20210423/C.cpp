#include<iostream>
#include<cstring>
#include<algorithm>
const int maxK = 1.1e5;
//now the ith column is column-th column before
int* column;
int* row;
struct tree{
	int x;
	int y;
	int val;
} t[maxK];
int k;
int findval(int x, int y){
	for(int i = 0;i < k;i++)
		if(t[i].x == x && t[i].y == y)
			return t[i].val;
	return 0;
}
using namespace std;
int main(){
	int times;
	cin>>times;
	for(int time = 1;time <= times; time++){
		cout<<"Case #"<<time<<":\n";
		memset(t,0,sizeof(t));
		int n,m;
		cin>>n>>m>>k;//n*m matrix
		column = new int[n];
		row = new int[m];
		for(int i = 0;i < k;i++){
			int x,y,c;
			cin>>x>>y>>c;
			t[i].x = x;
			t[i].y = y;
			t[i].val = c;
		}
		for(int i = 1;i <= n;i++)
			column[i] = i;
		for(int i = 1;i <= m;i++)
			row[i] = i;
		int q;
		cin>>q;
		for(int i = 0;i < q;i++){
			int st,op1,op2;
			cin>>st>>op1>>op2;
			switch(st){
				case 1:
					swap(row[op1],row[op2]);
					break;
				case 2:
					swap(column[op1],column[op2]);
					break;
				case 3:
					cout<<findval(column[op1],row[op2])<<endl;
					break;
			}
		}
		delete[] column;
		delete[] row; 
	}
	return 0;
}
