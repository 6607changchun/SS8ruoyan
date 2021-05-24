#include<iostream>
#include<cstring>
const int maxN = 35;
struct node{
	char value;
	node* left;
	node* right;
};
using namespace std;
node* rebuild(string s1,string s2){
	if(s1.empty()) return 0;
	char root = s1[0];
	int position = s2.find(root);
	node * n = new node;
	n -> value = root;
	if(position == 0) {
		n -> left = 0;
		n -> right = rebuild(s1.substr(1,s1.length()-1),s2.substr(1,s2.length()-1));
	}
	if(position == s2.length()-1) {
		n -> right = 0;
		n -> left = rebuild(s1.substr(1,s1.length()-1),s2.substr(0,s2.length()-1));
	}
	if(position != 0 && position != s2.length()-1){
		int leftTree = position;
		int rightTree = s2.length()-position-1;
		n -> left = rebuild(s1.substr(1,leftTree),s2.substr(0,leftTree));
		n -> right = rebuild(s1.substr(leftTree+1,rightTree),s2.substr(leftTree+1,rightTree));
	}
	return n;
}
void postOrder(node* root){
	if(root -> left != 0) postOrder(root -> left);
	if(root -> right != 0) postOrder(root -> right);
	char val = root -> value;
	cout<<val;
}
int main(){
	string s1,s2;
	int v = 0;
	while(cin>>s1>>s2){
		node* r = rebuild(s1,s2);
		postOrder(r);
		cout<<endl;
	}
	return 0;
}
