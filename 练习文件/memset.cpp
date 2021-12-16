#include<stdio.h>
#include<string.h> 
int main(){
	int a[5] = {1,2,3,4,5};
	//对数组中每个元素赋同样值， 记得加string.h
	//memeset使用的是按字节赋值，即对每个字节赋同样的值 
	memset(a,0,sizeof(a));
	for(int i = 0;i<5;i++){
		printf("%d,",a[i]);
	}
	return 0;
}

