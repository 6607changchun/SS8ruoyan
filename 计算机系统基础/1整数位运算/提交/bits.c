int isAsciiDigit(int x){
	return !((x&(~0x7))^0x30)|!(x^0x38)|!(x^0x39);
}
int anyEvenBit(int x){
	return !!(x&((0x55<<24)+(0x55<<16)+(0x55<<8)+0x55));
}
int copyLSB(int x){
	return (~(x&0x1))+1;
}
int leastBitPos(int x){
	return ((~x)+1)&x;
}
int divpw2(int m,int n){
	int c = (((0x1<<31)&m)>>31)&0x1;
	return ((c<<n)+(~c)+1+m)>>n;
}
int bitCount(int x){
	//掩码设定
	int m0 = (0x55<<8)+0x55;
	int m1= (m0<<16)+m0;
	int m20 = (0x33<<8)+0x33;
	int m2 = (m20<<16)+m20;
	int m30 = (0xf<<8)+0xf;
	int m3 = (m30<<16)+m30;
	int m4 = (0xff<<16)+0xff;
	int m5 = (0xff<<8)+0xff;
	//分段统计
	int a1 = (x & m1) + ((x >> 1) & m1);//1
	int a2 = (a1&m2)+((a1>>2)&m2);//2
	int a3 = (a2&m3)+((a2>>4)&m3);//4
	int a4 = (a3&m4)+((a3>>8)&m4);//8
	int r = (a4&m5)+((a4>>16)&m5);//16和统计
	return r; 
}
