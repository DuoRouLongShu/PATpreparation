#include<stdio.h>
#include<iostream>
using namespace std; 
int main(){
	/*
		cin cout��C++���������
		���ͷ�ļ�
		#include<iostream>
		using namespace std; 
	*/	
	int n;
	double db;
	char c;
	char str[100],str2[100];
	//����,����ָ����ʽ������Ҫ��ȡ��ַ�����&��ֱ��д�������Ϳ� 
	cin >> n >> db >> c >> str;
	//����һ���У�ʹ��getline����
	cin.getline(str2,100); 
	
	//���,������"\n"��endl 
	cout << n << "\n" << db << endl << c << endl << str << endl << str2; 
	return 0;
}

