#include<stdio.h>
int main(){
	//PATB1022
	int num1,num2,D,sum,z[40]={0},n=0;//����z���Q���Ƶ�ÿһλ����nΪλ�� 
	scanf("%d%d%d",&num1,&num2,&D);
	sum = num1+num2;
	do{
		z[n++] = sum % D;
		sum = sum / D;
	} while(sum != 0);
	
	for(int i=n-1;i>=0;i--){
		printf("%d",z[i]);
	}
	return 0;
}

