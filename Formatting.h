int check_duplicates(char username[])
{
	char str[100],val[100];
	int space=0,k=0;
	FILE *fp;
	fp = fopen("login_db.txt" , "r");
  	 if(fp == NULL) {
      P("Error opening file");
      exit(0);
   }
   while( fgets (str, 60, fp)!=NULL ) {
	k=0;
      for(int i=0;str[i];i++)
	{
		if(str[i]==' ')
		break;
		else
		val[k++]=str[i];
	}
	val[k++]='\0';
	if(!strcmp(username,val)){
	P("Username already taken! Try again\n");
	return 1;
      }
   }
   fclose(fp);

}
void segregate(char userpass[],char user[100],char pass[100])
{
	int i,space=0,k=0;
	char ch;
	for(i=0;i<100;i++)
	user[i]=pass[i]=' ';
	for(i=0;i<userpass[i]!='\0';i++)
	{
		
		ch=userpass[i];
		if(ch==' ')
		{
		space=1;
		user[k]='\0';
		k=0;
		}
		if(space==0)
		user[k++]=userpass[i];
		else if(userpass[i]!=' ')
		pass[k++]=userpass[i];
		
	}
	pass[k]='\0';
	
}
void form_a_line(char details[200],char username[100],char password[100],char first_name[100],char last_name[100],char user_city[20])
{
	int i,k=0;
	details[k++]='\n';
	for(i=0;username[i];i++)
	details[k++]=username[i];
	details[k++]=' ';
	for(i=0;password[i];i++)
	details[k++]=password[i];
	details[k++]=' ';
	for(i=0;first_name[i];i++)
	details[k++]=first_name[i];
	details[k++]=' ';
	for(i=0;last_name[i];i++)
	details[k++]=last_name[i];
	details[k++]=' ';
	for(i=0;user_city[i];i++)
	details[k++]=user_city[i];
	details[k++]='\0';
}

void form_a_line_data(char details[200],char index,char username[100],char password[100])
{
	int i,k=0;
	details[k++]='\n';
	details[k++]=index;
	details[k++]=' ';
	for(i=0;username[i];i++)
	details[k++]=username[i];
	details[k++]=' ';
	for(i=0;password[i];i++)
	details[k++]=password[i];
	details[k++]='\0';
}
void form_data(char details[200],char index,char username[100],char password[100])
{
	int i,k=0;
	char str[]="located at ";
	details[k++]='\n';
	details[k++]=index;
	details[k++]=' ';
	for(i=0;username[i];i++)
	details[k++]=username[i];
	details[k++]=' ';
	for(i=0;i<strlen(str);i++)
	details[k++]=str[i];
	for(i=0;password[i];i++)
	details[k++]=password[i];
	details[k++]='\0';
}
void form_a_line_menu(char details[200],char index,char username[100])
{
	int i,k=0;
	details[k++]='\n';
	details[k++]=index;
	details[k++]=' ';
	for(i=0;username[i];i++)
	details[k++]=username[i];
	details[k++]='\0';
}

void blanks_formatting(char source[])
{
	FILE *srcFile,*tempFile;
	srcFile  = fopen(source, "r");
	 tempFile = fopen("remove-blanks.txt", "w");
	rewind(srcFile);
        removeEmptyLines(srcFile,tempFile);
	fclose(srcFile);
	fclose(tempFile);
	copyFiles("remove-blanks.txt",source);
}

