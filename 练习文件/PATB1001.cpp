#include<stdio.h>
int main(){
	//PAT B1001
	int T = 0;
	int n;
	scanf("%d",&n);
	while(n != 1){
		if(n % 2 == 0){
			n = n/2;
		}else{
			n = 3 * n + 1;
			n = n / 2;
		}
		T++;
	} 
	printf("%d",T);
	return 0;
}

