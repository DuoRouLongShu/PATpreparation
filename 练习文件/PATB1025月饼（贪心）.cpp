#include<cstdio>
#include<algorithm>
using namespace std;
struct mooncake{
	double store;//库存 
	double totalprice;//总售价
	double price;//单价 
}cake[1010];
bool cmp(mooncake a,mooncake b){
	return a.price > b.price;//单价按从大到小排序 
}
int main(){
	//PATB1025月饼
	int N;
	double need,value=0;//市场需求 最后输出的总价值 
	scanf("%d%lf",&N,&need);
	for(int i=0; i < N ;i++){
		scanf("%lf",&cake[i].store);//输入的是每种月饼的库存量 
	}
	for(int i = 0;i<N;i++){
		scanf("%lf",&cake[i].totalprice);//输入每种月饼的总售价 
		cake[i].price = cake[i].totalprice / cake[i].store;//计算每种月饼的单价 
	} 
	sort(cake,cake+N,cmp);//对月饼的单价排序
	int j=0;//从单价最高的月饼开始遍历 
	while(need != 0 && j < N){
		if(cake[j].store >= need){
			value += cake[j].price*need; 
			need = 0;
		}else{
			value += cake[j].totalprice;
			need -= cake[j].store;
			j++;
		}
	}
	printf("%.2f",value);
	return 0;
}

