#include<stdio.h>
//对区间[left,right]进行划分 
int Partition(int A[], int left, int right){
	int temp = A[left];//将A[left]存放至临时变量temp
	while(left < right){//只要left与right不相遇 
		while(left < right && A[right] > temp) right--;//反复左移right
		A[left] = A[right];//将A[right]挪到A[left]
		while(left < right && A[left] <= temp) left++;//反复右移left 
		A[right] = A[left];//将A[left]挪到A[right]		 
	} 
	A[left] = temp;	//把temp放到left与right相遇的地方
	return left;	//返回相遇的下标 
}
void quickSort(int A[],int left,int right){
	if (left < right){//当前区间的长度不超过1
		int pos = Partition(A,left,right);
		quickSort(A,left,pos - 1);//对左子区间递归进行快速排序
		quickSort(A,pos + 1,right);//对右子区间递归进行快速排序 
	}
}
int main(){
	//快速排序
	int A[10]={3,5,1,2,7,98,5,0,2,44};
	quickSort(A,0,9);
	for(int i=0;i<10;i++){
		printf("%d ",A[i]);
	}
	return 0;
}

