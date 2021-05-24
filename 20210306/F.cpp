#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 1e6;
int next[maxN];
int KMP(string t, string p) 
{
	int i = 0; 
	int j = 0;

	while (i < (int)t.length() && j < (int)p.length())
	{
		if (j == -1||t[i] == p[j]) 
		{
			i++;
           	j++;
		}
	 	else 
           	j = next[j];
//    cout<<"j:"<<j<<endl;
//	cout<<"i:"<<i<<endl;
    }
	
    if (j == p.length())
       return i - j;
    else 
       return -1;
}
void getNext(string p)
{
	next[0] = -1;
	int i = 0, j = -1;

	while (i < p.length())
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}	
		else
			j = next[j];
	}
}
int main(){
	int t;
	cin>>t;
	string a,b;
	for(int t0 = 0;t0 < t;t0++){
		memset(next,0,sizeof(next));
		cin.get();
		cin>>a>>b;
		getNext(b);
//		for(int i = 0;i <= b.length();i++)
//			cout<<next[i]<<" ";
//		cout<<endl;
		cout<<KMP(a,b)<<endl;
	}
} 
