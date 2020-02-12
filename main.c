#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
typedef struct student STU;
int person = 0;

struct student
{
    char name[10];
    int num;
    int age;
};

void welcome()
{
    system("clear");
    printf("\n\n\n\n\t\t\t========================================");
    printf("\n\n\t\t\t\t\tWelcome!\n");
}

void menu()
{
    system("clear");
    printf("\n\n\t************************************************************************");
    printf("\n\t\t\t\t\t请选择:");
    printf("\n\t\t\t\t\t1.添加信息");
    printf("\n\t\t\t\t\t2.查看信息");
    printf("\n\t\t\t\t\t3.查找信息");
    printf("\n\t\t\t\t\t4.删除信息");
    printf("\n\t\t\t\t\t5.修改信息");
    printf("\n\t\t\t\t\t6.退出");
    printf("\n\t************************************************************************");

}

/*添加信息*/
void AddInfo(STU *s[])
{
//    system("clear");
    printf("姓名 学号 年龄\n");
    printf("------------------------\n");
    printf("请输入信息：(bye结束添加)\n");
    while(1)
    {
        s[person] = (STU*)malloc(sizeof(STU));
        if(NULL == s[person])
        {
            printf("malloc failure!\n");
        }
        scanf("%s", s[person]->name);
        if(!strcmp(s[person]->name, "bye"))
        {
            break;
        }
        scanf("%d%d", &s[person]->num, &s[person]->age);
        getchar();
        person++;
    }
}

/*查看信息（按姓名排序）*/
void ShowAll(STU *s[])
{
//    system("clear");
    int i, j;
    STU *q[1] = {0};
    q[0] = (STU *)malloc(sizeof(STU));


    printf("information:\n");

    for(i = 0; i < person; i++)
    {
        for(j = 0; j < person - 1 - i; j++)
        {
            if(strcmp(s[j]->name, s[j + 1]->name) > 0)
            {
                q[0] = s[j];
                s[j] = s[j + 1];
                s[j + 1] = q[0];
            }
        }
    }

    for(i = 0; i < person; i++)
    {
        printf("\e[1;35mname:%s, num:%d, age:%d\e[0m\n", s[i]->name, s[i]->num, s[i]->age);
    }
    getchar();
}

/*查找信息*/

void Search_name(char *name, STU *s[])
{
    int i, n = 0;
    for(i = 0; i < person; i++)
    {
        if(strcmp(name, s[i]->name) == 0)
        {
            n++;
            printf("name:%s, num:%d, age:%d\n", s[i]->name, s[i]->num, s[i]->age);
        }
    }

    if(n == 0)
    {
        printf("不存在!\n");
    }
}

void SearchInfo(STU *s[])
{
//    system("clear");
    char *name = (char *)malloc(sizeof(char));

    printf("请输入要查找的人的名字:\n");
    scanf("%s", name);

    Search_name(name, s);
}

/*删除信息*/

void DeleteInfo(STU *s[])
{
//    system("clear");
    int i, n = 0, j;
    char del_name[10];

    printf("请输入要删除的人的名字:\n");
    scanf("%s", del_name);
    getchar();
    getchar();

    for(i = 0; i < person; i++)
    {
        if(strcmp(del_name, s[i]->name) == 0)
        {
            n++;
            free(s[i]);
            for(j = i; j < person - 1; j++)
            {
                strcpy(s[j]->name, s[j + 1]->name);
                s[j]->num = s[j + 1]->num;
                s[j]->age = s[j + 1]->age;
            }
            person--;
        }
    }

    if(n == 0)
    {
        printf("要删除的人不存在!\n");
    }
    else
    {
        printf("删除成功！\n");
    }
}

/*修改信息*/
void Change_name(char *name, STU *s[])
{
    int i, n = 0, choice;
    char *new_name = (char *)malloc(sizeof(char));
    int new_num, new_age;

    for(i = 0; i < person; i++)
    {
        if(strcmp(name, s[i]->name) == 0)
        {
            n++;
            printf("该学生的信息如下:");
            printf("name:%s, num:%d, age:%d\n", s[i]->name, s[i]->num, s[i]->age);
            printf("----------------------------\n");
            printf("请选择要修改的内容(1.name 2.num 3.age):\n");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    printf("请输入新的名字:\n");
                    scanf("%s", new_name);
                    strcpy(s[i]->name, new_name);
                    break;
                case 2:
                    printf("请输入新的学号:\n");
                    scanf("%d", &new_num);
                    s[i]->num = new_num;
                    break;
                case 3:
                    printf("请输入新的年龄:\n");
                    scanf("%d", &new_age);
                    s[i]->age = new_age;
                    break;
            }
        }
    }

    if(n == 0)
    {
        printf("不存在!\n");
    }
}

void ChangeInfo(STU *s[])
{
//    system("clear");
    char *name = (char *)malloc(sizeof(char));

    printf("请输入要修改的人的名字:\n");
    scanf("%s", name);

    Change_name(name, s);

}

int main()
{
    struct student *s[SIZE] = {0};
    int choice;

    welcome();

    while(1)
    {
        menu();
        printf("\nPlease input choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                AddInfo(s);
                break;
            case 2:
                ShowAll(s);
                break;
            case 3:
                SearchInfo(s);
                break;
            case 4:
                DeleteInfo(s);
                break;
            case 5:
                ChangeInfo(s);
                break;
            case 6:
                exit(0);
                break;
        }
    }

    return 0;
}