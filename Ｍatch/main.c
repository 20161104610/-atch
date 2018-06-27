#include <stdio.h>
#include <string.h>

struct Student {
    char name[10];
    //char sex;
    //char proname[20];
    //char prochoo[20];
    //char classname[10];
    //int phonenum[20];
};

typedef struct Student ElmtypeS;

typedef struct{
    ElmtypeS elem[30];
    int last;
}SeqlistS;

struct Teacher{
    char name[10];
    char sex;
    int phonenum[20];
    int score;
};

typedef struct Teacher ElmtypeT;

typedef struct{
    ElmtypeT elem[5];
    int last;
}SeqlistT;



int menu(){
    int m=0;
    printf("|  ------------------------------------  |\n");
    printf("|               节目记分系统❤️             |\n");
    printf("|  ------------------------------------  |\n");
    printf("|              ✨1----节目信息            |\n");
    printf("|              ✨2----裁判信息            |\n");
    printf("|              ✨3----演员信息            |\n");
    printf("|              ✨4----录入得分            |\n");
    printf("|              ✨5----节目排名            |\n");
    printf("|              ✨6----保存显示            |\n");
    printf("|              ✨0----退出系统            |\n");
    printf("|  ------------------------------------  |\n");
    printf("输入数字以进行操作：\n");
    scanf("%d",&m);
    return m;
}


void save(SeqlistS *L){
    FILE *fw;
    int data=10;
    fw=fopen("Users/h20161104610/Desktop/Match/Match/workers.csv","w");
    //printf("Please input the student's name:\n");
    fprintf(fw,"%d",data);
    fclose(fw);
}

void load(SeqlistS *L){
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

void teachers(SeqlistT *L){
    int i;
    int n;
    printf("请输入裁判数量:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("请输入第%d个裁判的姓名：\n",i+1);
        scanf("%s",L->elem[i].name);
        printf("请输入第%d个裁判的性别：\n",i+1);
        scanf("%s",&L->elem[i].sex);
        printf("请输入第%d个裁判的电话号码：\n",i+1);
        scanf("%d",L->elem[i].phonenum);
    }
}
              
//printf("请输入第%d个裁判的评分：\n",i+1);
//scanf("%d",&L->MAXNUM->score);
              
void students(SeqlistS *L){
    
}

void show(SeqlistT *Lt,SeqlistS *Ls){
    
    
}

void display(h){
    SeqlistS ls;
    SeqlistT lt;
    ls.last=-1;
    lt.last=-1;
    switch(h){
        case 1://节目
            //load(&ls);
            break;
        case 2://裁判
            teachers(&lt);
            break;
        case 3://演员
            students(&ls);
            break;
        case 4://分数
            //input(&lt);
            break;
        case 5://排序
            
            break;
        case 6:
            //save();
            //show();
            break;
        case 0:
            break;
        default:
            printf("输入类型错误!\n");
    }
}

int disinput(){
    int m,h=0;
    printf("|  -----------------------------  |\n");
    printf("|           回到主菜单？❤️          |\n");
    printf("|  -----------------------------  |\n");
    printf("|          ✨是------(1)          |\n");
    printf("|          ✨否------(0)          |\n");
    printf("|  -----------------------------  |\n");
    scanf("%d",&m);
    if(m==1){
        h=menu();
        display(h);
    }
    else if(m==0){
        return 0;
    }
    else{
        printf("输入类型错误!\n");
    }
    return 0;
}

int main(){
    SeqlistS ls;
    SeqlistT lt;
    ls.last=-1;
    lt.last=-1;
    int h=0;
    
    while(1){
        h=menu();
        if(h==0){
            return 0;
        }
        else{
            display(h);
            disinput();
            return 0;
        }
    }
    
    return 0;
}
