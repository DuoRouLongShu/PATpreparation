#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
struct Student{
	char id[15];//׼��֤�� 
	int score;//���� 
	int loc;//������ 
	int locrank;//���������� 
}stu[30010];
bool cmp(Student a,Student b){
	/*
	������ͬ���������Ӵ�С����
	������ͬ����׼��֤�Ŵ�С�������� 
	*/
	if(a.score != b.score){
		return a.score > b.score;//������ͬ���������Ӵ�С����
	}else {
		return strcmp(a.id,b.id) < 0;//������ͬ����׼��֤�Ŵ�С��������
	}
}
int main(){
	int N,m=0;//mΪNode�����±� 
	scanf("%d",&N);//���Լ��� 
	for(int i=0;i<N;i++){
		int k;
		scanf("%d",&k);//ÿ�����Լ�������k����¼
		for(int j=0;j<k;j++){
			scanf("%s %d",stu[m].id,&stu[m].score);
			stu[m].loc = i+1;//��¼�������� 
			m++; 
		} 
		//ÿ�����Լ����Լ�����
		sort(&stu[m-k],&stu[m],cmp);
		stu[m-k].locrank = 1;
		for(int j=1;j<k;j++){
			if(stu[m-k+j].score == stu[m-k+j-1].score){//��ǰ��¼���Լ����Լ������� 
				stu[m-k+j].locrank = stu[m-k+j-1].locrank;
			}else{
				stu[m-k+j].locrank = j+1;
			}
		} 
	}
	sort(stu,stu+m,cmp);
	int rank = 1;
	printf("%d\n",m);
	printf("%s %d %d %d\n",stu[0].id,rank,stu[0].loc,stu[0].locrank);
	for(int i = 1;i<m;i++){
		if(stu[i].score != stu[i-1].score){
			rank = i + 1;
		}
		printf("%s %d %d %d\n",stu[i].id,rank,stu[i].loc,stu[i].locrank);
	}
	return 0;
}


