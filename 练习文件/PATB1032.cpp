#include<stdio.h>
const int N = 100010;
int a[N]={0};
int main(){
	//PAT B1032
	int n=0,bestschool=-1,school=0,score=0;
	scanf("%d",&n);
	for(int i=0;i < n;i++){
		scanf("%d%d",&school,&score);
		a[school] += score;
		if(a[school] >= a[0]){
			a[0] = a[school];
			bestschool = school;
		}
	}
	printf("%d %d",bestschool,a[0]);
	return 0;
}

