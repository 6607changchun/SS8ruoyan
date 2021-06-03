#include<cstdio>
#include"BST.h"
using namespace std;
void binary_search(){
	int n,q;
	scanf("%d %d",&n,&q);
	BST b(1.1e6);
	int num;
	for(int i = 0;i < n;i++){
		scanf("%d",&num);
		b.BSTInsert(i,num);
	}
	for(int i = 0;i < q;i++){
		bool flag = false;
		scanf("%d",&num);
		int low = 0;
		int high = n-1;
		while(low <= high){
			int mid = ((high-low)>>1)+low;
			int temp = b.Get(mid);
			if(temp > num)
				high = mid-1;
			if(temp == num){
				printf("%d\n",temp);
				flag = true;
				break;
			}
			if(temp < num)
				low = mid+1;
		}
		if(!flag)
			printf("%d\n",b.Get(low));
	}	
}
