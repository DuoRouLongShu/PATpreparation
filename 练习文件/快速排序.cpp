#include<stdio.h>
//������[left,right]���л��� 
int Partition(int A[], int left, int right){
	int temp = A[left];//��A[left]�������ʱ����temp
	while(left < right){//ֻҪleft��right������ 
		while(left < right && A[right] > temp) right--;//��������right
		A[left] = A[right];//��A[right]Ų��A[left]
		while(left < right && A[left] <= temp) left++;//��������left 
		A[right] = A[left];//��A[left]Ų��A[right]		 
	} 
	A[left] = temp;	//��temp�ŵ�left��right�����ĵط�
	return left;	//�����������±� 
}
void quickSort(int A[],int left,int right){
	if (left < right){//��ǰ����ĳ��Ȳ�����1
		int pos = Partition(A,left,right);
		quickSort(A,left,pos - 1);//����������ݹ���п�������
		quickSort(A,pos + 1,right);//����������ݹ���п������� 
	}
}
int main(){
	//��������
	int A[10]={3,5,1,2,7,98,5,0,2,44};
	quickSort(A,0,9);
	for(int i=0;i<10;i++){
		printf("%d ",A[i]);
	}
	return 0;
}

