int conditional(int x,int y,int z){
	int m = (~((!x)|0x0))+1;
	return (z & m)|(y & (~m));
}
int isNonNagetive(int x){
	return !((0x1<<31)&x);
}
int isGreater(int x, int y){
	return ((x + ~(((x ^ y) >> 31) | y)) >> 31) + 1;
}
int absVal(int x){
	int m = ~(((0x1<<31)&x)>>31);
	return (x & m) | ((~x+1) & (~m));
}
int isPower2(int x){
	int m = !((!x)|(x>>31));
	int n = ~m+1;
	return n & (!(x & (x+(~0x0))));
}
unsigned float_neg(unsigned uf){
	unsigned exp = (uf>>23)&0xFF;
	unsigned frac = uf & 0xFFFFFFFF;
	if(exp == 0xFF && frac != 0) return uf;
	return uf ^ 0x80000000;
}
//和datalab上提交不一样的原因是对代码格式做了一些调整
unsigned float_i2f(int uf){
	//关于0的特判
	if(uf==0) return 0;
	//符号位处理
	unsigned sign = !!(uf>>31);
	if(uf<0) uf = ~uf+1;
	//阶码处理
	unsigned exp = 127;
	//尾数处理
	unsigned frac = uf;
	unsigned j = (32 << 3) - 1;
	//寻找尾数最高位
	while (j >= 0) {
		if ((frac >> j) & 1) j = j;
		--j;
	}
	//不会丢失精度
	if(j<23){
		frac <<= (23-j);
		exp += j;
		}
	else{
		//会丢失精度
		frac>>=(j-23);
		exp += j;
		unsigned mask = (1 << (j - 23)) - 1;
		//舍入处理
		if ((uf&mask) > (1 << (j - 24))) frac++;
		else if ((uf&mask) == 1 << (j - 24) && (frac & 1)) frac++; 
		//再次舍入
		if (frac == (1 << 24)) exp++;
		}
	//获得尾码
	frac &= 0x7FFFFF;
	return (sign<<31) + (exp<<23) + frac;
}
