#include<stdio.h>
//�򵥰�� 
struct studentInfo1{
	int id;
	char gender;
};

//��ӹ��캯�����
struct studentInfo2{
	int id;
	char gender;
	//���Բ���ʼ���Ͷ���ṹ�����
	studentInfo2(){}
	//ֻ��ʼ��gender
	studentInfo2(char _gender){
		gender = _gender;
	}
	//ֻ��ʼ��id
	studentInfo2(int _id){
		id = _id;
	}
	//ͬʱ��ʼ��gender��id
	studentInfo2(int _id,char _gender){
		id = _id;
		gender = _gender;
	} 
}; 
int main(){
	/*
	ԭʼ�ĶԽṹ�������ʼ���� . ���� ->(�ṹ��ָ�������) 
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
	�ṹ���ʼ����ʹ�ù��캯�� 
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

