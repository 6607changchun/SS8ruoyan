#include<iostream>
using namespace std;
inline int abs(int x){
	return (x>0)?x:-x;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int l,t,ta;
	cin>>l>>t>>ta;
	int la = ta%(2*l);
	if(la > l) la = 2*l-la;
	int lb;
	if(ta <= t) lb = l;
	else lb = (l-ta+t)%(2*l);
	if(lb > l) lb = 2*l-lb;
	//cout<<"la:"<<la<<" lb:"<<lb<<endl;
	cout<<abs(la-lb);
	return 0;
}
