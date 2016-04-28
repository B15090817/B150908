/* ①Book.h文件的完整内容 */  
#ifndef _BOOK             /*条件编译，防止重复包含的错误*/  
#define _BOOK  
#include <string.h>  
#define NUM 3                /*定义图书种类常量，此处可以根据实际需要修改常量值*/  
struct Book                 /*图书记录的数据域*/  
 {  
    char ISBN[18];               //书的编号
	char name[20];               //书名
	float price;               //书的单价
	char category[20];          //书的种类
    char  auther_name[20];            //作者姓名
	int remain;                  //书的库存
    int  salevolume[3];             //每个月书的销量
    int total;                 //三个月的总销量
    double sales_money;                    //书的销售额
    int rank;         //受欢迎度
 };  
 typedef struct Book Book;  
 #define sizeBk sizeof(Book)       /*一个图书记录所需要的内存空间大小*/  
 int readBk(Book bk[],int n);       /*读入图书记录值，读满规定条数记录时停止*/  
 void printBk(Book  *bk , int n);   /*输出所有图书记录的值*/  
  
int equal(Book b1,Book b2,int condition);  /*根据condition条件判断两个Book类型数据相等否*/  
int larger(Book b1,Book b2,int condition);  /*根据condition比较Book类型数据大小*/  
void reverse(Book bk[],int n);             /*图书记录数组元素逆置*/  
  
void calcuTotal(Book bk[],int n);           /*计算一个季度图书的总销售量*/
void seson_sales_money(Book bk[],int n);           /*计算一个季度图书的销售额*/
//void month_sales_money(Book bk[],int n);           /*一个月的销售额*/
void calcuRank(Book bk[],int n);           /*根据图书的销售量，允许有并列名次*/  
void calcuMark(double m[3][3],Book bk[],int n); /*求三个月的最高、最低、平均销量，m数组第一维*/  
/*表示哪个月，第二维表示最高、最低、平均销量*/  
void calcu_remain(Book bk[],int n);        /*计算一个季度的库存*/

void sortBk(Book bk[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/  
 
int searchBk(Book bk[],int n,Book b,int condition,int f[]) ;  /*根据条件找数组中与b相等的各元素*/  
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/  
int insertBk(Book bk[],int n,Book b);                   /*向数组中插入一个元素按书编号有序*/  
int deleteBk(Book bk[],int n,Book s);                   /*从数组中删除一个指定图书的元素*/  
#endif  
