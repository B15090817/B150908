/*li12_1.c*/  
#include<stdio.h>  
#include<stdlib.h>  
#include"file.h"  
#include"Book.h"  
void printHead( )               /*��ӡͼ����Ϣ�ı�ͷ*/  
{
     printf("%8s%10s%8s%6s%6s%8s%8s%8s%10s\n","ͼ����","����","����","һ��","����","����","������","���۶�","�ܻ�ӭ�̶�");  
}   
void menu( )         /*����˵�����*/  
{  
 printf("******** 1. ��ʾ������Ϣ ********\n");  
 printf("******** 2. ������Ϣ���� ********\n");  
 printf("******** 3. ͼ����Ϣ���� ********\n");  
 printf("******** 4. ͼ������ͳ�� ********\n");  
 printf("******** 5. ����������ѯ ********\n");  
 printf("******** 0. �˳�         ********\n");  
 } 
 void menuBase( )     /*2��������Ϣ����˵�����*/  
 {  
 		printf("%%%%%%%% 1. ����ͼ���¼ %%%%%%%%\n");  
 		printf("%%%%%%%% 2. ɾ��ͼ���¼ %%%%%%%%\n");  
 		printf("%%%%%%%% 3. �޸�ͼ���¼ %%%%%%%%\n");  
 		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");  
 }  
 void menuScore( )     /*3��ͼ����������˵�����*/  
 {  
 		printf("@@@@@@@@ 1. �����鼮������ @@@@@@@@\n");  
 		printf("@@@@@@@@ 2. �������������� @@@@@@@@\n");  
 		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");  
 }    
 void menuCount( )    /*4��������Ϣͳ�Ʋ˵�����*/  
 {  
 		printf("&&&&&&&& 1. ��������� &&&&&&&&\n");  
 		printf("&&&&&&&& 2. ��������� &&&&&&&&\n");  
 		printf("&&&&&&&& 3. ƽ������ &&&&&&&&\n");  
 		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");  
 }  
   
 void menuSearch()    /*5������������ѯ�˵�����*/  
 {  
 	    printf("######## 1. ����Ų�ѯ   ########\n");  
 		printf("######## 2. �����߲�ѯ   ########\n");  
 		printf("######## 3. ���ȶȲ�ѯ   ########\n");  
	    printf("######## 0. �����ϲ�˵� ########\n");  
 }  
  
 int baseManage(Book bk[],int n)    	     /*�ú�����ɻ�����Ϣ����*/  
 /*�����Ž��в���ɾ���޸ģ���Ų����ظ�*/  
 {    
 	int choice,t,find[NUM];  
    Book b;  
    do  
	{     
     menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/  
     printf("choose one operation you want to do:\n");  
     scanf("%d",&choice);	          /*����ѡ��*/  
	 switch(choice)  
		  {  
 		   case 1:	 readBk(&b,1);                 /*����һ���������ͼ���¼*/  
			         n=insertBk(bk,n,b);               /*���ú�������ͼ���¼*/  
 					 break;  
		   case 2:  printf("Input the ISBN ofthebook deleted\n");  
 					 scanf("%s",&b.ISBN);          /*����һ����ɾ����ͼ����*/  
 					 n=deleteBk(bk,n,b);           /*���ú���ɾ��ָ��ͼ���ŵ�ͼ���¼*/  
 					 break;  
 		   case 3:  printf("Input the number modified\n");  
 					scanf("%s",&b.ISBN);            /*����һ�����޸ĵ�ͼ����*/  
 				    t=searchBk(bk,n,b,1,find) ;        /*���ú�������ָ��ͼ���ŵ�ͼ���¼*/  
 				    if (t)                         /*�����ѧ�ŵļ�¼����*/  
 					 {  
 						  readBk(&b,1);      /*����һ��������ͼ���¼��Ϣ*/  
 					      bk[find[0]]=b;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					   
 					 }					   
 					else                 /*�����ͼ��ŵļ�¼������*/   
                        printf("this Book is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/  
 					break;  
 		   case 0: break;  
 		   }  
 	}while(choice);  
 return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/  
 }  
 void scoreManage(Book bk[],int n)          /*�ú������ͼ������������*/  
 {    
 	int choice;  
 	do  
 	{  
 		menuScore( );                            /*��ʾ��Ӧ�Ķ����˵�*/  
 		printf("choose one operation you want to do:\n");  
 		scanf("%d",&choice);	                 /*�������ѡ��*/  
 		switch(choice)  
 		{  
 			case 1:   calcuTotal(bk,n);         /*������ͼ���������*/  
 					  break;  
 			case 2:   calcuRank(bk,n);         /*��������ͼ��������������Σ�����Ϊͼ���ȶȣ�*/  
 				      break;		  
 			case 0:   break;  
 		}  
 	}while(choice);  
 }
 
  void printSalevolume(char *s,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/  
 {                                                  /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ������������������ƽ������*/  
     int i;
	 printf("%6s%6s%6s\n","һ��","����","����");
     printf(s);                                  /*�����s������������������ʾ��Ϣ*/  
     for (i=0;i<3;i++)                           /*i������һ���µ�����*/  
 		  printf("%10.2lf",m[i][k]);  
 	   printf("\n");  
 }  
   
 void countManage(Book bk[],int n)               /*�ú����������ͳ�ƹ���*/  
 {  
 		int choice;  
 		double mark[3][3];  
 		do  
 		{  
 			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/  
 			calcuMark(mark,bk,n);                 /*���ô˺����������µ�������������������ƽ������*/  
 			printf("choose one operation you want to do:\n");  
 			scanf("%d",&choice);  
 			switch(choice)  
 			{  
 				case 1:   printSalevolume("ÿ����߷ֱַ���:\n",mark,0);  /*���ÿ�����������*/  
 				      break;  
 				case 2:   printSalevolume("ÿ����ͷֱַ���:\n",mark,1);  /*���ÿ�����������*/  
 				      break;  
 				case 3:   printSalevolume("���µ�ƽ���ֱַ���:\n",mark,2);  /*���ÿ�ֵ�ƽ������*/  
 				      break;  
 				case 0:   break;  
 			}  
 		}while (choice);  
 }  
   
 void searchManage(Book bk[],int n)               /*�ú�����ɸ���������ѯ����*/  
 {  
     int i,choice,findnum,f[NUM];  
     Book b;  
 	   do  
 {  
 			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/  
 			printf("choose one operation you want to do:\n");  
 			scanf("%d",&choice);  
 			switch(choice)  
 			{  
 				case 1:   printf("Input a Book's ISBN will be searched:\n");  
 				      scanf("%s",b.ISBN);         /*�������ѯ�鼮�ı��*/  
 					  break;  
 				case 2:   printf("Input a Book's name will be searched:\n");  
 				      scanf("%s",b.name);	          /*�������ѯͼ����*/		    
 				      break;     
 				case 3:   printf("Input a rank will be searched:\n");  
 				      scanf("%d",&b.rank);          /*�������ѯͼ����ȶ�*/ 
				case 4:   printf("Input the auther_name will be searched:\n");  
 				      scanf("%d",&b.rank);          /*�������ѯͼ�������*/ 
 					  break;  
 				case 0:   break;  
 			}  
 		 	if (choice>=1&&choice<=4)  
 			{   
 			  findnum=searchBk(bk,n,b,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/  
 			  if (findnum)				     /*������ҳɹ�*/  
				{  
 			   		 printHead( );                  /*��ӡ��ͷ*/  
 					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/  
 	      	              printBk(&bk[f[i]],1);      /*ÿ�����һ����¼*/  
 				}  
 		      else  
 			    	    printf("this record does not exist!\n");    /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/  
 		     }		  
 	    }while (choice);  
 }  
   
 int runMain(Book bk[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/  
 {  
 		switch(choice)  
 		{  
 			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/  
 				 sortBk(bk,n,1);         /*��ͼ������С�����˳�������¼*/   
           	 printBk(bk,n);          /*��ͼ������С�����˳��������м�¼*/  
 					break;  
 			case 2: n=baseManage(bk,n);    /* 2. ������Ϣ����*/  
 			   	     break;  
 			case 3: scoreManage(bk,n);     /* 3. ͼ����Ϣ����*/  
 					break;  
 			case 4: countManage(bk,n);     /* 4. ͼ������ͳ��*/  
 					break;  
 			case 5: searchManage(bk,n);     /* 5. ����������ѯ*/  
 				     break;  
           case 0: break;  
 		}  
 		return n;  
 }  
  
 int main( )  
 {  
 	   Book bk[NUM];                /*����ʵ��һά����洢ͼ���¼*/  
       int choice,n;  
 	   n=readFile(bk);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/  
     	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/  
 	     {  
 		    n=createFile(bk);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/  
		 }	 	   
 	     do  
 	     {  
 	         menu();                      /*��ʾ���˵�*/  
 	         printf("Please input your choice: ");  
 	         scanf("%d",&choice);  
 	         if (choice>=0&&choice<=5)  
 	              n=runMain(bk,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/  
 	         else   
 		          printf("error input,please input your choice again!\n");  
 	} while (choice);  
 	      sortBk(bk,n,1);                   /*�����ļ�ǰ��ѧ����С��������*/   
 	     saveFile(bk,n);                   /*����������ļ�*/  
       return 0;  
 }
