#include<cstdio> 
const int maxn = 11;
//P为当前排列，hashTable记录整数x是否已经在P中
int n,P[maxn],hashTable[maxn]={false}; 
void generate(int index){
	//递归实现全排列 ,《算法笔记》P115
	if(index == n+1){//递归边界，已经处理完排列1~n位 
		for(int i = 1;i <= n;i++){
			printf("%d",P[i]);//输出当前排列 
		}
		printf("\n");
		return;
	}	
	for(int x = 1;x <= n;x++){//枚举1~n，试图将x填入P[index]中
		if(hashTable[x] == false) {//如果x不在P[0]~P[index-1]中
			P[index] = x;//令P的第index位为x，即把x加入当前排列
			hashTable[x] = true;//x已在P的排列中 
			generate(index+1);//处理排列的第index+1号位 
			hashTable[x]=false;//已处理完P[index]为x的子问题，还原状态 
		}
	} 
}
int main(){
	n = 3;//实现1~3的全排列 
	generate(1);//从P[1]开始填 
	return 0;
}

