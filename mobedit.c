#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX1LINE 256

int main(void){

    FILE *fp,*fp2;
    char inputFilename[] = "distcheck";
    char outputFilename[128];
    sprintf(outputFilename,"%sout",inputFilename);

    char str[MAX1LINE];

    fp = fopen(inputFilename, "r");
    fp2 = fopen(outputFilename, "w");

    double shift_X = 100;
    double shift_Y = 100;

    if(fp == NULL) {
        printf("%s file not open!\n", inputFilename);
        return -1;
    }

    int count = 0;
    int i = 0;
    char *addr,*addr2;
    double value = 0;
    while(fgets(str, MAX1LINE, fp) != NULL) {
        //printf("%d ",count);
        //printf("%ld ", strlen(str));
        addr = NULL;
        addr = strstr(str,"set X_");

        if(addr != NULL) {
            //printf("%s", addr);
            printf("%d:",count);
            for(i = 0; i < strlen(addr); i++){
                printf("%c",addr[i]);
            }
            //X座標のシフト
            addr2 = strchr(addr, (int)'X');
            if(addr2 != NULL){
                printf("%s",addr2+3);
                value = atof(addr2+3);

                printf("double:%.12f\n",value);
                value += shift_X;

                printf("shiftX= %.12f\n",value);

                fprintf(stdout,"%s",str);
                //fprintf(outputFilename,"")
            }

        }
        for(i = 0; i < strlen(str); i++){
            //printf("%c",str[i]);
        }

        if(count >=5){
            break;
        }
        count++;

    }



    fclose(fp); // ファイルを閉じる

    return 0;
}