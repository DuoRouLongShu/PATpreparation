# 算法题BUG

### 对于字符数组的处理：

- 字符数组初始化：

  1. char str[15]={'G','o','d',' '};
  2. 直接赋值，**不过仅限初始化**：char str[15] = "Good story!";

- 字符数组输入输出

  1. scanf、printf

     - %c：用来输入单个字符，能够**识别空格跟换行符并将其输入**
     - %s：用来输入一串字符**并存在字符数组里**，**通过空格或换行识别字符串的结束**（后面对应数组名不用加&取地址运算符）

     ```c
     scanf("%s",str)
     printf("%s",str)
     输入：TAT TAT TAT
     输出：TAT
     ```

  2. getchar、putchar

  3. gets、puts

     gets识别换行符'\n'作为输入结束；

     puts用来输出一行字符串（一维数组或二维数组的一维），并紧跟一个换行

- 字符数组的存放方式

  空字符"\0"在使用gets或scanf输入字符串时会自动添加在输入的字符串后面，并占用一个字符位（但不属于字符串长度），而puts或printf就是通过\0识别作为字符串的结尾来输出，所以如果使用getchar输入字符串，请记得在字符串末尾加一个\0，否则printf或puts输出字符串无法识别字符串末尾而输出一堆乱码。

- string.h字符数组函数

  1. strlen()

     得到字符数组中第一个\0前的字符个数

     如：strlen(str);

  2. strcmp()

     strcmp(str1,str2) 返回小于0，等于0，大于0

     如果相比较字符数组某个元素是否是某一个字母，用法：

     ```C
     if (str[i] == 'P'){
     	……
     }
     //注意用的是单引号
     ```

     

  3. strcpy()

     strcpy(str1,str2)（注意复制包括结束符\0）

  4. strcat()

     把一个字符串连接到另一个字符串后面

     strcat(str1,str2)

- sscanf与sprintf

  ![ ](C:\Users\麦先生\AppData\Roaming\Typora\typora-user-images\image-20211201212831286.png)

  

![image-20211201212853850](C:\Users\麦先生\AppData\Roaming\Typora\typora-user-images\image-20211201212853850.png)

### C++标准模板库（STL）介绍

STL：standard template library

#### vector



### 数学知识

#### 最大公约数P154

```C
int gcd(int a,int b){
    return !b ? a: gcd(b,a % b);
}
```

#### 最小公倍数

……

#### 分数的四则运算

- 分数表示

  ```C
  struct Fraction{//分数
  	int up,down;//分子，分母
  }
  ```

- 分数化简

  ```C
  /*
  满足三个原则
  1.分母为负数，则令分子和分母都变成相反数
  2.分子up为0，则令分母down为1
  3.约分：求出分子绝对值和分母绝对值的最大公约数d，然后令分子分母同时除以d
  */
  Fraction reduction(Fraction result){
      if(result.down < 0){//分母为负数，则令分子和分母都变成相反数
          result.up = -result.up;
          result.down = -result.down;
      }
      if(result.up == 0){//如果分子为0
          result.down = 1;//令分母为1
      }else{//如果分母不为0，则进行约分
          int d = gcd(abs(result.up),abs(result.down));//分子分母的最大公约数
          result.up /= d;//约去最大公约数
          result.down /= d;
      }
      return result;	
  }
  ```

- 分数四则运算

  ```C
  //加法
  Fraction add(Fraction f1,Fraction f2){
      Fraction result;
      result.up = f1.up * f2.down + f2.up * f1.down;
      result.down = f1.down * f2.down;
      return reduction(result);//返回结果分数，注意化简
  }
  
  //减法
  Fraction minu(Fraction f1,Fraction f2){
      Fraction result;
      result.up = f1.up * f2.down - f2.up * f1.down;
      result.down = f1.down * f2.down;
      return reduction(result);//返回结果分数，注意化简
  }
  
  //乘法
  Fraction multi(Fraction f1,Fraction f2){
      Fraction result;
      result.up = f1.up * f2.up;
      result.down = f1.down * f2.down;
      return reduction(result);//返回结果分数，注意化简
  }
  
  //除法
  Fraction divide(Fraction f1,Fraction f2){
      Fraction result;
      result.up = f1.up * f2.down;
      result.down = f1.down * f2.up;
      return reduction(result);//返回结果分数，注意化简
  }
  ```

- 分数的输出

  ```C
  /*
  1.输出前化简
  2.分母为1，直接输出分子为整数
  3.分子up绝对值大于分母down，说明是假分数
  4.以上都不是，原样输出
  注：由于分数的乘法和除法过程中可能是分子或分母超过int型表示的范围，因此一般情况下， 分子分母应当使用long long型来存储
  */
  void showResult(Fraciton r){
      r = reduction(r);
      if (r.down == 1) printf("lld",r.up);//整数
  	else if (abs(r.up) > r.down){//假分数
          printf("%d %d/%d",r.up / r.down,abs(r.up) % r.down,r.down);
      }else{
          printf("%d/%d",r.up,r.down);
      }
  }
  ```

#### 素数

- 素数的判断

  只要判断2~sqrt（n）是不是n的公约数就好

  ```C
  bool isPrime(int n){
      if(n <= 1) return false;
      int sqr = (int)sqrt(1.0 * n);//根号n
      for(int i=2;i<=sqr;i++){//遍历2~根号n
          if(n % i == 0) return false;//n是i的倍数，则n不是素数
      }
      return true;//n是素数
  }
  ```

  sqrt函数，需要添加math.h头文件

- 素数表的获取

  1. 方法一：直接法P161

     ```c
     const int maxn = ?;//表长
     int prime[maxn],pNum = 0;//prime数组存放所有的素数，pNum为素数个数
     void Find_Prime(){
         for (int i=1;i < maxn;i++ ){
             if(isPrime(i) == true){
                 prime[pNum++] = i;//是素数把i存入prime数组
             }
         }
     }
     ```

     

  2. 方法二：筛法

  <img src="C:\Users\麦先生\AppData\Roaming\Typora\typora-user-images\image-20211213192424013.png" alt="image-20211213192424013" style="zoom: 67%;" />

  ```c
  #include<stdio.h>
  //筛法，求解素数表 
  const int maxn = 101;//表长
  int prime[maxn],pNum = 0;//prime数组存放所有素数，pNum为素数个数
  bool p[maxn] = {0};//如果i为素数，则p[i]为false；否则，p[i]为true
  void Find_Prime(){
  	for(int i = 2;i < maxn;i++){//从2开始，i<maxn结束，注意不能写成i<=maxn
  		if(p[i] == false){//如果i是素数
  			prime[pNum++] = i; //把素数i存到prime数组中
  			for(int j = i + i;j < maxn;j+= i){
  				p[j] = true;//筛去所有i的倍数，循环条件不能写出j<=maxn
  			} 
  		}
  	}
  }
  int main(){
  	Find_Prime();
  	for(int i=0;i<pNum;i++){
  		printf("%d ",prime[i]);
  	}
  	return 0;
  }
  
  ```
  

#### 质数

int范围内的正整数，素数表大概开到10^5大小就可以，即maxn=100010

- 结构体

  ```C
  struct factor{
      int x,cnt;//x为因子，cnt为出现的次数
  }fac[10];//对于一个int型范围的书来说，fac数组开到10就可以了
  ```

- 质因子的分解

  1. 枚举1~sqrt（n）范围内的所有质因子p，判断p是否为n的因子

     - 如果是，更新fac数组，n不断除以p，直到p不再是n的质因子
     - 如果不是，则跳过

     ```C 
     if(n % prime[i] == 0){//如果prime[i]是n的质因子
         fac[num].x = prime[i];//记录该因子
         fac[num].cnt = 0;
         while(n % prime[i] == 0){//计算出该质因子的个数
             fac[num].cnt++;
             n /= prime[i];
         }
         num++;//不同质因子个数加1
     }
     ```

  2. 上面步骤后，n仍然大于1，说明n有且仅有一个大于sqrt（n）（因为如果有两个的话，乘起来肯定大于n了，所以只能有一个，可能也是n本身，比如n本身就是质数），把这个质因子加入fac数组

     ```C
     if(n != 1 ){//如果无法被根号n以内的质因数除尽
         fac[num].x = n;//那么一定有一个大于根号n的质因子
         fac[num].cnt = 1;//
     }
     ```

     

### 生成随机数

- 添加头文件

  ```C
  #include<stdlib.h>
  #include<time.h>
  int main(){
      //并在main函数开头加上这句
      srand((unsigned)time(NULL));//这个语句将生成随机数种子
      //用法：rand()
      printf("%d",rand());
      return 0;
  }
  ```

- 生成[a,b]的随机数

  rand()只能输出[0,RAND_MAX]范围内的整数（RAND_MAX是stdlib.h中的一个常数），输出给定范围[a,b]内的随机数：rand()%(b-a+1)+a

- 生成比RAND_MAX更大的随机数P145

  ```C
  (int)((double)rand()/32763*(b-a+1)+a)
  ```

  

### 排序

#### 选择排序

```C
void selectSort(){
    int temp;
    for(int i=1;i<=n;i++){//需要进行	n趟操作
        int k = i;
        for(int j=i;j<=n;j++){//选出[i,n]中最小的元素，下标为k
			if(a[k]>a[j]){
                k = j;
            }
        }
        temp = a[i];//交换a[k]与a[i]
        a[i] = a[k];
        a[k] = temp;
    }
}
```



#### 直接插入排序

```C
void insertSort(){
    for(int i=2;i<=n;i++){//进行n-1趟排序
        int temp = a[i],j = i;//temp临时存放a[i]，j从i开始往前遍历
        while(temp < a[j-1] && j > 1){//只要temp小于前一个元素a[j-1]
            a[j] = a[j-1];
            j--;//j往后移
        }
        a[j] = temp;//插入位置j
    }
}
```

#### 归并排序

- 递归实现

  ```C
  #include<stdio.h>
  const int maxn = 100;
  //将数组A的[L1,R1]与[L2,R2]区间合并为有序区间（此处L2为R1+1）
  void merge(int A[],int L1, int R1, int L2, int R2){
  	int i = L1, j = L2;//i指向A[L1],j指向A[L2] 
  	int temp[maxn],index = 0;//temo临时存放合并后的数组，index为其下标
  	while(i <= R1 && j <= R2){
  		if (A[i] <= A[j]){	//如果A[i] <=A[j] 
  			temp[index++] = A[i++]; 	//将A[i]加入到序列temp中 
  		}else{		//如果A[i]>A[j] 
  			temp[index++] = A[j++];		//将A[j]加入到序列temp中 
  		}
  	} 
  	while(i <= R1) temp[index++] = A[i++];//将[L1,R1]中剩余元素加入到序列temp中 
  	while(j <= R2) temp[index++] = A[j++];//将[L2,R2]中剩余元素加入到序列temp中 
  	for(int i = 0;i < index;i++){
  		A[L1+i] = temp[i];//将合并后的序列赋值回给数组A 
  	} 
  } 
  //将array数组当前区间[left,right]进行归并排序
  void mergeSort(int A[],int left,int right){
  	if(left < right){	//只要left<right 
  		int mid = (left+right) / 2;//取[left,right]中点
  		mergeSort(A,left,mid);	//递归，将左子区间[left,mid]归并排序 
  		mergeSort(A,mid+1,right);	//递归，将右子区间[mid+1,right]归并排序 
  		merge(A,left,mid,mid+1,right);	//将左子区间和右子区间合并 
  	}
  } 
  int main(){
  	//归并排序——递归实现
  	int A[10]={3,5,1,2,7,98,5,0,2,44};
  	mergeSort(A,0,9);
  	for(int i=0;i<10;i++){
  		printf("%d ",A[i]);
  	}
  	return 0;
  }
  
  ```

- 非递归实现P141 

  ```C
  ……
  ```

#### 快速排序

```C
#include<stdio.h>
//对区间[left,right]进行划分 
int Partition(int A[], int left, int right){
	int temp = A[left];//将A[left]存放至临时变量temp
	while(left < right){//只要left与right不相遇 
		while(left < right && A[right] > temp) right--;//反复左移right
		A[left] = A[right];//将A[right]挪到A[left]
		while(left < right && A[left] <= temp) left++;//反复右移left 
		A[right] = A[left];//将A[left]挪到A[right]		 
	} 
	A[left] = temp;	//把temp放到left与right相遇的地方
	return left;	//返回相遇的下标 
}
void quickSort(int A[],int left,int right){
	if (left < right){//当前区间的长度不超过1
		int pos = Partition(A,left,right);
		quickSort(A,left,pos - 1);//对左子区间递归进行快速排序
		quickSort(A,pos + 1,right);//对右子区间递归进行快速排序 
	}
}
int main(){
	//快速排序
	int A[10]={3,5,1,2,7,98,5,0,2,44};
	quickSort(A,0,9);
	for(int i=0;i<10;i++){
		printf("%d ",A[i]);
	}
	return 0;
}

```



#### C++的sort函数P235

- 用法

  加上：

  ```c++
      #include<algorithm>
      using namespace std;
  ```

  语法：

  ```c++
  sort(首元素底值(必填)，尾元素地址的下一个地址（必填），比较函数（非必填）)
      
  int a[6]={9,4,2,5,6,-1};
  //将a[0]~a[3]从小到大排序
  sort(a,a+4);//注意理解“尾元素地址的下一个地址”
  //输出：2 4 5 9 6 -1
  
  ```

- sort第三个参数

  第三个参数就是compare函数（一般写作cmp函数）

  实现规则：

  如果cmp返回结果为假, 那么函数就会将他们互换位置；如果cmp返回结果为真，就会保持原来位置不变。

  1. 基本数据类型的排序

     若比较函数不填，**默认从小到大排序**；

     当想要从大到小排序，参考下面代码

     ```c++
     bool cmp(int a,int b){
     	return a > b;//意味着a>b的时候，把a放到b前,按大到小排序。 
     }
     int main(){
     	int a[4]={3,1,4,2};
     	sort(a,a+4,cmp);
     }
     //输出结果：4 3 2 1
     ```

     **记忆方法**：如果要把数据从小到大排列，就用“<”,因为“a<b"就是左小右大；

     ​				   如果要把数据从大到小排列，就用“>”,因为“a>b"就是左大右小；

  2. 结构体数组的排序

     算法笔记P239

  3. 容器的排序

###      递归

- 全排列

  <img src="C:\Users\麦先生\AppData\Roaming\Typora\typora-user-images\image-20211208154231963.png" alt="image-20211208154231963" style="zoom:67%;" />

  ```C
  #include<cstdio> 
  const int maxn = 11;
  //P为当前排列，hashTable记录整数x是否已经在P中
  int n,P[maxn],hashTable[maxn]={false}; 
  void generate(int index){
  	//递归实现全排列 ,《算法笔记》P115
  	if(index == n+1){//递归边界，已经处理完排列1~n位 
  		for(int i = 1;i <= n;i++){
  			printf("%d",P[i]);//输出当前排列 
  		}
  		printf("\n");
  		return;
  	}	
  	for(int x = 1;x <= n;x++){//枚举1~n，试图将x填入P[index]中
  		if(hashTable[x] == false) {//如果x不在P[0]~P[index-1]中
  			P[index] = x;//令P的第index位为x，即把x加入当前排列
  			hashTable[x] = true;//x已在P的排列中 
  			generate(index+1);//处理排列的第index+1号位 
  			hashTable[x]=false;//已处理完P[index]为x的子问题，还原状态 
  		}
  	} 
  }
  int main(){
  	n = 3;//实现1~3的全排列 
  	generate(1);//从P[1]开始填 
  	return 0;
  }
  
  ```

- N皇后问题

  ……

### 查找

#### 二分查找P124

- 序列中**是否存在满足某条件**的元素

  ```C
  #include<stdio.h>
  //二分区间为左闭右闭的[left,right],传入的初值为[0,n-1]
  int binarySearch(int A[], int left, int right, int x){
  	int mid;//mid为left和right的中点
  	while(left <= right){//如果left>right就没法形成闭区间
  		mid = (left + right) / 2;
          /*
          当left+right超过int有可能导致溢出时，可以使用
          mid = left + (right - left) / 2;
          */
  		if(A[mid] == x)	 return mid;//找到x，返回下标
  		else if(A[mid] > x){//中间的数大于x 
  			right = mid - 1;//往左子区间[left,mid-1]去找 
  		}else{
  			left = mid + 1;
  		}
  	} 
  	return -1;//查找失败，返回-1 
  } 
  int main(){
  	//二分查找法 
  	int n=10;
  	int A[10]={1,3,4,6,7,8,10,11,12,15};
  	printf("%d %d\n",binarySearch(A,0,n-1,6),binarySearch(A,0,n-1,9)); 
  	return 0;
  }
  ```

- 寻找有序序列中**第一个满足某条件**的元素的位置

  ```C
  //二分区间为左闭右闭的[left,right],传入的初值为[0,n]
  int solveSearch(int left, int right){
  	int mid;//mid为left和right的中点
  	while(left < right){//如果left==right就意味着找到唯一的位置
  		mid = (left + right) / 2;//取中点
  		if(条件成立){//条件成立，第一个满足条件的元素位置<=mid
              right = mid;//往左子区间[left,mid]中去查找
          }else{//条件不成立，则第一个满足该条件的元素的位置>mid
  			left = mid + 1;//往右子区间[mid+1,right]去找 
  		}
  	} 
  	return left;//返回夹出来的位置 
  } 
  ```

  

### PATB1009说反话

<img src="C:\Users\麦先生\AppData\Roaming\Typora\typora-user-images\image-20211201121228267.png" alt="image-20211201121228267" style="zoom:66%;" />

要联想到用二维数组来处理输入，因为scanf刚好是用空格来识别字符串的结束输入，所以二维数组每一个单元刚好就是遇到空格停止的单词。

```C
#include<stdio.h>
#include<string.h>
const int maxn = 80;
int main(){
	//PATB1009
	int num=0;//单词的个数 
	char str[90][90];
	while(scanf("%s",str[num])!=EOF){
		num++;//单词数加一 
	}
	//倒序输出单词即可
	for(int i=num-1; i>=0 ;i--){
		printf("%s",str[i]);
		if(i>0){
			printf(" ");
		}
	} 
	return 0;
}
//运行程序后，输入完数据想要退出按ctrl+z，然后按enter
```

### 贪心算法

```C
int count=0;
```

### bug整理

- 布尔型

  布尔型在C++中可以直接使用，但在C语言中必须添加stdbool.h头文件才可以使用；

  ```C
  #include<stdbool.h>
  ```

- 如果相比较字符数组某个元素是否是某一个字母，用法：

  ```C
  if (str[i] == 'P'){
  	……
  }
  //注意用的是单引号
  ```

  

### 解题小技巧

- 打表

  <img src="C:\Users\麦先生\AppData\Roaming\Typora\typora-user-images\image-20211211220942308.png" alt="image-20211211220942308" style="zoom:50%;" />

  <img src="C:\Users\麦先生\AppData\Roaming\Typora\typora-user-images\image-20211211221000521.png" alt="image-20211211221000521" style="zoom:50%;" />
  
- 要输出整数"0123"，可以使用域宽技巧

  ```C
  int n = 123;
  printf("%04d",n);
  //不必把它变成一个数组，再遍历输出
  ```

  