#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct entry
{
char first_name[50];
char email_address[50];
char house_address[50];
char city[50];
char pincode[50];
struct entry *ptr_1;
struct entry *ptr_2;
}*temp,*new_entry,*l,*r;
typedef struct entry *list;
void new_record();
void display(char n[50]);
void delete_record(char n[50]);
void display_all();
void make_empty();
int is_empty();
void save_record();
void delete_all();
//function to add a new record to addressbook
void new_record()
{
int i,k=0;
new_entry=(struct entry*)malloc(sizeof(struct entry));//dynamic memory allocation
//getting data input from user
printf("Enter the Datas for the New Record: \n");
printf("Enter Your First name :\n");
scanf("%s",new_entry->first_name);
printf("Enter Your E-mail address :\n");
scanf("%s",new_entry->email_address);
printf("Enter Your House Address :\n");
scanf("%s",new_entry->house_address);
printf("Enter Your City Name :\n");
scanf("%s",new_entry->city);
printf("Enter Your Pincode   :\n");
scanf("%s",new_entry->pincode);
if(is_empty())
{
new_entry->ptr_1=new_entry->ptr_2=NULL;
l=r=new_entry;
printf("Your Record is Added\n");
}
else
 {
	 temp=l;
	 while(temp!=NULL)
  {
	  i=strcmp(new_entry->first_name,temp->first_name);
	 if(i<0)
	 break;
	 else if(i>0)
	  temp=temp->ptr_2;
	  else if(i==0)
	 {
		printf("Name already exists and hence record cannot be added\n");
	  k=1;
	  break;
	 }
	}
	 if(k!=1)
	 {
		if(temp==l)
	{
	  new_entry->ptr_1=NULL;
	  new_entry->ptr_2=l;
	  l->ptr_1=new_entry;
	  l=new_entry;
	  printf("Your Record is Added\n");
	 }
	 else if(temp==NULL)
	{
	  new_entry->ptr_2=NULL;
	  new_entry->ptr_1=r;
	  r->ptr_2=new_entry;
	  r=new_entry;
	  printf("Your Record is Added\n");
	 }
	 else
	{
	new_entry->ptr_2=temp;
	new_entry->ptr_1=temp->ptr_1;
	temp->ptr_1=new_entry;
	(new_entry->ptr_1)->ptr_2=new_entry;
	printf("Your Record is Added\n");
	}
  }
  }
}
//function to display all the records
void display_all()
{       int n=1;
if(!is_empty())
{
temp=l;
while(temp!=NULL)
{
printf("First Name      :%s \n",temp->first_name);
printf("E-mail address :%s\n",temp->email_address);
printf("House address:%s\n",temp->house_address);
printf("City      :%s \n",temp->city);
printf("Pin code :%s\n",temp->pincode);
printf("\n \n");
temp=temp->ptr_2;
n++;
}
}
else
printf("No records in address book \n");
}
//function to delete the records
void delete_record(char n[50])
{
int i;
if(is_empty())
printf("No records in address book \n");
else{
temp=l;
while(temp!=NULL)
{
i=stricmp(temp->first_name,n);
if(i==NULL)
{
if(l==r)
{
l=r=NULL;
printf("Record is deleted \n");
break;
}
else if(temp==l)
  {
  l=l->ptr_2;
  l->ptr_1=NULL;
  printf("Record is deleted \n");
  break;
  }
else if(temp==r)
{
r=r->ptr_1;
r->ptr_2=NULL;
printf("Record is deleted \n");
break;
}
else{
(temp->ptr_1)->ptr_2=temp->ptr_2;
(temp->ptr_2)->ptr_1=temp->ptr_1;
printf("Record is deleted \n");
break;
}
}
temp=temp->ptr_2;

}
if(temp==NULL)
printf("Sorry, Data Not Found \n");
}
}
int is_empty()
{
return l==NULL;
}
//function to make addressbook empty
void make_empty()
{
l=r=NULL;
printf("No records in Address book \n");
}
//function to display the addressbook
void display(char n[50])
{
int i,p=1;
if(is_empty())
printf("No records in Address book \n");
else
{
temp=l;
while(temp!=NULL)
{
i=stricmp(temp->first_name,n);
if(i==NULL)
{
if(p==1)
printf("Record is found in %dst location \n",p);
else if(p==2)
printf("Record is found in %dnd location \n",p);
else if (p==3)
printf("Record is found in %drd location \n",p);
else
printf("Record is found in %dth location\n",p);
printf("First Name      :%s \n",temp->first_name);
printf("E-mail address :%s \n",temp->email_address);
printf("House address:%s \n",temp->house_address);
printf("City:%s \n",temp->city);
printf("Pin code:%s\n",temp->pincode);
break;
}
temp=temp->ptr_2;
p++;
}
if(temp==NULL)
printf("Record Not Found \n");

}
}
void main()
{
int l=1,m;
char n[50];
while(l!=8)
{
printf("ADDRESS BOOK USING LINKED LIST \n");
printf("Enter Your Choice \n");
printf("(1)-New Record \n");
printf("(2)-Display a Record \n");
printf("(3)-Delete a Record \n");
printf("(4)-Display all Records \n");
printf("(5)-Empty the Address book \n");
printf("(6)-Save Record in folder \n");
printf("(7)-Delete All The Saved Files \n");
printf("(8)-End\n");
scanf("%d",&l);
switch(l)
{
case 1:
new_record();
getch();
break;
case 2:
printf("Enter the person's name which is to be displayed \n");
printf("");
scanf("%s",&n);
display(n);
getch();
break;
case 3:
printf("Enter the person's name which is to be deleted \n");
printf("");
scanf("%s",&n);
delete_record(n);
getch();
break;
case 4:
display_all();
getch();
break;
case 5:
make_empty();
getch();
break;
case 6:
save_record();
getch();
break;
case 7:
delete_all();
getch();
break;
case 8:
printf("End of Program");
printf("");
getch();
break;
default:
printf("Enter a Valid Choice (between 1-8 only) \n");
printf("");
getch();
break;
}
}
getch();
}
//function to save the record in the addressbook
void save_record()
{
char n[50];
int c;
printf("Enter the Person's name \n");
scanf("%s",n);
list t;
if(is_empty())
printf("No records in the address book \n");
else
{
FILE *f;
f=fopen("addressbook.txt","a");
int i;
int t=l;
while(t!=NULL)
{
i=stricmp(t->first_name,n);
if(i==0)
{
fprintf(f,"First name:%s \n Email:%s \n House Address: %s \n City: %s \n Pincode: %s \n\n",t->first_name,t->email_address,t->house_address,t->city,t->pincode);
printf("Your Record is Saved");
printf("Add Another Record");
printf(" (1 for yes/2 for no)");
scanf("%d",&c);
if(c==1)
save_record();
else if(c==2)
break;
}
t=t->ptr_2;
}
fclose(f);
if(t==NULL)
printf("No such record is found \n");
}
//function to delete all the saved records in the addressbook
}
	void delete_all()
	{
	FILE *f;
	f=fopen("addressbook.txt","w");
	fclose(f);
	printf("All the saved files are emptied");
	}
