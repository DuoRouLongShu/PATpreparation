#include<stdio.h>
#include<math.h> 
const int maxn = 100010;//素数表表长，int型数据一般开到10^5就够了 
int prime[maxn]={0},pNum=0;
struct factor{
	int x,cnt;//x为质因子，cnt为其个数 
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
	int n,num=0;//n为输入的质数,num为n不同质因子的个数 
	findPrime();
	scanf("%d",&n);
	if(n == 1) printf("1=1");//特判1的情况
	else{
		printf("%d=",n);
		int sqr = (int)sqrt(1.0 * n);//根号n
		for(int i =0; i < pNum && prime[i] <= sqr;i++){
			if(n % prime[i] == 0){
				fac[num].x = prime[i];//如果prime[i]是n的因子
				fac[num].cnt = 0;
				while(n % prime[i] == 0){
					fac[num].cnt++;
					n /= prime[i];
				} 
				num++;//不同质因子个数加1 
			}
			if(n ==1) break;//及时推出循环，节省时间 
		} 
		if (n != 1){
			fac[num].x = n;//若果无法被根号n以内的质因子除尽，那么一定有一个大于根号n的质因子
			fac[num++].cnt = 1; 
		}
		//按格式输出
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

