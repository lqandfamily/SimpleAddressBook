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
    printf("\n\t\t\t\t\t��ѡ��:");
    printf("\n\t\t\t\t\t1.�����Ϣ");
    printf("\n\t\t\t\t\t2.�鿴��Ϣ");
    printf("\n\t\t\t\t\t3.������Ϣ");
    printf("\n\t\t\t\t\t4.ɾ����Ϣ");
    printf("\n\t\t\t\t\t5.�޸���Ϣ");
    printf("\n\t\t\t\t\t6.�˳�");
    printf("\n\t************************************************************************");

}

/*�����Ϣ*/
void AddInfo(STU *s[])
{
//    system("clear");
    printf("���� ѧ�� ����\n");
    printf("------------------------\n");
    printf("��������Ϣ��(bye�������)\n");
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

/*�鿴��Ϣ������������*/
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

/*������Ϣ*/

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
        printf("������!\n");
    }
}

void SearchInfo(STU *s[])
{
//    system("clear");
    char *name = (char *)malloc(sizeof(char));

    printf("������Ҫ���ҵ��˵�����:\n");
    scanf("%s", name);

    Search_name(name, s);
}

/*ɾ����Ϣ*/

void DeleteInfo(STU *s[])
{
//    system("clear");
    int i, n = 0, j;
    char del_name[10];

    printf("������Ҫɾ�����˵�����:\n");
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
        printf("Ҫɾ�����˲�����!\n");
    }
    else
    {
        printf("ɾ���ɹ���\n");
    }
}

/*�޸���Ϣ*/
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
            printf("��ѧ������Ϣ����:");
            printf("name:%s, num:%d, age:%d\n", s[i]->name, s[i]->num, s[i]->age);
            printf("----------------------------\n");
            printf("��ѡ��Ҫ�޸ĵ�����(1.name 2.num 3.age):\n");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    printf("�������µ�����:\n");
                    scanf("%s", new_name);
                    strcpy(s[i]->name, new_name);
                    break;
                case 2:
                    printf("�������µ�ѧ��:\n");
                    scanf("%d", &new_num);
                    s[i]->num = new_num;
                    break;
                case 3:
                    printf("�������µ�����:\n");
                    scanf("%d", &new_age);
                    s[i]->age = new_age;
                    break;
            }
        }
    }

    if(n == 0)
    {
        printf("������!\n");
    }
}

void ChangeInfo(STU *s[])
{
//    system("clear");
    char *name = (char *)malloc(sizeof(char));

    printf("������Ҫ�޸ĵ��˵�����:\n");
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