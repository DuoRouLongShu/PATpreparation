#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
struct Student{
	char id[15];//准考证号 
	int score;//分数 
	int loc;//考场号 
	int locrank;//考场内排名 
}stu[30010];
bool cmp(Student a,Student b){
	/*
	分数不同，按分数从大到小排序；
	分数相同，按准考证号从小到大排序 
	*/
	if(a.score != b.score){
		return a.score > b.score;//分数不同，按分数从大到小排序；
	}else {
		return strcmp(a.id,b.id) < 0;//分数相同，按准考证号从小到大排序
	}
}
int main(){
	int N,m=0;//m为Node数组下标 
	scanf("%d",&N);//测试集数 
	for(int i=0;i<N;i++){
		int k;
		scanf("%d",&k);//每个测试集包含的k个记录
		for(int j=0;j<k;j++){
			scanf("%s %d",stu[m].id,&stu[m].score);
			stu[m].loc = i+1;//记录所属集合 
			m++; 
		} 
		//每个测试集先自己排序
		sort(&stu[m-k],&stu[m],cmp);
		stu[m-k].locrank = 1;
		for(int j=1;j<k;j++){
			if(stu[m-k+j].score == stu[m-k+j-1].score){//当前记录在自己测试集的排名 
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


