#include<stdio.h>
int main()
{
    //includes colour to the output.(blue)
    system("color 3f");
    int choice;
    printf("\tWELCOME TO PHONE BOOK!\n");
    printf("Select any option:\n");
    printf(" 1. Add New Contacts.\n");
    printf(" 2. Search Contacts.\n");
    printf(" 3. Delete Contacts.\n");
    printf(" 4. View List of Contacts.\n");
    printf(" 5. Exit the application.\n");
    printf("Enter Your Choice:-");
    scanf("%d",&choice);
    //switch case used.
    switch(choice)
    {
    case 1:
        AddContact();
        break;
    case 2:
        SearchContact();
        break;
    case 3:
        DeleteContact();
        break;
    case 4:
        ListContact();
        break;
    case 5:
        exit(0);
    default:
        main();
    }
}
int AddContact()
{
    FILE *fp;
    //a+ mode->opens a file for both reading and appending.file created if not existed.
    fp=fopen("mobilecontacts.txt","a+");
    printf("ADD CONTACTS:\n");
    printf("Enter Name  :");
    char name[20];
    scanf("%s",name);
    printf("Enter Mobile Number :" );
    char num[20];
    scanf("%s",num);
    printf("Enter email address");
    char email[30];
    scanf("%s",email);
    fprintf(fp,"%s %s %s\n",name,num,email);
    fclose(fp);
    printf("PRESS ANY KEY TO CONTINUE\n");
    getch();
    main();
}
int SearchContact()
{
    FILE *fp;
    //r mode->opens file in only read mode.does not create file if not existed.
    fp=fopen("mobilecontacts.txt","r");
    printf("SEARCH A CONTACT: \n");
    printf("Enter Name :");
    char name[20];
    scanf("%s",name);
    char name1[20],num1[20],email[30];
    while(fscanf(fp,"%s %s %s",name1,num1,email)!=EOF)
    {
        //strcmp compares two strings.
        if(strcmp(name,name1)==0)
        {
            printf("\tNAME           : %s\n",name1);
            printf("\tMOBILE NUMBER  : %s\n",num1);
            printf("\tEMAIL ADDRESS  : %s\n",email);
        }
    }
    fclose(fp);
    printf("\nPRESS ANY KEY TO CONTINUE\n");
    getch();
    main();
}
int DeleteContact()
{
    FILE *fp,*fp1;
    fp=fopen("mobilecontacts.txt","r+");
    //r+ mode ->both reading and writing possible.creates file if not existed.overwrites existing data.
    fp1=fopen("temporary.txt","w");
    //w mode ->opens file in write mode.file created if not existed.
    printf("\nDELETE CONTACT");
    printf("\n Enter Name :-");
    char name[20];
    scanf("%s",name);
    char name2[20],num2[20],email[30];
    while(fscanf(fp,"%s %s %s",name2,num2,email)!=EOF)
    {
        if(strcmp(name,name2)==0)
        {
            continue;
        }
        fprintf(fp1,"%s %s %s\n",name2,num2,email);
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("mobilecontacts.txt","w");
    fp1=fopen("temporary.txt","r");
    while(fscanf(fp1,"%s %s %s",name2,num2,email)!=EOF)
    {

        fprintf(fp,"%s %s %s\n",name2,num2,email);
    }
    fclose(fp);
    fclose(fp1);
    //remove() deletes filename so the content can no longer be accessed.
    remove("temporary.txt");
    printf("\nPRESS ANY KEY TO CONTINUE\n");
    getch();
    main();
}
int ListContact()
{
    FILE *fp;
    fp=fopen("mobilecontacts.txt","r");
    //opens file in read only mode.file not created if not existed.
    printf("\n LIST OF ALL CONTACTS:");
    char name[20],num1[20],email[30];
    while(fscanf(fp,"%s %s %s",name,num1,email)!=EOF)
    {
        printf("\n\t NAME           :  %s",name);
        printf("\n\t MOBILE NUMBER. :  %s",num1);
        printf("\n\t EMAIL ADDRESS  :  %s",email);
    }
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE\n");
    getch();
    main();
}
