#include<stdio.h>
#include<string.h>
int main(){
	//PATB1040 �м���PAT 
	char str[100010];
	int leftNumP[100010]={0},rightNumT[100010]={0};//leftNumPͳ��ÿһλ���P��������rightNumTͳ��ÿһλ�ұ�T������
	long long int sum=0; 
	scanf("%s",str);
	int len = strlen(str);
	if(str[0] == 'P'){//��һλ��P��leftNumP��0�±굥Ԫ��1����������ѭ������ 
		leftNumP[0]=1;
	} 
	if(str[len-1]=='T'){//ͬ���� 
		rightNumT[len-1]=1;
	}
	for(int i=1;i<len;i++){//���±�Ϊ1�Ŀ�ʼ����
		if (str[i] == 'P'){//���iΪP����leftNumP[i]�͵��� leftNumP[i-1]+1
			leftNumP[i] = leftNumP[i-1] + 1; 
		}else{//������P��leftNumP[i]�͵��� leftNumP[i-1] 
			leftNumP[i] = leftNumP[i-1];
		}
	}
	if(str[len-1] == 'A'){
		sum += rightNumT[len-1] * leftNumP[len-1];
	}
	for(int j = len-2;j>=0;j--){
		if (str[j]=='T'){
			rightNumT[j] = rightNumT[j+1] + 1;
		}else{
			rightNumT[j] = rightNumT[j+1];
		}
		if(str[j] == 'A'){
			sum += (leftNumP[j] * rightNumT[j]) ;
		}
	} 
	printf("%lld",sum% 1000000007);
	return 0;
}

