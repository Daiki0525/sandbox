#include <stdio.h>
#include <stdlib.h>

//void print_oneline(int *read_bytecount,char *read_char); 

int main(int argc, char *argv[])
{
    /*-- initialize --*/
    int ix;
    char ch;
    int read_bytecount = 0;
    int hexchar[16];
    char read_char[16];
    char *filename = argv[1];
    FILE *fp;
    
    /*-- file open --*/
    if((fp = fopen(filename, "r")) == (NULL))
    {
        printf("error : can\'t open %s",filename);
        exit(1);
    }

    /*-- line loop --*/
    while ((ch = fgetc(fp)) != EOF)
    {
        read_bytecount += 1;
        read_char[((read_bytecount-1) % 16)] = ch;

        if(read_bytecount % 16 == 0 )
        {
            print_oneline(&read_bytecount,&read_char);
        }
    }
    /*-- print a last line --*/
    print_oneline(&read_bytecount,&read_char);

    fclose(fp);

    return 0;
}

/*-- print a line --*/
int print_oneline(int *read_bytecount, char *read_char)
{
    /*-- intialize --*/
    int iy;
    int char_count;
    /*-- print bytecount --*/
    if(!(char_count = *read_bytecount % 16))
    {
        char_count = 16;
    }
    if(char_count != 16)
    {
        printf("%08x  ",*read_bytecount);
    }else{
        printf("%08x  ",*read_bytecount - 16);
    }
    /*-- print hexchar --*/
    for(iy = 0; iy < char_count; iy++)
    {
       printf("%02x ",*(read_char + iy));
    }
    if(char_count != 16)
    {
       for(iy = 0; iy < 16 - char_count; iy++)
       {
            printf("   ");
       }
    }
    /*-- print filein --*/
    printf(" |");
    for(iy = 0; iy <  char_count; iy++)
    {
        if(*(read_char + iy)<= 0x1f || 0x7f <= *(read_char + iy))
        {
            printf(".");
        }else{
            printf("%c",*(read_char + iy));
        }
    }
    printf("|\n");
    return 0;
}
