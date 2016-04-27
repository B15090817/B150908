/*②book.c文件的完整内容*/  
#include "Book.h"  
#include <stdio.h>  
  
int readBk(Book*bk ,int n)          /*读入图书记录值，图书编号为0或读满规定条数记录时停止*/  
{  
 	int i,j;  
	for (i=0;i<n;i++)  
	{  
	printf("Input one Book's information\n");  
	printf("ISBN:  ");  
      scanf("%s", bk[i].ISBN); 
	  if(strcmp(bk[i].ISBN,"0")==0)
		  break;
	printf("name: ");  
	 scanf("%s",bk[i].name);	  
	printf("price:  ");  
	 scanf("%f",&bk[i].price); 
    printf("category:  ");
      scanf("%s",bk[i].category);                  /*书的类别*/
    printf("auther_name:  ");
      scanf("%s",bk[i].auther_name);                /*作者*/
   	printf("remain:  ");
	  scanf("%d",&bk[i].remain);                    /*输入初始库存*/
	printf("Input three months of the Book:\n");  
	for (j=0;j<3;j++)  
    {  
	    scanf("%d",&bk[i].salevolume[j]);	  
    }  
		bk[i].rank=0;                 /*名次需要根据总分来计算，初值置为0*/ 
        bk[i].total=0;               /*总销量需要计算求得，初值置为0*/ 
		bk[i].sales_money=0;
	}  
	return i;                         /*返回实际读入的记录条数*/  
}  
   
 void printBk (Book*bk,int n)       /*输出所有学生记录的值*/  
{  
    int i,j;  
 	for (i=0;i<n;i++)  
 	{  
 	printf("%-8s", bk[i].ISBN);  
	printf("%-10s",bk[i].name);
	printf("%-8s",bk[i].auther_name);
	printf("%-6s",bk[i].category); 
	printf("%-6.2lf",bk[i].price);
	for (j=0;j<3;j++)  
 	   printf("%8d",bk[i].salevolume[j]);  
 	printf("%-8d",bk[i].total);
	printf("%-8.2lf",bk[i].sales_money); 
    printf("%-10d\n",bk[i].rank);  
 	}  
 }  
   
 int equal(Book b1,Book b2,int condition)  /*如何判断两个Book记录相等*/  
 {  
	if (condition==1)                  /*如果参数condition的值为1，则比较书编号*/  
	{	
		if (strcmp(b1.ISBN,b2.ISBN)==0) 
 		    return 1;  
        else 
		   return 0; 
	}
	else if (condition==2)                /*如果参数condition的值为2，则比较书名*/  
     {  
       if (strcmp(b1.name,b2.name)==0) 
 		    return 1;  
       else 
		   return 0;  
    }  
    else if (condition==3)                /*如果参数condition的值为3，则比较销量名次(热度)*/  
 	     return b1.rank==b2.rank;  
    else if (condition==4)                /*如果参数condition的值为4，则比较书的作者*/ 
	{
	 if (strcmp(b1.auther_name,b2.auther_name)==0) 
 		   return 1;  
	 else 
		   return 0; 
	}
	else return 1;                       /*其余情况返回1*/  
 }   
  
int larger(Book b1,Book b2,int condition)  /*根据condition条件比较两个Book记录的大小*/  
 {  
	if (condition==1)                      /*如果参数condition的值为1，则比较书编号*/ 
	{	
		if (strcmp(b1.ISBN,b2.ISBN)==1) 
 		    return 1;  
       else 
		   return 0;                         /*	return s1.num>s2.num;*/
	} 
	else if(condition==2)
	{
	 if (strcmp(b1.auther_name,b2.auther_name)==1)  /*如果参数condition的值为2，则比较书的作者*/ 
 		    return 1;  
       else 
		   return 0;    
	}
	else if (condition==3)                    /*如果参数condition的值为3，则比较总销量*/  
 		    return b1.total>b2.total;	  
	else return 1;                          /*其余情况返回1*/  
}  
  
 void reverse(Book bk[],int n)             /*数组元素逆置*/  
 {  
 	int i;  
 	Book temp;  
 	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/  
{  
		temp=bk[i];  
 	bk[i]=bk[n-1-i];  
 	bk[n-1-i]=temp;  
}  
 }  
 
 void calcuTotal(Book bk[],int n)         /*计算所有图书的总销量*/  
 {  
 	int i,j;  
 	for (i=0;i<n;i++)                    /*外层循环控制所有图书记录*/  
	{  
		bk[i].total =0;  
 	for (j=0;j<3;j++)                    /*内层循环控制每个月的销量*/  
 		bk[i].total+=bk[i].salevolume[j];  
	}	  
 }  
   
void season_sales_money(Book bk[],int n)       /*计算图书一个季度的销售额*/
{
  int i;
  calcuTotal(bk,n);
  for(i=0;i<n;i++)
     bk[i].sales_money=bk[i].price*bk[i].total;
}

 void calcuRank(Book bk[],int n)          /*根据总分计算所有图书的销量排名，相同者名次相同*/  
 {  
 int i ;                         
	sortBk(bk,n,2);                     /*先调用sortBk算法，按总分由小到大排序*/  
	reverse(bk,n);                      /*再逆置，则按总分由大到小排序了*/  
    bk[0].rank=1;                            /*第一条记录的名次一定是1*/  
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/  
	{   
 		if (equal(bk[i],bk[i-1],4))         /*当前记录与其相邻的前一条记录如果总分相等*/  
			   bk[i].rank=bk[i-1].rank;       /*当前记录名次等于其相邻的前一条记录名次*/   
	    else  
			bk[i].rank=i+1;                /*不相等时当前记录名次等于其下标号+1*/  
 	}  
}  
 
void calcuMark(double m[3][3],Book bk[],int n) /*求三个月的最高、最低、平均销量*/  
                                               /*其中形式参数二维数组m的第一维代表三个月的销量，第二维代表最高、最低、平均销量*/  
{  
 	int i,j;  
	for (i=0;i<3;i++)                 /*求三个月的最高销量*/ 		  
	{   
		m[i][0]=bk[0].salevolume[i];       
		for (j=1;j<n;j++)  
			if (m[i][0]<bk[j].salevolume[i])  
				  m[i][0]=bk[j].salevolume[i];  
	}  
	for (i=0;i<3;i++)                  /*求三个月的最低销量*/  
 	{   
 		m[i][1]=bk[0].salevolume[i];        
		for (j=1;j<n;j++)  
 			if (m[i][1]>bk[j].salevolume[i])  
				  m[i][1]=bk[j].salevolume[i];  
 	}  
	for (i=0;i<3;i++)                 /*求三个月的平均销量*/  
	{   
 		m[i][2]=bk[0].salevolume[i];       
 		for (j=1;j<n;j++)  
 			 m[i][2]+=bk[j].salevolume[i];  
 		m[i][2]/=n;  
	}  
 }  
  
 void sortBk(Book bk[],int n,int condition)        /*选择法排序，按condition条件由小到大排序*/  
 {  
 	int i,j,minpos;                             /*minpos用来存储本趟最小元素所在的下标*/  
 	Book t;  
 	for (i=0;i<n-1;i++)                          /*控制循环的n-1趟*/  
	{  
		minpos=i;  
		for (j=i+1;j<n;j++)                     /*寻找本趟最小元素所在的下标*/  
			if (larger(bk[minpos],bk[j],condition))  
				minpos=j;  
		if (i!=minpos)                         /*保证本趟最小元素到达下标为i的位置*/  
		{  
			t=bk[i];  
			bk[i]=bk[minpos];  
		        bk[minpos]=t;  
		}  
	}  
}  
  
int searchBk(Book bk[],int n,Book b,int condition,int f[ ])  /*在bk数组中依condition条件查找*/  
                                                            /*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/  
{  
	int i,j=0,find=0;  
 	for (i=0;i<n;i++)                                 /*待查找的元素*/  
 		if (equal(bk[i],b,condition))    
 		{  
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/  
			find++;	                         /*统计找到的元素个数*/                                
		}  
	 return find;                                /*返回find，其值为0则表示没找到*/   
}  
   
int insertBk(Book bk[],int n,Book b)              /*向bk数组中依书的编号递增插入一个元素bk*/  
{  
 	int i;  
 	sortBk(bk,n,1);                              /*先按书编号排序*/  
	for (i=0;i<n;i++)  
	{  
		if (equal(bk[i],b,1))                      /*书编号相同不允许插入，保证书编号的唯一性*/  
		{  
                   printf("this record exist,can not insert again!\n"); 
		    return n;  
		}  
	}  
	for (i=n-1;i>=0;i--)                          /*按学号从小到大有序*/  
	{  
		if (!larger(bk[i],b,1))                    /*如果b大于当前元素bk[i]，则退出循环*/  
	        	break;  
		bk[i+1]=bk[i];                         /*否则元素bk[i]后移一个位置*/  
	}  
	bk[i+1]=b;                                /*在下标i+1处插入元素s*/                                     
	n++;                                     /*元素个数增加1*/  
	return n;                                  /*返回现有元素个数*/  
}  
  
int deleteBk(Book bk[],int n,Book b)            /*从数组中删除指定书的编号的一个元素*/  
{  
	int i,j;
	for(i=0;i<n;i++)
		if (equal(bk[i],b,1))   
			break;                           /*如果找到相等元素则退出循环*/  
	if (i==n)                                 /*如果找不到待删除的元素*/  
	{  
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/  
		return n;  
	}  
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(bk[i],s,1)成立*/   
		bk[j]=bk[j+1];                       /*通过移动覆盖删除下标为i的元素*/  
                                                                            
	n--;                                      /*元素个数减少加1*/  
	return n;                                  /*返回现有个数*/  
}  