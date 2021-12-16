#include<stdio.h>
/*
参考算法笔记P76，浮点数的比较和pi的定义
 
*/ 
const double eps = 1e-8;//误差范围10的负八次方 
const double Pi = acos(-1.0);//pi

#define Equ(a,b) ((fabs((a)-(b)))<(eps))//两浮点数相等
#define More(a,b) (((a)-(b))>(eps))//a>b
#define Less(a,b) (((a)-(b))<(-eps))//a<b
#define MoreEqu(a,b) (((a)-(b))>(-eps))//a>=b
#define LessEqu(a,b) (((a)-(b))<(eps))//a<=b 
int main(){

	return 0;
}

