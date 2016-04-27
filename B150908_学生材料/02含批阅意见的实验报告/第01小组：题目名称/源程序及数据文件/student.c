/*��book.c�ļ�����������*/  
#include "Book.h"  
#include <stdio.h>  
  
int readBk(Book*bk ,int n)          /*����ͼ���¼ֵ��ͼ����Ϊ0������涨������¼ʱֹͣ*/  
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
      scanf("%s",bk[i].category);                  /*������*/
    printf("auther_name:  ");
      scanf("%s",bk[i].auther_name);                /*����*/
   	printf("remain:  ");
	  scanf("%d",&bk[i].remain);                    /*�����ʼ���*/
	printf("Input three months of the Book:\n");  
	for (j=0;j<3;j++)  
    {  
	    scanf("%d",&bk[i].salevolume[j]);	  
    }  
		bk[i].rank=0;                 /*������Ҫ�����ܷ������㣬��ֵ��Ϊ0*/ 
        bk[i].total=0;               /*��������Ҫ������ã���ֵ��Ϊ0*/ 
		bk[i].sales_money=0;
	}  
	return i;                         /*����ʵ�ʶ���ļ�¼����*/  
}  
   
 void printBk (Book*bk,int n)       /*�������ѧ����¼��ֵ*/  
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
   
 int equal(Book b1,Book b2,int condition)  /*����ж�����Book��¼���*/  
 {  
	if (condition==1)                  /*�������condition��ֵΪ1����Ƚ�����*/  
	{	
		if (strcmp(b1.ISBN,b2.ISBN)==0) 
 		    return 1;  
        else 
		   return 0; 
	}
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/  
     {  
       if (strcmp(b1.name,b2.name)==0) 
 		    return 1;  
       else 
		   return 0;  
    }  
    else if (condition==3)                /*�������condition��ֵΪ3����Ƚ���������(�ȶ�)*/  
 	     return b1.rank==b2.rank;  
    else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��������*/ 
	{
	 if (strcmp(b1.auther_name,b2.auther_name)==0) 
 		   return 1;  
	 else 
		   return 0; 
	}
	else return 1;                       /*�����������1*/  
 }   
  
int larger(Book b1,Book b2,int condition)  /*����condition�����Ƚ�����Book��¼�Ĵ�С*/  
 {  
	if (condition==1)                      /*�������condition��ֵΪ1����Ƚ�����*/ 
	{	
		if (strcmp(b1.ISBN,b2.ISBN)==1) 
 		    return 1;  
       else 
		   return 0;                         /*	return s1.num>s2.num;*/
	} 
	else if(condition==2)
	{
	 if (strcmp(b1.auther_name,b2.auther_name)==1)  /*�������condition��ֵΪ2����Ƚ��������*/ 
 		    return 1;  
       else 
		   return 0;    
	}
	else if (condition==3)                    /*�������condition��ֵΪ3����Ƚ�������*/  
 		    return b1.total>b2.total;	  
	else return 1;                          /*�����������1*/  
}  
  
 void reverse(Book bk[],int n)             /*����Ԫ������*/  
 {  
 	int i;  
 	Book temp;  
 	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/  
{  
		temp=bk[i];  
 	bk[i]=bk[n-1-i];  
 	bk[n-1-i]=temp;  
}  
 }  
 
 void calcuTotal(Book bk[],int n)         /*��������ͼ���������*/  
 {  
 	int i,j;  
 	for (i=0;i<n;i++)                    /*���ѭ����������ͼ���¼*/  
	{  
		bk[i].total =0;  
 	for (j=0;j<3;j++)                    /*�ڲ�ѭ������ÿ���µ�����*/  
 		bk[i].total+=bk[i].salevolume[j];  
	}	  
 }  
   
void season_sales_money(Book bk[],int n)       /*����ͼ��һ�����ȵ����۶�*/
{
  int i;
  calcuTotal(bk,n);
  for(i=0;i<n;i++)
     bk[i].sales_money=bk[i].price*bk[i].total;
}

 void calcuRank(Book bk[],int n)          /*�����ּܷ�������ͼ���������������ͬ��������ͬ*/  
 {  
 int i ;                         
	sortBk(bk,n,2);                     /*�ȵ���sortBk�㷨�����ܷ���С��������*/  
	reverse(bk,n);                      /*�����ã����ܷ��ɴ�С������*/  
    bk[0].rank=1;                            /*��һ����¼������һ����1*/  
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/  
	{   
 		if (equal(bk[i],bk[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/  
			   bk[i].rank=bk[i-1].rank;       /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/   
	    else  
			bk[i].rank=i+1;                /*�����ʱ��ǰ��¼���ε������±��+1*/  
 	}  
}  
 
void calcuMark(double m[3][3],Book bk[],int n) /*�������µ���ߡ���͡�ƽ������*/  
                                               /*������ʽ������ά����m�ĵ�һά���������µ��������ڶ�ά������ߡ���͡�ƽ������*/  
{  
 	int i,j;  
	for (i=0;i<3;i++)                 /*�������µ��������*/ 		  
	{   
		m[i][0]=bk[0].salevolume[i];       
		for (j=1;j<n;j++)  
			if (m[i][0]<bk[j].salevolume[i])  
				  m[i][0]=bk[j].salevolume[i];  
	}  
	for (i=0;i<3;i++)                  /*�������µ��������*/  
 	{   
 		m[i][1]=bk[0].salevolume[i];        
		for (j=1;j<n;j++)  
 			if (m[i][1]>bk[j].salevolume[i])  
				  m[i][1]=bk[j].salevolume[i];  
 	}  
	for (i=0;i<3;i++)                 /*�������µ�ƽ������*/  
	{   
 		m[i][2]=bk[0].salevolume[i];       
 		for (j=1;j<n;j++)  
 			 m[i][2]+=bk[j].salevolume[i];  
 		m[i][2]/=n;  
	}  
 }  
  
 void sortBk(Book bk[],int n,int condition)        /*ѡ�����򣬰�condition������С��������*/  
 {  
 	int i,j,minpos;                             /*minpos�����洢������СԪ�����ڵ��±�*/  
 	Book t;  
 	for (i=0;i<n-1;i++)                          /*����ѭ����n-1��*/  
	{  
		minpos=i;  
		for (j=i+1;j<n;j++)                     /*Ѱ�ұ�����СԪ�����ڵ��±�*/  
			if (larger(bk[minpos],bk[j],condition))  
				minpos=j;  
		if (i!=minpos)                         /*��֤������СԪ�ص����±�Ϊi��λ��*/  
		{  
			t=bk[i];  
			bk[i]=bk[minpos];  
		        bk[minpos]=t;  
		}  
	}  
}  
  
int searchBk(Book bk[],int n,Book b,int condition,int f[ ])  /*��bk��������condition��������*/  
                                                            /*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/  
{  
	int i,j=0,find=0;  
 	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/  
 		if (equal(bk[i],b,condition))    
 		{  
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/  
			find++;	                         /*ͳ���ҵ���Ԫ�ظ���*/                                
		}  
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/   
}  
   
int insertBk(Book bk[],int n,Book b)              /*��bk����������ı�ŵ�������һ��Ԫ��bk*/  
{  
 	int i;  
 	sortBk(bk,n,1);                              /*�Ȱ���������*/  
	for (i=0;i<n;i++)  
	{  
		if (equal(bk[i],b,1))                      /*������ͬ��������룬��֤���ŵ�Ψһ��*/  
		{  
                   printf("this record exist,can not insert again!\n"); 
		    return n;  
		}  
	}  
	for (i=n-1;i>=0;i--)                          /*��ѧ�Ŵ�С��������*/  
	{  
		if (!larger(bk[i],b,1))                    /*���b���ڵ�ǰԪ��bk[i]�����˳�ѭ��*/  
	        	break;  
		bk[i+1]=bk[i];                         /*����Ԫ��bk[i]����һ��λ��*/  
	}  
	bk[i+1]=b;                                /*���±�i+1������Ԫ��s*/                                     
	n++;                                     /*Ԫ�ظ�������1*/  
	return n;                                  /*��������Ԫ�ظ���*/  
}  
  
int deleteBk(Book bk[],int n,Book b)            /*��������ɾ��ָ����ı�ŵ�һ��Ԫ��*/  
{  
	int i,j;
	for(i=0;i<n;i++)
		if (equal(bk[i],b,1))   
			break;                           /*����ҵ����Ԫ�����˳�ѭ��*/  
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/  
	{  
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/  
		return n;  
	}  
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(bk[i],s,1)����*/   
		bk[j]=bk[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/  
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/  
	return n;                                  /*�������и���*/  
}  