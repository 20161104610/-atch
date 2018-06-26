#include <stdio.h>
#include <string.h>

struct Student {
    char name[10];
    char sex;
    char proname[20];
    char prochoo[20];
    char classname[10];
    int phonenum[20];
};

typedef struct Student Elmtype;

typedef struct{
    Elmtype MAXNUM[30];
    int last;
}Seqlist;

struct Teacher{
    char name[10];
    char sex;
    int phonenum[20];
    int score;
};



void menu(){
    printf("|  ---------------------------------  |\n");
    printf("|               节目记分表              |\n");
    printf("|  ---------------------------------  |\n");
    printf("|              1----节目表             |\n");
    printf("|              2----裁判表             |\n");
    printf("|              3----演员表             |\n");
    printf("|              4----分数表             |\n");
    printf("|              5----保存表             |\n");
    printf("|              0----退出去             |\n");
    printf("|  ---------------------------------  |\n");
}


void save(Seqlist *L){
    FILE *fw;
    int data=10;
    fw=fopen("Users/h20161104610/Desktop/Match/Match/workers.csv","w");
    //printf("Please input the student's name:\n");
    fprintf(fw,"%d",data);
    fclose(fw);
}

void load(Seqlist *L){
    char data;
    
    FILE *fr;
    fr=fopen("Users/h20161104610/Desktop/Match/Ｍatch/Ｍatch/workers.csv","r+");
    
    if(fr==NULL){
        printf("This text is not find!\n");
    }
    else{
        printf("Success!\n");
        
        //fgets(data,6,fr);
        printf("%c",data);
    }
    fclose(fr);
}

void input(Seqlist *L){
    
}

void teachers(Seqlist *L){
    
}

void students(Seqlist *L){
    
}

void main(){
    Seqlist l;
    l.last=-1;
    int h;

    while(1){
        menu();
        printf("输入数字以进行操作：\n");
        scanf("%d",&h);
        switch(h){
            case 1:
                load(&l);
            case 2:
                teachers(&l);
            case 3:
                students(&l);
        }
    }
    //save(&l);
    
    //load(&l);
}
