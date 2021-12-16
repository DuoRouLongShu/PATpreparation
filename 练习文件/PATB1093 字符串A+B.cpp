#include<cstdio>
#include<cstring>
int main(){
	//PATB1093 ×Ö·û´®A+B
	char A[1000010],B[1000010];
	bool hashA[95]={false},hashB[95]={false};
	gets(A);
	gets(B);
	for(int i=0;i<strlen(A);i++){
		if(hashA[A[i]-32] == false){
			hashA[A[i]-32] = true;
		}
	}
	for(int i=0;i<strlen(B);i++){
		if(hashB[B[i]-32] == false && hashA[B[i]-32] == false){
			hashB[B[i]-32] = true;
		}
	}	
	for(int i=0;i<strlen(A);i++){
		if(hashA[A[i]-32] == true){
			printf("%c",A[i]);
			hashA[A[i]-32] = false;
		}
	}
	for(int i=0;i<strlen(B);i++){
		if(hashB[B[i]-32] == true){
			printf("%c",B[i]);
			hashB[B[i]-32] = false;
		}
	}	
	return 0;
}

