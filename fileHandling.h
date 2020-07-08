int isEmpty(const char *str)
{
    char ch;

    do
    {
        ch = *(str++);

        // Check non whitespace character
        if(ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0')
            return 0;

    } while (ch != '\0');

    return 1;
}
void removeEmptyLines(FILE *srcFile,FILE *tempFile)
{
    char buffer[1000];

    while ((fgets(buffer, 1000, srcFile)) != NULL)
    {
        /* If current line is not empty then write to temporary file */
        if(!isEmpty(buffer))
            fputs(buffer, tempFile);
    }
}
void copyFiles(char source_file[],char target_file[])
{
   FILE *source,*target;
   char ch;
   source = fopen(source_file, "r");

   target = fopen(target_file, "w");

   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);

fclose(source);
	fclose(target);
}
