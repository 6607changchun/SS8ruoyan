#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class myString{
	private:
		char* value;
		int length;
	public:
		myString(){value=new char[0];length=0;}
		myString(char* buffer){
			this->length = strlen(buffer);
			value = new char[this->length+1];
			for(int i = 0;i < this->length;i++)
				value[i] = buffer[i];
			value[this->length] = 0;
		}
		~myString(){delete[] value;}
		string toString(){
			string re = value;
			return re;
		}
		myString append(char* appending){
			int len = strlen(appending)+this->length;
			char* re = new char[len+1];
			for(int i = 0;i < this->length;i++)
				re[i] = this->value[i];
			for(int i = this->length;i < len;i++)
				re[i] = appending[i-this->length];
			re[len] = 0;
			myString s(re);
			return s;
		}
		myString operator+(myString & appending){
			string app = appending.toString();
			int len = app.length() + this->length;
			char * re = new char[len+1];
			for(int i = 0;i < this->length;i++)
				re[i] = this->value[i];
			for(int i = this->length;i < len;i++)
				re[i] = app[i-this->length];
			re[len] = 0;
			myString s(re);
			return s;
		}
		friend myString preAppend(char* appending, myString str){
			int len = strlen(appending)+ str.length;
			char* re = new char[len+1];
			for(int i = 0;i < strlen(appending);i++)
				re[i] = appending[i];
			for(int i = strlen(appending);i < len;i++)
				re[i] = str.value[i-strlen(appending)];
			re[len] = 0;
			myString s(re);
			return s;
		}
};
int main(){
	myString s1,s2,s3("string class "),s4;
	char p[] = "test";
	s1 = s3.append(p);
	s2 = s1+s3;
	s4 = preAppend(p,s3);
	cout<<s1.toString()<<endl;
	cout<<s2.toString()<<endl;
	cout<<s4.toString()<<endl;
	return 0;
}
