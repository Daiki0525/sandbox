#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    /*-- comment --*/
    int ix;
    char ch;
    int read_bytecount = 0;
    int hexchar[16];
    char read_char[17];
    char *filename = argv[1];
    FILE *fp;
    
    /*-- comment --*/
    if((fp = fopen(filename, "r")) == (NULL)){
        printf("error : can\'t open %s",filename);
        exit(1);
    }
            for(ix = 0; ix < 16; ix++)
            {
                read_char[ix] = '\0';
            }

    /*-- comment --*/
    while ((ch = fgetc(fp)) != EOF)
    {
        read_bytecount += 1;
        read_char[((read_bytecount-1) % 16)] = ch;
//        printf("%d %c %zd \n",(read_bytecount-1) % 16,ch , strlen(read_char));

//        if( (int)strlen(read_char) == 16 )//文字列満タンなら
        if( read_bytecount % 16  == 0 )
        {

            /*-- print read byte count --*/
            printf("%08x  ",read_bytecount - 16);
            /*-- print hexdump --*/
            for(ix = 0; ix < 16; ix++)
            {
                printf("%02x ",read_char[ix]);
            }
            /*-- print filein --*/
            printf(" |");
            for(ix = 0; ix < 16; ix++)
            {
                //printf("%d:",ix);
                if(read_char[ix] == '\n')
                {
                    printf(".");
                }else{
                    printf("%c",read_char[ix]);
                }
            }
//            for(ix = 0; ix < 17; ix++)
//            {
//                read_char[ix] = '\0';
//            }
            printf("|\n");
        }
    }
//        printf("%08x  ",read_bytecount);
//        for(ix = 0; ix < ((read_bytecount - 1) % 16); ix++)
//        {
//            printf("%02x ",hexchar[ix]);
//        }
//        for(ix = ((read_bytecount - 1) % 16); ix < 16; ix++)
//        {
//            printf("   ");
//        }
//        printf(" |");
//        for(ix = 0; ix < ((read_bytecount - 1) % 16); ix++)
//        {
//            //printf("%d:",ix);
//            if(read_filein[ix] == '\n')
//            {
//                printf(".");
//            }else{
//                printf("%c",read_filein[ix]);
//            }
//        }
//        printf("|\n");

    fclose(fp);

    return 0;
}

//int print_oneline(int *read_bytecount, int *hexchar, int *read_filein)
//{
//    int ix;
//    printf("%08x  ",*read_bytecount-16);
////    for(ix = 0; ix < ((*read_bytecount - 1) % 16); ix++)
//    for(ix = 0; ix <  16; ix++)
//    {
//        printf("%02x ",hexchar[ix]);
//    }
////    for(ix = (*read_bytecount % 16); ix < 16; ix++)
////    {
////        printf("   ");
////    }
//    printf(" |");
////    for(ix = 0; ix < ((*read_bytecount - 1) % 16); ix++)
//    for(ix = 0; ix < 16; ix++)
//    {
//        printf("%d:",ix);
//        if(read_filein[ix] == '\n')
//        {
//            printf(".");
//        }else{
//            printf("%c",read_filein[ix]);
//        }
//    }
//    printf("|\n");
//}
