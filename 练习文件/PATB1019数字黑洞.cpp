#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp1(int a,int b){
	return a > b;//�Ӵ�С 
}
bool cmp2(int a,int b){
	return a < b;//��С���� 
}
int getNum(int a[]){
	//������a��ԭ��һ����
	int num=0,d=1000;
	for(int i=0;i<4;i++){//��ԭ������ 
		num += a[i] * d;
		d /= 10;
	}
	return num; 
} 
void getString(int n,int a[]){
	//����n����ÿһλ���洢������a�� 
	for(int i=0;i<4;i++){
		a[i] = n % 10;
		n /= 10;
	}
}

int main(){
	//PATB1019���ֺڶ�
	int n,max,min;
	scanf("%d",&n); 
	int a[4],n2;
	while(1){
		getString(n,a);
		sort(a,a+4,cmp1);//�Ӵ�С
		max = getNum(a); 
		sort(a,a+4,cmp2);//��С����
		min = getNum(a);
		n = max - min;
		printf("%04d - %04d = %04d\n",max,min,n);
		if (n == 0 || n == 6174){
			return 0;
		}
	} 
	return 0;
}

