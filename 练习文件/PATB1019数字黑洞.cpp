#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp1(int a,int b){
	return a > b;//从大到小 
}
bool cmp2(int a,int b){
	return a < b;//从小到大 
}
int getNum(int a[]){
	//将数组a还原成一个数
	int num=0,d=1000;
	for(int i=0;i<4;i++){//还原成整数 
		num += a[i] * d;
		d /= 10;
	}
	return num; 
} 
void getString(int n,int a[]){
	//将数n拆解成每一位，存储到数组a里 
	for(int i=0;i<4;i++){
		a[i] = n % 10;
		n /= 10;
	}
}

int main(){
	//PATB1019数字黑洞
	int n,max,min;
	scanf("%d",&n); 
	int a[4],n2;
	while(1){
		getString(n,a);
		sort(a,a+4,cmp1);//从大到小
		max = getNum(a); 
		sort(a,a+4,cmp2);//从小到大
		min = getNum(a);
		n = max - min;
		printf("%04d - %04d = %04d\n",max,min,n);
		if (n == 0 || n == 6174){
			return 0;
		}
	} 
	return 0;
}

