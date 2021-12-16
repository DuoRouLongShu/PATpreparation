#include<stdio.h>
//简单版的 
struct studentInfo1{
	int id;
	char gender;
};

//添加构造函数版的
struct studentInfo2{
	int id;
	char gender;
	//用以不初始化就定义结构体变量
	studentInfo2(){}
	//只初始化gender
	studentInfo2(char _gender){
		gender = _gender;
	}
	//只初始化id
	studentInfo2(int _id){
		id = _id;
	}
	//同时初始化gender和id
	studentInfo2(int _id,char _gender){
		id = _id;
		gender = _gender;
	} 
}; 
int main(){
	/*
	原始的对结构体变量初始化用 . 或者 ->(结构体指针变量用) 
	*/
	studentInfo1 stu1[5],*stup;
	for(int i = 0;i < 5;i++ ){
		stu1[i].id = i;
		stu1[i].gender = 'M'; 
	}
	for(int i = 0;i < 5;i++){
		printf("%d %c\n",stu1[i].id,stu1[i].gender);
	}
	/*
	结构体初始化：使用构造函数 
	*/ 
	studentInfo2 stu2[5];
	for(int i = 0;i < 5;i++ ){
		stu2[i] = studentInfo2(i);	
	}
	for(int i = 0;i < 5;i++){
		printf("%d %c\n",stu2[i].id,stu2[i].gender);
	}
	return 0;
}

