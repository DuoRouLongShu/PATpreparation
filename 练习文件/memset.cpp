#include<stdio.h>
#include<string.h> 
int main(){
	int a[5] = {1,2,3,4,5};
	//��������ÿ��Ԫ�ظ�ͬ��ֵ�� �ǵü�string.h
	//memesetʹ�õ��ǰ��ֽڸ�ֵ������ÿ���ֽڸ�ͬ����ֵ 
	memset(a,0,sizeof(a));
	for(int i = 0;i<5;i++){
		printf("%d,",a[i]);
	}
	return 0;
}

