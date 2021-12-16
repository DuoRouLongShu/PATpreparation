#include<cstdio>
int main(){
	//PATB1023组个最小数（贪心）
	int a[10]={0};
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
	} 
	for(int i=1;i<10;i++){
		if(a[i] != 0){
			printf("%d",i);
			a[i] -= 1;
			break;
		}
	}
	for(int i = 0;i<10;i++){
		if(a[i] != 0){
			for(int j=0;j<a[i];j++){
				printf("%d",i);
			}
		}
	}
	return 0;
}

