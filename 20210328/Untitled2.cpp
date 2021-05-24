#include<cstdio>
#include<cmath>
#include<cstring>

const int maxn = 25;
int n;
int sum; //��ǰ�������ֵĸ��� 
int ans[maxn]; //��Ž�� 
int vis[maxn]; //�������� 
int num; //��¼������� 
     
bool isPrime(int x){ //�����ж� 
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
	if(r > n){ //�߽� 
		if(sum == n){ //����ȫ��������� 
			printf("%d",ans[1]); //����β����һ���ո� 
			for(int i = 2;i <= n;i++){
				printf(" %d",ans[i]);
			}
			putchar(10);
		}
		
		return;
	}
	
	for(int i = 1;i <= n;i++){ //������������ 
		if(vis[i])
			continue;

		if(r == n){ //���һ����Ҫ����Դ�
			if(isPrime(ans[r-1]+i) && isPrime(1+i)){ //����Ҫ��ǰһλ��Ƚϻ�Ҫ�͵�һλ��Ƚ� 
				ans[r] = i; //��¼�� 
				vis[i] = 1;
				sum++;
			
				dfs(r+1);
			
				sum--;	//����״̬ 
				vis[i] = 0;
			}	
		} else if(isPrime(ans[r-1]+i)){ //�����ľ�ֻ��Ҫ��ǰһλ��Ƚ� 
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
		ans[1] = 1; //��һ��һ����1 
		vis[1] = 1;
		sum = 1;
		
		printf("Case %d:\n",num); //ע���ʽ 
		dfs(2);
		putchar(10);
		memset(vis,0,sizeof(vis));
	}

	return 0;
}
