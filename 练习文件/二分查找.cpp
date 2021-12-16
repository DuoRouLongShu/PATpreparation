#include<stdio.h>
//二分区间为左闭右闭的[left,right],传入的初值为[0,n-1]
int binarySearch(int A[], int left, int right, int x){
	int mid;//mid为left和right的中点
	while(left <= right){//如果left>right就没法形成闭区间
		mid = (left + right) / 2;
		if(A[mid] == x)	 return mid;//找到x，返回下标
		else if(A[mid] > x){//中间的数大于x 
			right = mid - 1;//往左子区间[left,mid-1]去找 
		}else{
			left = mid + 1;
		}
	} 
	return -1;//查找失败，返回-1 
} 
int main(){
	//二分查找法 
	int n=10;
	int A[10]={1,3,4,6,7,8,10,11,12,15};
	printf("%d %d\n",binarySearch(A,0,n-1,6),binarySearch(A,0,n-1,9)); 
	return 0;
}

