#include<stdio.h>
#include<string.h>
int main(){
	//PATB1040 有几个PAT 
	char str[100010];
	int leftNumP[100010]={0},rightNumT[100010]={0};//leftNumP统计每一位左边P的数量，rightNumT统计每一位右边T的数量
	long long int sum=0; 
	scanf("%s",str);
	int len = strlen(str);
	if(str[0] == 'P'){//第一位是P，leftNumP的0下标单元赋1，方便下面循环进行 
		leftNumP[0]=1;
	} 
	if(str[len-1]=='T'){//同上面 
		rightNumT[len-1]=1;
	}
	for(int i=1;i<len;i++){//从下标为1的开始遍历
		if (str[i] == 'P'){//如果i为P，则leftNumP[i]就等于 leftNumP[i-1]+1
			leftNumP[i] = leftNumP[i-1] + 1; 
		}else{//否则不是P，leftNumP[i]就等于 leftNumP[i-1] 
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

