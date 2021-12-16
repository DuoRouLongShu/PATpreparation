#include<stdio.h>
#include<iostream>
using namespace std; 
int main(){
	/*
		cin cout是C++的输入输出
		添加头文件
		#include<iostream>
		using namespace std; 
	*/	
	int n;
	double db;
	char c;
	char str[100],str2[100];
	//输入,不用指定格式，不需要加取地址运算符&，直接写变量名就可 
	cin >> n >> db >> c >> str;
	//输入一整行，使用getline函数
	cin.getline(str2,100); 
	
	//输出,换行有"\n"或endl 
	cout << n << "\n" << db << endl << c << endl << str << endl << str2; 
	return 0;
}

