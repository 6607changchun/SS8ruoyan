#include<iostream>
#include<cstring>
using namespace std;

int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int t;
	string record;
	cin>>t;
	for(int i = 0;i < t;i++){
		cin.get();
		cin>>record;
		int l,a;
		l = 0;
		a = 0;
		bool flag = true;
		//cout<<record;
		for(int j = 0;j < record.size();j++){
			//cout<<l<<" "<<a<<" "<<endl;
			if(record[j] == 'L') l++;
			else if(record[j] == 'A') {a++;l=0;}
			else l = 0;
			if(l == 3 || a == 2) {
				flag = false;
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
