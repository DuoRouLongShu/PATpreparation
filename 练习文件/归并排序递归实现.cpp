#include<stdio.h>
const int maxn = 100;
//������A��[L1,R1]��[L2,R2]����ϲ�Ϊ�������䣨�˴�L2ΪR1+1��
void merge(int A[],int L1, int R1, int L2, int R2){
	int i = L1, j = L2;//iָ��A[L1],jָ��A[L2] 
	int temp[maxn],index = 0;//temo��ʱ��źϲ�������飬indexΪ���±�
	while(i <= R1 && j <= R2){
		if (A[i] <= A[j]){	//���A[i] <=A[j] 
			temp[index++] = A[i++]; 	//��A[i]���뵽����temp�� 
		}else{		//���A[i]>A[j] 
			temp[index++] = A[j++];		//��A[j]���뵽����temp�� 
		}
	} 
	while(i <= R1) temp[index++] = A[i++];//��[L1,R1]��ʣ��Ԫ�ؼ��뵽����temp�� 
	while(j <= R2) temp[index++] = A[j++];//��[L2,R2]��ʣ��Ԫ�ؼ��뵽����temp�� 
	for(int i = 0;i < index;i++){
		A[L1+i] = temp[i];//���ϲ�������и�ֵ�ظ�����A 
	} 
} 
//��array���鵱ǰ����[left,right]���й鲢����
void mergeSort(int A[],int left,int right){
	if(left < right){	//ֻҪleft<right 
		int mid = (left+right) / 2;//ȡ[left,right]�е�
		mergeSort(A,left,mid);	//�ݹ飬����������[left,mid]�鲢���� 
		mergeSort(A,mid+1,right);	//�ݹ飬����������[mid+1,right]�鲢���� 
		merge(A,left,mid,mid+1,right);	//�������������������ϲ� 
	}
} 
int main(){
	//�鲢���򡪡��ݹ�ʵ��
	int A[10]={3,5,1,2,7,98,5,0,2,44};
	mergeSort(A,0,9);
	for(int i=0;i<10;i++){
		printf("%d ",A[i]);
	}
	return 0;
}

