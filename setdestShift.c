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

    //file open check
    if(fp == NULL) {
        printf("%s file not open!\n", inputFilename);
        return -1;
    }
    else{
        printf("inputfilename: %s\n",inputFilename);
    }
    if(fp2 == NULL) {
        printf("%s file not open!\n", outputFilename);
        return -1;
    }
    else{
        printf("outputFilename:%s\n",outputFilename);
    }

    int count = 0;
    int i = 0;
    char *addr, *addr2;
    double value = 0;

    while(fgets(str, MAX1LINE, fp) != NULL) {

        //X座標のシフト
        //setXを探す
        addr = NULL;
        addr = strstr(str,"set X_");

        if(addr != NULL) {
            printf("%d:",count);
            for(i = 0; i < strlen(addr); i++){
                printf("%c",addr[i]);
            }
            //Xを探す
            addr2 = strchr(addr, (int)'X');
            if(addr2 != NULL){
                printf("%s",addr2 + 3);
                value = atof(addr2 + 3);

                printf("double:%.12f\n",value);
                value += shift_X;

                printf("shiftX= %.12f\n",value);
                snprintf(addr2 + 3, 20, "%.13f", value);
                fprintf(stdout,"%s",str);
                //fprintf(fp2,"%s",str);
                str[strlen(str)-1] = '\n';
            }

        }
        addr = NULL;
        addr = strstr(str,"set Y_");
        if(addr != NULL) {
            printf("%d:",count);
            for(i = 0; i < strlen(addr); i++){
                printf("%c",addr[i]);
            }
            //Yを探す
            addr2 = strchr(addr, (int)'Y');
            if(addr2 != NULL){
                printf("%s",addr2 + 3);
                value = atof(addr2 + 3);

                printf("double:%.12f\n",value);
                value += shift_Y;

                printf("shiftX= %.12f\n",value);
                snprintf(addr2 + 3, 20, "%.13f", value);
                fprintf(stdout,"%s",str);
                //fprintf(fp2,"%s",str);
                str[strlen(str)-1] = '\n';
            }

        }

        addr = NULL;
        addr = strstr(str,"setdest");
        if(addr != NULL) {
            printf("start:%s",str);

            value = atof(addr + 8);
            printf("double:%.12f\n",value);
            value += shift_X;
            snprintf(addr + 8, strlen(addr + 8), "%.13f", value);


            value = 0;
            for(i = 8; ;i++){
                if(addr[i] == ' '){
                    i++;
                    break;
                }
            }
            value = atof(addr + i);
            printf("double:%.12f\n",value);
            value += shift_Y;
            snprintf(addr + i, strlen(addr + i), "%.13f", value);

            printf("final:%s",str);

/*            printf("%d:",count);
            for(i = 0; i < strlen(addr); i++){
                printf("%c",addr[i]);
            }
            //Xを探す
            for(i =)
            if(addr2 != NULL){
                printf("%s",addr2 + 3);
                value = atof(addr2 + 3);

                printf("double:%.12f\n",value);
                value += shift_X;

                printf("shiftX= %.12f\n",value);
                snprintf(addr2 + 3, 20, "%.13f", value);
                fprintf(stdout,"%s",str);
                //fprintf(fp2,"%s",str);
                str[strlen(str)-1] = '\n';
            }*/

        }

        printf("\n---\n");

        //ファイルに出力
        fprintf(fp2,"%s",str);



        if(count >=170){
            break;
        }
        count++;

    }



    fclose(fp); // ファイルを閉じる
    fclose(fp2);
    return 0;
}