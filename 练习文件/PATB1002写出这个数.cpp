#include<cstdio>
#include<cstring>
int main(){
	//PATB1002 写出这个数
	char str[110];//存放n
	int sum=0;
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++){
		sum += str[i] - 48;
	} 
	return 0;
}

