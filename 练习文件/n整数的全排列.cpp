#include<cstdio> 
const int maxn = 11;
//PΪ��ǰ���У�hashTable��¼����x�Ƿ��Ѿ���P��
int n,P[maxn],hashTable[maxn]={false}; 
void generate(int index){
	//�ݹ�ʵ��ȫ���� ,���㷨�ʼǡ�P115
	if(index == n+1){//�ݹ�߽磬�Ѿ�����������1~nλ 
		for(int i = 1;i <= n;i++){
			printf("%d",P[i]);//�����ǰ���� 
		}
		printf("\n");
		return;
	}	
	for(int x = 1;x <= n;x++){//ö��1~n����ͼ��x����P[index]��
		if(hashTable[x] == false) {//���x����P[0]~P[index-1]��
			P[index] = x;//��P�ĵ�indexλΪx������x���뵱ǰ����
			hashTable[x] = true;//x����P�������� 
			generate(index+1);//�������еĵ�index+1��λ 
			hashTable[x]=false;//�Ѵ�����P[index]Ϊx�������⣬��ԭ״̬ 
		}
	} 
}
int main(){
	n = 3;//ʵ��1~3��ȫ���� 
	generate(1);//��P[1]��ʼ�� 
	return 0;
}

