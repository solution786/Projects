#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>

struct Information
{
	char name[30];
	char phoneNumber[10];
	char address[30];
	char email[30];
	
}info;

void fordelay(int j)
{   
	int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void loading()
{
	int i;
	printf("LOADING");
    for(i=1;i<6;i++)
    {
        fordelay(100000000);
        printf(".");
    }
}

void addContact()
{
	FILE *fp;
	fp = fopen("contactRecord.txt","w");
	if(fp==NULL)
	{
		printf("\n\n File cannot be opened.");
		return;
	}else{
		fflush(stdin);
		printf("\nEnter Name:  ");
		gets(info.name);
		printf("\nEnter phoneNumber:  ");
		gets(info.phoneNumber);
		fflush(stdin);
		printf("\nEnter address:  ");
		gets(info.address);
		printf("\nEnter email:  ");
		gets(info.email);
		fwrite(&info,sizeof(info),1,fp);
	}
	fclose(fp);
}

void appendContact()
{
	FILE *fp;
	fp = fopen("contactRecord.txt","a+");
	if(fp==NULL)
	{
		printf("\n\n File cannot be opened.");
		return;
	}
	else
	{
		fflush(stdin);
		printf("\nEnter Name:  ");
		gets(info.name);
		printf("\nEnter phoneNumber:  ");
		gets(info.phoneNumber);
		fflush(stdin);
		printf("\nEnter address:  ");
		gets(info.address);
		printf("\nEnter email:  ");
		gets(info.email);
		fwrite(&info,sizeof(info),1,fp);
	}
	fclose(fp);
}

void deleteContact()
{
	FILE *fp,*temp;
    char name[30];
    int found=0;
    fp= fopen("contactRecord.txt","r");
    temp=fopen("tempFile.txt","w");
    fflush(stdin);
    printf("\nEnter the name to be delete:  ");
    gets(name);
    if(fp==NULL && temp==NULL)
    {
    	printf("\nFile cannot open.");
    	exit(0);
	}
	else{
		while(fread(&info,sizeof(info),1,fp)>0)
		{
			if(strcmp(info.name,name)==0)
			{
				found = 1;	
				printf("\nRecord delete successfully");		
			}
			else{
				fwrite(&info,sizeof(info),1,temp);
			}
			
		}
		fclose(fp);
		fclose(temp);
		if(found==1)
		{
			fp = fopen("contactRecord.txt","w");
			temp = fopen("tempFile.txt","r");
			while(fread(&info,sizeof(info),1,temp)>0)
			{
				fwrite(&info,sizeof(info),1,fp);
			}
			fclose(fp);
			fclose(temp);
		}
		else{
			printf("\nRecord not found");
		}
	}
	
}

void updateContact()
{
    FILE *fp,*temp;
    char name[30];
    int found=0;
    fp= fopen("contactRecord.txt","r");
    temp=fopen("tempFile.txt","w");
    fflush(stdin);
    printf("\nEnter the name to be update:  ");
    gets(name);
    if(fp==NULL && temp==NULL)
    {
    	printf("\nFile cannot open.");
    	exit(0);
	}
	else{
		while(fread(&info,sizeof(info),1,fp)>0)
		{
			if(strcmp(info.name,name)==0)
			{
				found = 1;
				printf("\nEnter the new details: ");
				printf("\n===========================");
				fflush(stdin);
				printf("\nEnter Name:  ");
				gets(info.name);
				printf("\nEnter phoneNumber:  ");
				gets(info.phoneNumber);
				fflush(stdin);
				printf("\nEnter address:  ");
				gets(info.address);
				printf("\nEnter email:  ");
				gets(info.email);
			
			}
			fwrite(&info,sizeof(info),1,temp);
		}
		fclose(fp);
		fclose(temp);
		if(found==1)
		{
			fp = fopen("contactRecord.txt","w");
			temp = fopen("tempFile.txt","r");
			while(fread(&info,sizeof(info),1,temp)>0)
			{
				fwrite(&info,sizeof(info),1,fp);
			}
			fclose(fp);
			fclose(temp);
		}
		else{
			printf("\nRecord not found");
		}
	}
	
}

void listContact()
{
	FILE *fp;
	struct Information info;
	fp=fopen("contactRecord.txt","r");
	if(fp==NULL)
	{
		printf("\nFile cannot be opened.");
		exit(1);
	}
	while(fread(&info,sizeof(info),1,fp)>0)
	{
		printf("\nName:  ");
		puts(info.name);
		printf("\nPhone Numnber:  ");
		puts(info.phoneNumber);
		printf("\nAddress:  ");
		puts(info.address);
		printf("\nEmail:  ");
		puts(info.email);
		printf("**********************************************************************\n");
		
		
	}
	fclose(fp);
	
}

int main()
{
	int choice,password=123456,pass;
	system("cls");
	loading();
  TryAgain:
  	system("cls");
	printf("\nEnter the password to login:  ");
	scanf("%d",&pass);
	if(pass == password)
	{
		goto mainMenu;
	}else{
		goto TryAgain;
	}
  mainMenu:
  	system("cls");
	printf("*************** WELCOME TO CONTACT MANAGEMENT SYSTEM ***************");
	printf("\n--------------------------------------------------------------------");
	printf("\n\n\n================== MAIN MENU =======================");
	printf("\n[1]. ADD CONTACT ");
	printf("\n[2]. DELETE CONTACT");
	printf("\n[3]. APPEND CONTACT");
	printf("\n[4]. LIST CONTACT");
	printf("\n[5]. UPDATE CONTACT");
	printf("\n[6]. EXIT");
	while(choice!=6)
	{
		choice:
			printf("\n\n Enter your choice:  ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					//system("cls");
					printf("\n\n######### ADD CONTACT ##########");
					printf("\n----------------------------------");
					addContact();
					break;
					
				case 2:
					//system("cls");
					printf("\n\n######### DELETE CONTACT ##########");
					printf("\n----------------------------------");
					deleteContact();
					break;
					
				case 3:
					//system("cls");
					printf("\n\n######### APPEND CONTACT ##########");
					appendContact();
					break;
					
				case 4:
					//system("cls");
					printf("\n\n######### LIST ALL CONTACTS ##########");
					printf("\n----------------------------------");
					listContact();
					break;
					
				case 5:
					//system("cls");
					printf("\n\n######### UPDATE CONTACT ##########");
					printf("\n----------------------------------");
					updateContact();
					break;
					
					
				case 6:
					exit(1);
					break;
					
				default:
					printf("\nInvalid Choice.");
					goto choice;
					break;
			}
	}

	
}
