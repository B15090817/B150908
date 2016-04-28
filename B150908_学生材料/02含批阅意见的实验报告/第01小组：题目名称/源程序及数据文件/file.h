 /*�� file.h�ļ����������£�*/  
 #include <stdio.h>  
 #include <stdlib.h>  
 #include "Book.h"          
 int  createFile(Book bk[ ])              /*������ʼ�������ļ�*/  
 {  
	FILE *fp;  
	int n;  
   	if((fp=fopen("d:\\Book.dat", "wb")) == NULL)     /*ָ�����ļ�������д�뷽ʽ��*/  
 	{  
 	    printf("can not open file !\n");            /*����ʧ�ܣ������ʾ��Ϣ*/  
        exit(0);                                /*Ȼ���˳�*/  
     }  
 	printf("input Books'information:\n");  
   	n=readBk(bk,NUM);                        /*����Book.h�еĺ���������*/  
    fwrite(bk,sizeBk,n,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/  
  	fclose(fp);                             /*�ر��ļ�*/  
 	return n;  
 }  
   
 int readFile(Book bk[ ] )                     /*���ļ��е����ݶ������ڽṹ������bk��*/  
 {  
    FILE *fp;  
    int i=0;  
    if((fp=fopen("d:\\Book.dat", "rb")) == NULL)      /*�Զ��ķ�ʽ��ָ���ļ�*/  
		{  
 	       printf("file does not exist,create it first:\n");  /*�����ʧ�������ʾ��Ϣ*/  
 	        return 0;                              /*Ȼ�󷵻�0*/  
		}	   
    fread(&bk[i],sizeBk,1,fp);                   /*������һ����¼*/  
    while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/  
		{  
		    i++;  
 	    	fread(&bk[i],sizeBk,1,fp);              /*�ٶ�����һ����¼*/  
		}  
 	fclose(fp);                                /*�ر��ļ�*/  
 	return i;                                  /*���ؼ�¼����*/  
 }  
   
 void saveFile(Book bk[],int n)                  /*���ṹ�����������д���ļ�*/  
 {   			  
   	FILE *fp;	  
    if((fp=fopen("d:\\Book.dat", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/  
		{  
 		printf("can not open file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/  
		exit(0);                                  /*Ȼ���˳�*/  
		}  
 	fwrite(bk,sizeBk,n,fp);          
	fclose(fp);  
}

