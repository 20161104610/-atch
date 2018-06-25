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

void save(Seqlist *L){
    FILE *fp;
    int data;
    fp=fopen("Users/h20161104610/Desktop/Match/Match/workers.txt","w");
    printf("Please input the student's name:\n");
    scanf("%c",&data);
    fprintf(fp,"%c",data);
    fclose(fp);
}

void load(Seqlist *L){
    FILE *fp;
    fp=fopen("Users/h20161104610/Desktop/Match/Ｍatch/Ｍatch/workers.txt","r");
    char data;
    if(fp==NULL){
        printf("This text is not find!\n");
    }
    else{
        printf("Success!\n");
        
        fscanf(fp,"%c",&data);
        printf("%c",data);
    }
    fclose(fp);
}

int main(){
    Seqlist l;
    l.last=-1;
    
    save(&l);
    load(&l);
}
