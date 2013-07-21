#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    /*-- comment --*/
    int ix;
    char ch;
    int read_bytecount = 0;
    int hexchar[16];
    char read_filein[17];
    char *filename = argv[1];
    FILE *fp;
    
    /*-- comment --*/
    if((fp = fopen(filename, "r")) == (NULL)){
        printf("error : can\'t open %s",filename);
        exit(1);
    }

    /*-- comment --*/
    while ((ch = fgetc(fp)) != EOF)
    {
        read_bytecount += 1;
        hexchar[(read_bytecount - 1) % 16] = ch;
        read_filein[(read_bytecount - 1) % 16] = ch;

        if(read_bytecount % 16 == 0)
        {
            /*-- print read byte count --*/
            printf("%08x  ",read_bytecount);
            /*-- print hexdump --*/
            for(ix = 0; ix < 16; ix++)
            {
                printf("%02x ",hexchar[ix]);
            }
            /*-- print filein --*/
            printf(" | ");
            for(ix = 0; ix < 16; ix++)
            {
                //printf("%d:",ix);
                if(read_filein[ix] == '\n')
                {
                    printf(".");
                }else{
                    printf("%c",read_filein[ix]);
                }
            }
            printf(" |\n");
        }
    }
        printf("%08x  ",read_bytecount);
        for(ix = 0; ix < ((read_bytecount - 1) % 16); ix++)
        {
            printf("%02x ",hexchar[ix]);
        }
        for(ix = ((read_bytecount - 1) % 16); ix < 16; ix++)
        {
            printf("   ");
        }
        printf(" | ");
        for(ix = 0; ix < ((read_bytecount - 1) % 16); ix++)
        {
            //printf("%d:",ix);
            if(read_filein[ix] == '\n')
            {
                printf(".");
            }else{
                printf("%c",read_filein[ix]);
            }
        }
        printf(" |\n");

    fclose(fp);

    return 0;
}

void print_oneline(int rbc_p, int hch_p, int rfi_p){
}
