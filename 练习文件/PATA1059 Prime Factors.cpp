#include<stdio.h>
#include<math.h> 
const int maxn = 100010;//���������int������һ�㿪��10^5�͹��� 
int prime[maxn]={0},pNum=0;
struct factor{
	int x,cnt;//xΪ�����ӣ�cntΪ����� 
}fac[10]; 
bool isPrime(int n){
	if (n <= 1) return false;
	int sqrtN = (int)sqrt(1.0*n);
	for (int i=2; i <= sqrtN;i++){
		if(n % i == 0) return false;
	}
	return true;
}
void findPrime(){
	for(int i =1;i<maxn;i++){
		if(isPrime(i) == true){
			prime[pNum++] = i;
		}
	}
}
int main(){
	//PATA1059 Prime Factors
	int n,num=0;//nΪ���������,numΪn��ͬ�����ӵĸ��� 
	findPrime();
	scanf("%d",&n);
	if(n == 1) printf("1=1");//����1�����
	else{
		printf("%d=",n);
		int sqr = (int)sqrt(1.0 * n);//����n
		for(int i =0; i < pNum && prime[i] <= sqr;i++){
			if(n % prime[i] == 0){
				fac[num].x = prime[i];//���prime[i]��n������
				fac[num].cnt = 0;
				while(n % prime[i] == 0){
					fac[num].cnt++;
					n /= prime[i];
				} 
				num++;//��ͬ�����Ӹ�����1 
			}
			if(n ==1) break;//��ʱ�Ƴ�ѭ������ʡʱ�� 
		} 
		if (n != 1){
			fac[num].x = n;//�����޷�������n���ڵ������ӳ�������ôһ����һ�����ڸ���n��������
			fac[num++].cnt = 1; 
		}
		//����ʽ���
		for(int i=0;i<num;i++) {
			if(i>0) printf("*");
			printf("%d",fac[i].x);
			if(fac[i].cnt > 1){
				printf("^%d",fac[i].cnt);
			}
		} 
	} 
	return 0;
}

