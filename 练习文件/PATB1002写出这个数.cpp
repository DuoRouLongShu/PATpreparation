#include<cstdio>
#include<cstring>
int main(){
	//PATB1002 д�������
	char str[110];//���n
	int sum=0;
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++){
		sum += str[i] - 48;
	} 
	return 0;
}

