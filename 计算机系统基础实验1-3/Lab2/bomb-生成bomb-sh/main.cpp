#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char s1[200] = "./makebomb.pl -i %s -s ./src -b ./bombs -l bomblab -u dqwang@hust.edu.cn -v %s";
char s2[200]="cd allbombs";
char s21[200]="mkdir %s";
char s22[200]="cd %s";
char s3[200]="mkdir U%s";
char s4[200]="cd ../..";
char s5[200]="cp ./bombs/bomb%s/bomb ./allbombs/%s/U%s";
char s6[200]="cp ./bombs/bomb%s/bomb.c ./allbombs/%s/U%s";
char s7[200]="cp ./bombs/bomb%s/ID ./allbombs/%s/U%s";
char s8[200]="cp ./bombs/bomb%s/README ./allbombs/%s/U%s";
char s9[200]="cd allbombs";
char s10[200]="zip -r %s.zip %s";
char s11[200]="cd ..";


char * cs2014[10] ={(char *)"CS201401",(char *)"CS201402",(char *)"CS201403",(char *)"CS201404",
                    (char *)"CS201405",(char *)"CS201406",(char *)"CS201407",(char *)"CS201408",
                    (char *)"CS201409",(char *)"CS201410"};
int main(int argc, char *argv[])
{
    FILE * fr;
    FILE * fw;
    char **csclass;
    int classnum = 0;
    char fname[100];
    if(argc<=1){
        printf("You should give me a input file!\nBut I also create files for you!");
        csclass = cs2014;
        classnum = 10;
    }
    else {
        if(!strcmp(argv[1],"-a")) {
            csclass = cs2014;
            classnum = 10;
        }
        else {
            csclass = &argv[1];
            classnum = 1;
        }
    }

    int n;
    char cs[100];
    char ss[100];
    for(int k=0;k<classnum;k++){
        strcpy(fname,csclass[k]);
        printf("Creating %s......\n",fname);
        fr = fopen(fname,"r");
        if(!fr) {
            printf("Can't open input file%s.",fname);
            return 1;
        }
        sprintf(fname,"%s.sh",fname);
        fw = fopen(fname,"w");
        if(!fw) {
            printf("Can't open output file %s.",fname);
            return 1;
        }
        fscanf(fr,"%s",cs);
        fscanf(fr,"%d",&n);
        for(int i=0;i<n;i++){
            fscanf(fr,"%s",ss);
            strcpy(ss,&ss[1]);
            sprintf(s1,"./makebomb.pl -i %s -s ./src -b ./bombs -l bomblab -u dqwang@hust.edu.cn -v %s",ss,ss);
            sprintf(s21,"mkdir %s",cs);
            sprintf(s22,"cd %s",cs);
            sprintf(s3,"mkdir U%s",ss);
            sprintf(s5,"cp ./bombs/bomb%s/bomb ./allbombs/%s/U%s",ss,cs,ss);
            sprintf(s6,"cp ./bombs/bomb%s/bomb.c ./allbombs/%s/U%s",ss,cs,ss);
            sprintf(s7,"cp ./bombs/bomb%s/ID ./allbombs/%s/U%s",ss,cs,ss);
            sprintf(s8,"cp ./bombs/bomb%s/README ./allbombs/%s/U%s",ss,cs,ss);
            sprintf(s10,"zip -r %s.zip %s",cs,cs);
            fprintf(fw,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",s1,s2,s21,s22,s3,s4,s5,s6,s7,s8,s9,s10,s11);
        }
        fclose(fr);
        fclose(fw);
    }
    printf("Done.");
    return 0;
}
