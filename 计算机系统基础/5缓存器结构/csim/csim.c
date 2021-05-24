#include "cachelab.h"
#include "stdio.h"
#include "stdlib.h"
int s,E,b;//与传递参数一致
long S,B;//总组数和块大小
long s_mask,tag_mask,b_mask;//3个掩码分别获取组序号位，标记位和块偏移位
char trace_file[200];//内存记录文件path缓冲区
int time_cycle = 0;//时间序列号，随操作自增
int hit = 0;//命中数
int miss = 0;//未命中数
int eviction = 0;//驱逐块次数
//缓存行
struct line{
	int is_valid;//有效位
	long tag;//标记位
	long block_start;//起始地址，由于仅统计命中数，本元素可以忽略
	long latest_used;//时间戳，最近一次访问时间序列号
};
//缓存组
struct group{
	long index;//组序号
	struct line* lines;//包含的缓存行
};
//总缓存
struct group* cache;
void load(long addr){
	time_cycle++;
	long group_num = (addr&s_mask)>>b;
	long tag_num = (addr&tag_mask)>>(s+b);
	long offset = addr&b_mask;
	printf("%ld %ld %ld\n",group_num,tag_num,offset);
	struct group current_group = cache[group_num];
	//find if it hits
	for(int i = 0;i < E;i++){
		if(current_group.lines[i].is_valid){
			long tag = current_group.lines[i].tag;
			if(tag == tag_num){
				hit++;
				current_group.lines[i].latest_used = time_cycle;
				return;
			}
		}
	}
	//miss
	miss++;
	//fing if ther is empty page
	for(int i = 0;i < E;i++){
		if(current_group.lines[i].is_valid) continue;
		long start = addr - offset;
		current_group.lines[i].is_valid = 1;
		current_group.lines[i].tag = tag_num;
		current_group.lines[i].block_start = start;
		current_group.lines[i].latest_used = time_cycle;
		return;
	}
	//all miss
	printf("eviction\n");
	eviction++;
	//find the least recently used page;
	int min_page = 0;
	long min_time_cycle = current_group.lines[0].latest_used;
	for(int i = 1;i < E;i++){
		if(current_group.lines[i].latest_used < min_time_cycle){
			min_page = i;
			min_time_cycle = current_group.lines[i].latest_used;
		}
	}
	//evict this page
	long start = addr - offset;
	current_group.lines[min_page].tag = tag_num;
	current_group.lines[min_page].block_start = start;
	current_group.lines[min_page].latest_used = time_cycle;
}

int main(int args, char* argv[])
{
    for(int i = 1;i < args;i++)
	{
		char opt = argv[i][1];
		switch(opt){
			case 'b':
				i++;
				sscanf(argv[i],"%d",&b);
				B = 1L<<b;
				b_mask = B-1;
				break;
			case 's':
				i++;
				sscanf(argv[i],"%d",&s);
				S = 1L<<s;
				break;
			case 'E':
				i++;
				sscanf(argv[i],"%d",&E);
				break;
			case 't':
				i++;
				sscanf(argv[i],"%s",trace_file);
				break;
		}
	}
	s_mask = (S - 1) << b;
	tag_mask = -1L - b_mask - s_mask;
	FILE* trace = fopen(trace_file,"r");
	cache = (struct group*)malloc(S*sizeof(struct group));
	for(int i = 0;i < S;i++){
		cache[i].index = i;
		cache[i].lines = (struct line*)malloc(E*sizeof(struct line));
		for(int j = 0;j < E;j++){
			(cache[i].lines)[j].is_valid = 0;
			(cache[i].lines)[j].tag = 0;
			(cache[i].lines)[j].block_start = 0;
			(cache[i].lines)[j].latest_used = 0;
		}
	}
	printf("mask:%lx,%lx,%lx\n",s_mask,tag_mask,b_mask);
	char s[60];//跟踪记录缓冲区
	while(fgets(s,60,trace)!=NULL){
		if(s[0] != ' ') continue;
		char op;
		long addr;
		int len;
		sscanf(s," %c %lx,%d",&op,&addr,&len);
		//test
		printf("%c %lx,%d ",op,addr,len);
		switch(op){
			case 'L':
			case 'S':
				load(addr);
				break;
			case 'M':
				load(addr);
				load(addr);
				break;
		}
	}	

	for(int i = 0;i < S;i++){
		free(cache[i].lines);
		cache[i].lines = NULL;
	}
	free(cache);
	fclose(trace);
    printSummary(hit, miss, eviction);
    return 0;
}
