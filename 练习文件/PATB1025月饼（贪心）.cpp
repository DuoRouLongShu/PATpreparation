#include<cstdio>
#include<algorithm>
using namespace std;
struct mooncake{
	double store;//��� 
	double totalprice;//���ۼ�
	double price;//���� 
}cake[1010];
bool cmp(mooncake a,mooncake b){
	return a.price > b.price;//���۰��Ӵ�С���� 
}
int main(){
	//PATB1025�±�
	int N;
	double need,value=0;//�г����� ���������ܼ�ֵ 
	scanf("%d%lf",&N,&need);
	for(int i=0; i < N ;i++){
		scanf("%lf",&cake[i].store);//�������ÿ���±��Ŀ���� 
	}
	for(int i = 0;i<N;i++){
		scanf("%lf",&cake[i].totalprice);//����ÿ���±������ۼ� 
		cake[i].price = cake[i].totalprice / cake[i].store;//����ÿ���±��ĵ��� 
	} 
	sort(cake,cake+N,cmp);//���±��ĵ�������
	int j=0;//�ӵ�����ߵ��±���ʼ���� 
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

