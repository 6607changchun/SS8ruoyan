#include<iostream>
#include<cstring>
using namespace std;

int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	string c;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin.get();
		cin>>c;
		int province = (c[0]-'0')*10+(c[1]-'0');
		int year = (c[6]-'0')*1000+(c[7]-'0')*100+(c[8]-'0')*10+(c[9]-'0');
		int month = (c[10]-'0')*10+(c[11]-'0');
		int day = (c[12]-'0')*10+(c[13]-'0');
		cout<<"He/She is from ";
		switch(province){
			case 33:cout<<"Zhejiang";break;
			case 11:cout<<"Beijing";break;
			case 71:cout<<"Taiwan";break;
			case 81:cout<<"Hong Kong";break;
			case 82:cout<<"Macao";break;
			case 54:cout<<"Tibet";break;
			case 21:cout<<"Liaoning";break;
			case 31:cout<<"Shanghai";break;
		}
		cout<<",and his/her birthday is on "<<month<<","<<day<<","<<year<<" based on the table."<<endl;
	}
	return 0;
}
