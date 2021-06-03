#include<cstdio>
#include<algorithm>
#include "BST.h"
using namespace std;
void stick(){
	int n;
	int m;
	BST b(1.1e3);
	int* num = new int[n];
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&num[i]);
	sort(num,num+n);
	for(int i = 0;i < n;i++)
		b.BSTInsert(i,num[i]);
	int ans = 0;
	for(int i = n-1;i >= 2;i--){
		for(int j = i-1;j >= 1;j--){
			int low = 0;
			int high = j - 1;
			while(low <= high){
				int mid = (low+high)>>1;
				int temp = b.Get(mid);
				int num = b.Get(i) - b.Get(j);
				if(temp > num)
					high = mid-1;
				if(temp <= num)
					low = mid+1;
			}
			ans += j - low;
		}
	}
	printf("%d\n",ans);
}
