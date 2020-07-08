#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define P printf
#define S scanf
#include "fileHandling.h"
#include "Formatting.h"
int perform_login();
int fill_form();
int allow_admin();
void search();
void find_hotel(int);
void show_menu(int);
void administrate();
int options_for_validation()
{
	char ch,buffer;
	int choice;
	int flag=0,status;
	P("\nEnter 1 to login as user, 2 to register as a new customer, 3 to login as admin, 4 to exit\n");
	
	S("%d",&choice);
	S("%c",&buffer);
	switch(choice)
	{
	case 1: //Login of existing user
	status=perform_login();
	return status;
	case 2: //Registration of new user
	flag=fill_form();
	if(flag==-1)
	return 20;
	return 21;
	case 3:
	status=allow_admin();
	if(status!=1)
	return 30;
	return 31;
	case 4:return 4;
	}

}
void validation()
{
	int ch,hotel_code;
	char item[100];
	int authentication_level=options_for_validation();
	while(1){
	if(authentication_level==11)
	{
		P("Enter 1 to view restaurants, 2 to search restaurant by items/menu, 3 to search by cuisine\n");
		S("%d",&ch);
		switch(ch)
		{
		case 1:
		P("The restaurants in our database are:\n");
		FILE *fp;
		fp=fopen("restaurant.txt","r");
		 while( ( ch = fgetc(fp) ) != EOF )
      		P("%c",ch);
		P("The number preceeding the hotel name is the code. Kindly enter the relevant code:\n");
		S("%d",&hotel_code);
		find_hotel(hotel_code);
		show_menu(hotel_code);
		break;
		case 2:
		P("Enter item to search (for example, try searching Custard)\n");
		S("%s",item);
		search(item);
		}		
		break;
	}
	else if(authentication_level==21)
	{
		P("You have registered successfully\n");
		/*P("You can now login-->\n");
		perform_login();*/
		break;
	}
	else if(authentication_level==31)
	{
		P("Welcome admin\n");
		administrate();
		
		break;
	}
	else if(authentication_level==4)
	{
		return;
	}
	else
		authentication_level=options_for_validation();
		
	}
}

void remove_blanks()
{
	FILE *srcFile,*tempFile;
	srcFile  = fopen("login_db.txt", "r");
	 tempFile = fopen("remove-blanks.txt", "w");
	rewind(srcFile);
        removeEmptyLines(srcFile,tempFile);
	fclose(srcFile);
	fclose(tempFile);
	copyFiles("remove-blanks.txt","login_db.txt");
	srcFile  = fopen("register.txt", "r");
	 tempFile = fopen("remove-blanks.txt", "w");
	rewind(srcFile);
        removeEmptyLines(srcFile,tempFile);
	fclose(srcFile);
	fclose(tempFile);
	copyFiles("remove-blanks.txt","register.txt");
}

int getItemNumber(char b[][1000],int index,int len)
{
	int i,j,c=0;
	for(i=0;i<index;i++)
	{
		for(j=0;b[i][j];j++)
		{
			if(b[i][j]=='!')
			c++;
		}
	}
	return c;
}
void token(char s[],int hotel_index)
{
	int f=0,p=0,i,k=0;
	char b[10000],ch;
	for(i=0;s[i];i++)
	{
	if(s[i]=='\n')
	{
	k++;
	if(k==hotel_index)
	break;
	}
	else
	{
	if(k==hotel_index-1)
	{
		f++;
		b[p++]=s[i];
	}
	}
	}
	b[p++]='\0';
	P("%s\n",b);
}
void find_hotel(int hotel_index)
{
	FILE *fp;
	fp=fopen("restaurant.txt","r");
	char buffer[10000],ch,hotel_name[100];
	int k=0;
	while( ( ch = fgetc(fp) ) != EOF )
	{
		buffer[k++]=ch;
	}
	
	token(buffer,hotel_index);
}
void accept_order(int hotel_code)
{
	FILE *fp,*fp2;
	int code[100],quantity[100];
	char buffer[1000],price[100],item[100],line[100];
	int k=0,ch,i,num,flag=1,f=0,p=0,x=0,in=0,total=0;
	fp=fopen("temp.txt","r");
	do
	{
		
		rewind(fp);		
		P("Enter code for item you wish to add\n");
		S("%d",&code[k]);
		P("Enter quantity\n");
		S("%d",&quantity[k]);
		while ((fgets(buffer, 1000, fp)) != NULL)
		{
		//P("buffer %s\n",buffer);
		f=0;
		p=0;
		x=0;
		flag=1;
		strcpy(price,"");
		strcpy(item,"");
		for(i=0;buffer[i];i++)
		{
			//P("To: %s\n",buffer);
			if(isdigit(buffer[i]) && flag==1)
			{
			num=buffer[i]-'0';
			if(num==code[k]){
			f=1;
			
			}
			else
			break;
			}
			else if(f==1 && buffer[i]==' ')
			{
				f++;
				flag=0;
			}
			else if(flag==0 && f==2 && isdigit(buffer[i]))
			{
				//P("Price %c\n",buffer[i]);
				price[x++]=buffer[i];
			}
			else if(f==2 && buffer[i]==' ')
			{
				price[x]='\0';
				f++;
			}
			else if(f==3 && (isalpha(buffer[i])||buffer[i]==' '))
			{
				item[p++]=buffer[i];
			}
			else{
				item[p]='\0';
				
			}
		}
		if(item!="" && price!="")
		{
			fp2=fopen("final_bill.txt","w");
			for(i=0;i<p;i++){
			//if(item[i]!=' ')
			line[in++]=item[i];
			}
			line[in++]=' ';
			for(i=0;i<x;i++){
			//if(price[i]!=' ')
			line[in++]=price[i];
			}			
		}
		//P("Price %s %d Qty %d\n",price,atoi(price),quantity[k]);
		total+=atoi(price)*quantity[k];
		
		}
		
		line[in++]=' ';
		line[in++]=quantity[k]+'0';
		line[in++]='\n';
		fputs(line,fp2);
		k++;
		
		//P("check %s %s\n",item,price);
		P("\nEnter 1 to continue, 0 if order is complete\n");
		S("%d",&ch);
	}while(ch==1); 
	//P("Total %d\n",total);
	char str[100];
	sprintf(str,"%d",total);
	fputs("Total: ",fp2);
	fputs(str,fp2);
	fclose(fp2);
	P("*********************\n");
	P("Bill generated:\n");
	P("*********************\nItem Cost Qty\n");
	fp2=fopen("final_bill.txt","r");
	while( ( ch = fgetc(fp2) ) != EOF )
      	P("%c",ch);
	P("\nEnter 1 to confirm your order,0 otherwise\n");
	S("%d",&ch);
	if(ch==1)
	P("Order placed\n");	
	else
	{
		fclose(fopen("final_bill.txt","w"));
		P("Order cancelled\n");
	}
	validation();
}
void show_menu(int hotel_code)
{
	FILE *fp2,*fp,*fp3;
	fp=fopen("restaurant_menu.txt","r");
	fp2=fopen("temp.txt","w");
	char hotel_menu[100000],ch;
	int k=0,i,index=1,f,flag,num=0;
	rewind(fp);
	rewind(fp2);
	char buffer[100000];
	while ((fgets(buffer, 100000, fp)) != NULL)
	{
		//P("%s",buffer);
		flag=1;
		f=0;
		for(i=0;buffer[i];i++)
		{
			if(isdigit(buffer[i]) && flag==1)
			{
			num=buffer[i]-'0';
			if(num==hotel_code){
			f=1;
			fputc(index+'0',fp2);
			//P("%c",index+'0');
				index++;
			}
			}
			else
			{
				flag=0;
				if(isalnum(buffer[i]) && f==1){
				fputc(buffer[i], fp2);
				//P("%c",buffer[i]);
				}
				else if(f==1 && buffer[i]==' '){
				fputc(' ',fp2);
				//P(".");
				}
				if(buffer[i]=='\n' && f==1){
				fputc('\n',fp2);
				//P("\n");
				flag=1;
				}
			}
		}
		
	}
	
	fclose(fp);
	//get hotel name
	fclose(fp2);
	FILE *fp1;
	fp1=fopen("restaurant.txt","r");
	P("********************************************************************\n");
	P("Welcome to");
	rewind(fp1);
	char buffer1[100000];
	while ((fgets(buffer1, 100000, fp1)) != NULL)
	{
		f=0;
		for(i=0;buffer1[i];i++){
		if(isdigit(buffer1[i]))
		{
		num=buffer1[i]-'0';
		if(num==hotel_code){
		f=1;
		//fputc(index+'0',fp2);
			
		}
		}
		if(f==1 && !isdigit(buffer1[i]))
		{
		P("%c",buffer1[i]);
		}
		}
	}
	P("\n********************************************************************\nPLEASE TAKE A LOOK AT OUR MENU\n");
	fclose(fp1);
	//blanks_formatting("temp.txt");	
	fp3=fopen("temp.txt","r");
	f=0;
	rewind(fp3);
	char buff[100000];
	P("Code Cost Item\n");
	while( ( ch = fgetc(fp3) ) != EOF )
      	{	
		P("%c",ch);
		if(ch==' ')
		P("  ");
	}
	P("\n**************************************************************\nKindly enter the code of the item you wish to eat\n");
	accept_order(hotel_code);
}
int tokenize(char code[],char s[],char buffer[1000][1000],int index[10000],int price[10000])
{
	char ch,t;
	char item_details[1000][1000],b[1000][1000];
	int i,j=0,k=0,f=0,a,c=0,p=0,count=0,hotel_index=0,found=0,hotel_code=0;
	for(i=0;s[i];i++)
		{
			ch=s[i];
			if(isalpha(ch))
			{
			f=1;
			buffer[j][k++]=ch;			
			}
			else
			{
			if(k!=0){
			f=0;
			buffer[j][k++]='\0';
			j++;
			k=0;
			}
			}
		}
	
	if(f==1)
	buffer[j][k]='\0';
	else
	j--;
	j=0;
	k=0;
	f=0;
	for(i=0;s[i];i++)
		{
			ch=s[i];
			if(isalpha(ch))
			{
			f=1;
			b[j][k++]=ch;
						
			}
			else if(ch=='\n')
			{
			b[j][k++]=' ';
			b[j][k++]='!';
			//P("Put\n");
			}
			else
			{
			if(k!=0){
			f=0;
			b[j][k++]='\0';
			j++;
			k=0;
			}
			}
		}
	
	if(f==1)
	b[j][k]='\0';
	else
	j--;

	f=0;
	c=0;
	p=0;
	for(i=0;s[i];i++)
		{
			ch=s[i];
			if(isdigit(ch))
			{
			f=1;
			item_details[c][p++]=ch;
						
			}
			else
			{
			if(p!=0){
			f=0;
			item_details[c][p++]='\0';
			c++;
			p=0;
			}
			}
		}
	
	if(f==1)
	b[c][p]='\0';
	else
	j--;

	k=0;
	p=0;
	for(i=0;i<=c;i++)
	{
		if(i%2==0)
		index[k]=atoi(item_details[i]);
		else
		price[k++]=atoi(item_details[i]);
	}
	P("Some of the hotels that prepare %s are:\n",code);
	for(i=0;i<=j;i++)
	{
		if(!strcasecmp(code,buffer[i])){
		count=getItemNumber(b,i,j);
		hotel_index=index[count];
		found=1;
		find_hotel(hotel_index);
		}
	}
	if(found==0)
	P("No items match your search, kindly search for something else!!\n");
	else
	{
		P("\n*********************************************************************************\n");
		P("The number preceeding the hotel name is the code. Kindly enter the relevant code:\n");
		S("%d",&hotel_code);
		show_menu(hotel_code);
	}
	return j;
}
void search(char code[])
{
	FILE *fp;
	int k=0,len=0,i;
	int index[10000],price[10000];
	char ch;
	char items_menu[1000][1000];
	fp=fopen("restaurant_menu.txt","r");
	char buffer[1000000];
	while( ( ch = fgetc(fp) ) != EOF )
	{
		buffer[k++]=ch;
	}
	//P("%s",buffer);
	len=tokenize(code,buffer,items_menu,index,price);
}



int login(char username[],char password[])
{
	FILE *fptr;
	int newline=1,k=0,flag=0,flag1=0;
	char line_db[100],user_db[100],pass_db[100],ch;
	fptr=fopen("login_db.txt","r");
	if(fptr==NULL)
	{
		P("Cannot access file");
		exit(0);
	}
	remove_blanks();
	ch=fgetc(fptr);
	while(ch!=EOF)
	{
		
		if(ch=='\n' && flag1==1)
		{
			flag1=0;
			newline=1;
			line_db[k]='\0';
			
			segregate(line_db,user_db,pass_db);
			//P("Line is-> %s,%s where user entered %s,%s\n",user_db,pass_db,username,password);
			if(strcmp(user_db,username)==0 && !strcmp(pass_db,password)){
			flag=1;
			}
			//P("%s",username_db);
		}
		else if(ch=='\n' && flag1==0)
		{
			flag1=1;
			continue;
		}
		else
			newline=0;
		if(newline==1)
		{
			k=0;
			
		}
		else{
			//P("%d ",ch);
			line_db[k++]=ch;
		}

		ch=fgetc(fptr);
	}
	fclose(fptr);
	return flag;
}

int admin_login(char username[],char password[])
{
	FILE *fptr;
	int newline=1,k=0,flag=0,flag1=0;
	char line_db[100],user_db[100],pass_db[100],ch;
	fptr=fopen("admin_db.txt","r");
	if(fptr==NULL)
	{
		P("Cannot access file");
		exit(0);
	}
	remove_blanks();
	ch=fgetc(fptr);
	while(ch!=EOF)
	{
		
		if(ch=='\n' && flag1==1)
		{
			flag1=0;
			newline=1;
			line_db[k]='\0';
			
			segregate(line_db,user_db,pass_db);
			//P("Line is-> %s,%s where user entered %s,%s\n",user_db,pass_db,username,password);
			if(strcmp(user_db,username)==0 && !strcmp(pass_db,password)){
			flag=1;
			}
			//P("%s",username_db);
		}
		else if(ch=='\n' && flag1==0)
		{
			flag1=1;
			continue;
		}
		else
			newline=0;
		if(newline==1)
		{
			k=0;
			
		}
		else{
			//P("%d ",ch);
			line_db[k++]=ch;
		}

		ch=fgetc(fptr);
	}
	fclose(fptr);
	return flag;
}

void customer_records(char details[])
{
    FILE *fptr;
    fptr = fopen("register.txt", "a");
    if (fptr == NULL) {
        printf("Unexpected Error! Try again later");
        exit(1);
    }
    fprintf(fptr, "%s", details);
    fclose(fptr);
}
void login_db(char username[],char password[])
{
	FILE *fptr;
    fptr = fopen("login_db.txt", "a");
    if (fptr == NULL) {
        printf("Unexpected Error! Try again later");
        exit(1);
    }
    fprintf(fptr, "\n%s %s", username, password);
    fclose(fptr);
}

int perform_login()
{
	char username[100],password[100];
	int flag=0;
	P("Enter username\n");
	S("%s",username);
	P("Enter password\n");
	S("%s",password);
	flag=login(username,password);
	if(flag==0){
	P("Authentication failed\n");
	return 10;
	}
	else if(flag==1)
	{
	return 11;
	}
	return 0;
}

int fill_form()
{
	FILE *fp;
	int duplicates=0;
	char first_name[100],last_name[100],username[100],password[100],details[200],space_append[1];
	space_append[0]=' ';
	system("clear");
	P("Enter your Full Name\n");
	S("%s %s",first_name,last_name);
	P("Enter a username (must be unique)\n");
	S("%s",username);
	duplicates=check_duplicates(username);
	if(duplicates==1)
	return -1;

	P("Enter a password (must have length between 8-15 and must have at least 1 numerical value and at least 1 upper case letter)\n");
	S("%s",password);
	char user_city[]="Delhi";
	char city_str[20];
	int city_code=0;
	form_a_line(details,username,password,first_name,last_name,user_city);
	customer_records(details);
	login_db(username,password);
	
	return 0;
}
int allow_admin()
{
	char username[100],password[100];
	int flag=0;
	P("Enter username\n");
	S("%s",username);
	P("Enter password\n");
	S("%s",password);
	flag=admin_login(username,password);
	if(flag==0){
	P("Authentication failed\n");
	return -1;
	}
	else if(flag==1)
	{
	return 1;
	}
	return 0;	
}


void restaurant_records(char details[])
{
    FILE *fptr;
    fptr = fopen("restaurant.txt", "a");
    if (fptr == NULL) {
        printf("Unexpected Error! Try again later");
        exit(1);
    }
    fprintf(fptr, "%s", details);
    fclose(fptr);
}
void restaurant_menu(char details[])
{
    FILE *fptr;
    fptr = fopen("restaurant_menu.txt", "a");
    if (fptr == NULL) {
        printf("Unexpected Error! Try again later");
        exit(1);
    }
    fprintf(fptr, "%s", details);
    fclose(fptr);	
}
void restaurant_cuisine(char details[])
{
    FILE *fptr;
    fptr = fopen("restaurant_cuisine.txt", "a");
    if (fptr == NULL) {
        printf("Unexpected Error! Try again later");
        exit(1);
    }
    fprintf(fptr, "%s", details);
    fclose(fptr);	
}
void add_to_db(char name[],char address[],char item[100][100],char price[100][100],char cuisine[100][100],int k,int p)
{
	FILE *fp;
	char ch;
	int i;
	fp=fopen("index.txt","r");
	ch=fgetc(fp);
	int index=ch-'0';
	//P("Index is: %d\n",index);
	fclose(fp);
	char details[1000];
	
	form_data(details,ch+1,name,address);
	restaurant_records(details);

	for(i=0;i<k;i++){
	form_a_line_data(details,ch+1,price[i],item[i]);
	restaurant_menu(details);
	}

	for(i=0;i<p;i++){
	form_a_line_menu(details,ch+1,cuisine[i]);
	restaurant_cuisine(details);
	}
	
	fp=fopen("index.txt","w");
	blanks_formatting("restaurant.txt");	
	blanks_formatting("restaurant_menu.txt");	
	blanks_formatting("restaurant_cuisine.txt");
	fputc(ch+1,fp);
	fclose(fp);
}
void administrate()
{
	int ch,choice=1,k=0,p=0,i;
	char price[100][100];
	char buffer;
	char name[100],address[100],item[100][100],cuisine[100][100];
	P("Enter 1 to add Restaurants, 2 to delete, 3 to display\n");
	S("%d",&ch);
	S("%c",&buffer);
	switch(ch)
	{
		case 1: P("Enter restaurant name\n");
		S("%[^\n]s ",name);
		P("Enter address\n");
		S("%c",&buffer);
		S("%[^\n]s ",address);
		do{
		S("%c",&buffer);
		P("Enter item %d\n",k+1);
		S("%[^\n]s ",item[k]);
		P("Enter price of %s\n",item[k]);
		S("%s",price[k]);
		k++;
		P("Enter 1 to enter more items, 0 to end\n");
		S("%d",&choice);
		}while(choice==1);
		P("Enter Cuisine\n");
		p=0;
		do{
		P("Enter a cuisine you specialise in:\n");
		S("%c",&buffer);
		S("%[^\n]s",cuisine[p]);
		S("%c",&buffer);
		p++;
		P("Enter 1 to enter more items, 0 to end\n");
		S("%d",&choice);
		
		}while(choice==1);
		P("%s located at %s\nMenu:\n",name,address);
		for(i=0;i<k;i++)
		P("%s %s\n",item[i],price[i]);
		P("Cuisines:\n");
		for(i=0;i<p;i++)
		P("%s\n",cuisine[i]);
		add_to_db(name,address,item,price,cuisine,k,p);
		break;
	}
}

int main()
{
	int ch,authentication_level;
	char item[100];
	validation();
}
