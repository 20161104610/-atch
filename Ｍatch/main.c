#include <stdio.h>
#include <string.h>

struct Student {
    char name[10];//姓名
    char sex;//性别
    char proname[20];//节目名称
    char prochoo[20];//节目类别
    char classname[10];//班级名称
    int phonenum[20];//电话号码
    int sorce[5];//分数
    int fasorce;//最终得分
};

typedef struct Student ElmtypeS;

typedef struct{
    ElmtypeS elem[30];
    int last;
}SeqlistS;

struct Teacher{
    char name[10];//姓名
    char sex;//性别
    char phonenum[20];//电话号码
};

typedef struct Teacher ElmtypeT;

typedef struct{
    ElmtypeT elem[5];
    int last;
}SeqlistT;



int menu(){//菜单栏
    int m=0;
    printf("|  ------------------------------------  |\n");
    printf("|               节目记分系统❤️             |\n");
    printf("|  ------------------------------------  |\n");
    printf("|              ✨1----节目信息            |\n");
    printf("|              ✨2----录入裁判信息         |\n");
    printf("|              ✨3----录入得分            |\n");
    printf("|              ✨4----节目排名            |\n");
    printf("|              ✨5----保存信息            |\n");
    printf("|              ✨6----选手信息            |\n");
    printf("|              ✨7----裁判信息            |\n");
    printf("|              ✨0----退出系统            |\n");
    printf("|  ------------------------------------  |\n");
    printf("输入数字以进行操作：\n");
    scanf("%d",&m);
    return m;
}

void save(SeqlistT *L){//保存
    FILE *fw;
    int i;
    fw=fopen("//Users//h20161104610//Desktop//teachers.csv","w");
    for(i=0;i<5;i++){
        fprintf(fw,"%s %c %d",L->elem[i].name,L->elem[i].sex,L->elem[i].phonenum);
    }
    fclose(fw);
}

void loads(SeqlistS *L){//读取数据
    FILE *fr;
    fr=fopen("//Users//h20161104610//Desktop//workers.csv","r+");
    if(fr == NULL){
        printf("读取文件失败!\n");
    }
    else{
        int i,j;
        L->last=-1;
        char name[10];
        char sex;
        char pname[20];
        char pchoo[20];
        char cname[10];
        char pnum[20];
        //char sor[5];
        //int fasor;
        while(fscanf(fr,"%d %s %c %s %s %s %s\n",&j,name,&sex,pname,pchoo,cname,pnum)!=EOF){
            i=j-1;
            strcpy(L->elem[i].name,name);
            L->elem[i].sex=sex;
            strcpy(L->elem[i].proname,pname);
            strcpy(L->elem[i].prochoo,pchoo);
            strcpy(L->elem[i].classname,cname);
            strcpy(L->elem[i].phonenum,pnum);
            L->last++;
        }
        printf("文件读取成功!\n");
        printf("%s %c %s %s %s %s\n",name,sex,pname,pchoo,cname,pnum);
        fclose(fr);
    }
}

void teachers(SeqlistT *L){//录入裁判信息
    int i;
    int n;
    FILE *fw=fopen("//User//h20161104610//Desktop//teachers.csv", "w");
    printf("请输入裁判数量:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("请输入第%d个裁判的姓名：\n",i+1);
        scanf("%s",&L->elem[i].name);
        //fprintf(fw,"%s",&L->elem[i].name);
        printf("请输入第%d个裁判的性别：\n",i+1);
        scanf("%s",&L->elem[i].sex);
        //fprintf(fw,"%s",L->elem[i].sex);
        printf("请输入第%d个裁判的电话号码：\n",i+1);
        scanf("%s",&L->elem[i].phonenum);
        //fprintf(fw,"%d",L->elem[i].phonenum);
    }
    fclose(fw);
}

void input(SeqlistS *L){
    int i,j,k,h,z=0;
    float fs=0;
    for(i=0;i<30;i++){
        printf("请输入给第%d小组的评分:\n",i+1);
        printf("第1位评委评分:\n");
        scanf("%d",&L->elem[i].sorce[0]);
        printf("第2位评委评分:\n");
        scanf("%d",&L->elem[i].sorce[1]);
        printf("第3位评委评分:\n");
        scanf("%d",&L->elem[i].sorce[2]);
        printf("第4位评委评分:\n");
        scanf("%d",&L->elem[i].sorce[3]);
        printf("第5位评委评分:\n");
        scanf("%d",&L->elem[i].sorce[4]);
        
        for(k=0;k<5;k++){
            for(h=0;h<5-k;k++){
                if(L->elem[i].sorce[k]>=L->elem[i].sorce[k+1]){
                    z=L->elem[i].sorce[k];
                    L->elem[i].sorce[k]=L->elem[i].sorce[k+1];
                    L->elem[i].sorce[k+1]=z;
                }
            }
            
        }
        for(k=1;k<4;k++){
            fs=fs+L->elem[i].sorce[k];
        }
        fs=fs/3;
        L->elem[i].fasorce=fs/3;
        printf("第%d小组的最终得分为:\n",i+1);
        printf("%.2f\n",fs);
        
        printf("|  ------------------------------------  |\n");
        printf("|              是否继续进行评分❤️           |\n");
        printf("|  ------------------------------------  |\n");
        printf("|               ✨是------(1)            |\n");
        printf("|               ✨否------(0)            |\n");
        printf("|  ------------------------------------  |\n");
        scanf("%d",&j);
        if(j==0){
            break;
        }
    }
    
}

void shows(SeqlistS *L){
    int i,j;
    j=L->last;
    if(j==NULL){
        printf("      ---------没有可以显示的信息!\n");
        }
    
    else{
       
        printf("| 姓名 | 性别 | 节目名称 | 节目类别 | 班级 | 电话号码 |\n");
        for(i=0;i<=L->last;i++){
            printf("|  %s  |  %c  |  %s  |  %s  |  %s  |  %s  |\n",L->elem[i].name,L->elem[i].sex,L->elem[i].proname,L->elem[i].prochoo,L->elem[i].classname,L->elem[i].phonenum);
        }

    }
    
}

void showt(SeqlistT *L){
    int i,j;
    j=L->last;
    if(j!=NULL){
        printf("| 姓名 | 性别 | 电话号码 |\n");
        for(i=0;i<j;i++)
        {
            printf("|%-6s|%-6c|%-6s|\n",L->elem[i].name,L->elem[i].sex,L->elem[i].phonenum);
        }
    }
    else{
        printf("      ---------没有可以显示的信息!\n");
    }
    
}

void sort(SeqlistS *L){//排序
    int i,j,k;
    int s=0;
    for(i=0;i<30;i++){
        printf("开始排序:\n");
        for(j=0;j<30-i;j++){
                if(L->elem[j].fasorce<L->elem[j+1].fasorce){
                   s=L->elem[j].fasorce;
                   L->elem[j].fasorce=L->elem[j+1].fasorce;
                   L->elem[j+1].fasorce=s;
                }
        }
    }
}


void display(h){
    SeqlistS ls;
    SeqlistT lt;
    ls.last=-1;
    lt.last=-1;
    switch(h){
        case 1://节目信息 从文件中读取
            loads(&ls);
            shows(&ls);
            break;
        case 2://裁判信息 开始录入✅
            teachers(&lt);
            save(&lt);
            showt(&lt);
            break;
        case 3://录入得分并计算最终得分✅
            input(&ls);
            break;
        case 4://排序 节目得分排序
            sort(&ls);
            shows(&ls);
            break;
        case 5://保存
            save(&ls);
            break;
        case 6://显示选手信息
            shows(&ls);
            break;
        case 7://显示裁判信息
            showt(&lt);
            break;
        case 0://退出系统✅
            break;
        default:
            printf("输入类型错误!\n");
    }
}

void disinput(){
    int m,h=0;
    printf("|  ------------------------------------  |\n");
    printf("|                回到主菜单？❤️            |\n");
    printf("|  ------------------------------------  |\n");
    printf("|               ✨是------(1)            |\n");
    printf("|               ✨否------(0)            |\n");
    printf("|  ------------------------------------  |\n");
    scanf("%d",&m);
    if(m==1){
        h=menu();
        display(h);
    }
    else if(m==0){
        exit(1);
    }
    else{
        printf("输入类型错误!\n");
    }
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
