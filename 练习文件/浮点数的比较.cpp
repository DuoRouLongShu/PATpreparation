#include<stdio.h>
/*
�ο��㷨�ʼ�P76���������ıȽϺ�pi�Ķ���
 
*/ 
const double eps = 1e-8;//��Χ10�ĸ��˴η� 
const double Pi = acos(-1.0);//pi

#define Equ(a,b) ((fabs((a)-(b)))<(eps))//�����������
#define More(a,b) (((a)-(b))>(eps))//a>b
#define Less(a,b) (((a)-(b))<(-eps))//a<b
#define MoreEqu(a,b) (((a)-(b))>(-eps))//a>=b
#define LessEqu(a,b) (((a)-(b))<(eps))//a<=b 
int main(){

	return 0;
}

