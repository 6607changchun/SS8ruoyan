#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main(){
	string s;
	int n;
	cin>>n;
	for(int i = 0;i < n; i++){
		stack<double> number;
		stack<char> sign;
		cin.get();
		cin>>s;
		for(int i = 0;i < s.length();i++){
			char c = s[i];
			if(c >= '0' && c <= '9')
				number.push(c-'0');
			else if(c == '+' || c == '-')
				sign.push(c);
			else{
				i++;
				double o2 = (double)(s[i]-'0');
				double o1 = number.top();
				number.pop();
				if(c == '*') number.push(o1*o2);
				else number.push(o1/o2);
			}
		}
		double result = 0;
		while(!sign.empty()){
			double opn = number.top();
			number.pop();
			char op = sign.top();
			sign.pop();
			if(op == '+') result += opn;
			else result -= opn;
		}
		double lastNumber = number.top();
		result += lastNumber;
		cout<<result<<endl;
	}
	return 0;
}
