#include<stdio.h>
#include<string.h>
const int maxn = 80;
int main(){
	//PATB1009
	int num=0;//���ʵĸ��� 
	char str[90][90];
	while(scanf("%s",str[num])!=EOF){
		num++;//��������һ 
	}
	//����������ʼ���
	for(int i=num-1; i>=0 ;i--){
		printf("%s",str[i]);
		if(i>0){
			printf(" ");
		}
	} 
	return 0;
}

