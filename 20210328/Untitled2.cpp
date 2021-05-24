#include<cstdio>
#include<cmath>
#include<cstring>

const int maxn = 25;
int n;
int sum; //当前放置数字的个数 
int ans[maxn]; //存放结果 
int vis[maxn]; //访问数组 
int num; //记录输入次数 
     
bool isPrime(int x){ //素数判定 
	int i,k;
    if(x==2) 
		return true;
    if(x<2||x%2==0) 
		return 0;
    k = sqrt(x);
    for(i=3;i<=k && x%i;i+=2);
    	if(i>k)
			return 1;
    	else 
			return 0;
}

void dfs(int r){
	if(r > n){ //边界 
		if(sum == n){ //数字全被放置完毕 
			printf("%d",ans[1]); //避免尾部多一个空格 
			for(int i = 2;i <= n;i++){
				printf(" %d",ans[i]);
			}
			putchar(10);
		}
		
		return;
	}
	
	for(int i = 1;i <= n;i++){ //遍历数字序列 
		if(vis[i])
			continue;

		if(r == n){ //最后一个需要特殊对待
			if(isPrime(ans[r-1]+i) && isPrime(1+i)){ //不但要和前一位相比较还要和第一位相比较 
				ans[r] = i; //记录答案 
				vis[i] = 1;
				sum++;
			
				dfs(r+1);
			
				sum--;	//重置状态 
				vis[i] = 0;
			}	
		} else if(isPrime(ans[r-1]+i)){ //其他的就只需要和前一位相比较 
			ans[r] = i;  
			vis[i] = 1;
			sum++;
			
			dfs(r+1);
			
			sum--;
			vis[i] = 0;			
		}
	}
	
}

int main(){
	//freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF){
		num++;
		ans[1] = 1; //第一步一定是1 
		vis[1] = 1;
		sum = 1;
		
		printf("Case %d:\n",num); //注意格式 
		dfs(2);
		putchar(10);
		memset(vis,0,sizeof(vis));
	}

	return 0;
}
