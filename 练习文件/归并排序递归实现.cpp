#include<stdio.h>
const int maxn = 100;
//将数组A的[L1,R1]与[L2,R2]区间合并为有序区间（此处L2为R1+1）
void merge(int A[],int L1, int R1, int L2, int R2){
	int i = L1, j = L2;//i指向A[L1],j指向A[L2] 
	int temp[maxn],index = 0;//temo临时存放合并后的数组，index为其下标
	while(i <= R1 && j <= R2){
		if (A[i] <= A[j]){	//如果A[i] <=A[j] 
			temp[index++] = A[i++]; 	//将A[i]加入到序列temp中 
		}else{		//如果A[i]>A[j] 
			temp[index++] = A[j++];		//将A[j]加入到序列temp中 
		}
	} 
	while(i <= R1) temp[index++] = A[i++];//将[L1,R1]中剩余元素加入到序列temp中 
	while(j <= R2) temp[index++] = A[j++];//将[L2,R2]中剩余元素加入到序列temp中 
	for(int i = 0;i < index;i++){
		A[L1+i] = temp[i];//将合并后的序列赋值回给数组A 
	} 
} 
//将array数组当前区间[left,right]进行归并排序
void mergeSort(int A[],int left,int right){
	if(left < right){	//只要left<right 
		int mid = (left+right) / 2;//取[left,right]中点
		mergeSort(A,left,mid);	//递归，将左子区间[left,mid]归并排序 
		mergeSort(A,mid+1,right);	//递归，将右子区间[mid+1,right]归并排序 
		merge(A,left,mid,mid+1,right);	//将左子区间和右子区间合并 
	}
} 
int main(){
	//归并排序——递归实现
	int A[10]={3,5,1,2,7,98,5,0,2,44};
	mergeSort(A,0,9);
	for(int i=0;i<10;i++){
		printf("%d ",A[i]);
	}
	return 0;
}

