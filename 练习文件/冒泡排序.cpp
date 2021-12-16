//ц╟ещеепР
#include<stdio.h>
int main(){
	int temp; 
	int a[10] = {3,2,6,5,8,1,5};
	for (int i = 0;i <7; i++ ){
		for(int j = 0;j < 7-i-1;j++){
			if (a[7-1-i] < a [j]){
				temp = a[7-1-i];
				a[7-1-i] = a[j];
				a[j] = temp;
			}
		}
	} 	
	for(int i = 0;i < 7;i++){
		printf("%d ",a[i]);
	}
}
