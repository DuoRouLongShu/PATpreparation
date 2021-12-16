#include<stdio.h>
#include<math.h>
int main(){
	int n;
	char c;
	scanf("%d %c",&n,&c);
	for(int i=0;i<n;i++){
		printf("%c",c);
	} 
	printf("\n");
	int col = (int)round(((double)n)/2) - 2;
	for(int i=0;i<col;i++){
		printf("%c",c);
		for(int j=0;j<n-2;j++){
			printf(" ");
		}
		printf("%c",c);
		printf("\n");
	}
	for(int i=0;i<n;i++){
		printf("%c",c);
	} 
	return 0;
}

