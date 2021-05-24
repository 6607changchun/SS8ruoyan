#include<iostream>
using namespace std;
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int x,y;
	bool flag = true;
	while(flag){
		flag = false;
		cin>>x>>y;
		int minx,maxx,miny,maxy;
		if(x!=0 || y!=0){
			flag = true;
			minx = maxx = x;
			miny = maxy = y;
		}
		while(x!=0 || y!=0){
			minx = (minx < x)? minx: x;
			maxx = (maxx > x)? maxx: x;
			miny = (miny < y)? miny: y;
			maxy = (maxy > y)? maxy: y;
			cin>>x>>y;
		}
		if(flag)
			cout<<minx<<" "<<miny<<" "<<maxx<<" "<<maxy<<endl;
	}
}
