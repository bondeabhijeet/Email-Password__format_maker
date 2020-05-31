#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main (void)
{
    FILE *fp, *fp1;
    char filename[80], ch, str[200], str1[200];
    int i;

    ch = ' ';

    if((fp=fopen("new.txt", "rt"))==NULL)
    {
        printf("\n ERROR OPENING FILE 1 \n");
        exit(0);
    }

    if((fp1=fopen("new1.txt", "wt"))==NULL)
    {
        printf("\n ERROR OPENING FILE 2 \n");
        exit(0);
    }
    int count = 0;
    do
    {
        if(feof(fp))
        {
            printf("\n END OF FILE \n");
            exit(0);
        }

        i=0;
        fscanf(fp, " %[^\n]", str);
        printf("%s\n", str);


        while(str[i] != ' ' )
        {
            str1[i]=str[i];
            ++i;
        }
        str1[i] = '\0';
        printf("%s \n", str1);

        fprintf(fp1, "%s \n", str1);
        // printf( "\n %c\n",str1[i]) ;
        count++;


    }while(count < 1000);

    fclose(fp);
    fclose(fp1);
}
