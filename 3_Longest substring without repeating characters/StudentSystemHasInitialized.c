#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

#pragma warning(disable : 4996)

struct Student /*定义一个结构体*/
{
    char Name[25];  /*姓名*/
    int Age;        /*年龄*/
    int Num;        /*学号*/
    float Score[3]; /*三科成绩 语数英*/
    float Total;    /*总分*/
    float Ave;      /*平均分*/
};

int num; //学生人数

//得到学生人数
int Num(void);

/*定义一个输入函数，用于输入学生的信息*/
struct Student *Initialize(struct Student *pArr, int len);

/*定义一个输出函数，用于输出学生的信息*/
void Output(struct Student *pArr, int len);

/*定义一个删除函数用于删除学生信息*/
void Delete(struct Student *pArr, int &len);

/*定义一个查找函数，用于查找结构体*/
void Search(struct Student *pArr, int len);

/*定义一个函数，用于修改结构体*/
void Change(struct Student *pArr, int len);

//定义一个函数,用于添加学生信息
void Add(struct Student *pArr, int &len);

/*定义一个排序函数，用于对语文成绩排序*/
void ScoreChinese(struct Student *pArr, int len);

/*定义一个排序函数，用于对数学成绩排序*/
void ScoreMath(struct Student *pArr, int len);

/*定义一个排序函数，用于对英语成绩排序*/
void ScoreEnglish(struct Student *pArr, int len);

/*定义一个排序函数，用于对总成绩排序*/
void ScoreTotal(struct Student *pArr, int len);

int main()
{
    srand((unsigned)time(NULL));
    int num = 20, Item;
    struct Student *pArr = NULL;
    struct Student *p = NULL;
    p = Initialize(pArr, num);

    printf("================================================================================\n\n");
    printf("*************************欢迎使用学生成绩管理系统*******************************\n\n");
    printf("================================================================================\n\n");

    printf("请按任意键进入学生管理系统:\n");
    getchar();

    while (1)
    {
        system("cls");
        printf("================================================================================\n\n");
        printf("------------------------ 请选择要操作的命令：-----------------------------------\n\n");
        printf("-------------------------- 1 查看所有学生信息-----------------------------------\n\n");
        printf("-------------------------- 2 删除学生信息---------------------------------------\n\n");
        printf("-------------------------- 3 查找学生信息---------------------------------------\n\n");
        printf("-------------------------- 4 修改学生信息---------------------------------------\n\n");
        printf("-------------------------- 5 增加学生信息---------------------------------------\n\n");
        printf("-------------------------- 6 将学生的语文成绩从大到小排序-----------------------\n\n");
        printf("-------------------------- 7 将学生的数学成绩从大到小排序-----------------------\n\n");
        printf("-------------------------- 8 将学生的英语成绩从大到小排序-----------------------\n\n");
        printf("-------------------------- 9 将学生的总成绩从大到小排序------------------------\n\n");
        printf("-------------------------- 10 退出程序----------------------------------------\n\n");
        printf("================================================================================\n\n");
        printf("\n请选择操作命令;\n");
        scanf("%d", &Item);

        switch (Item)
        {
            break;

        case 1: //输出学生信息
        {
            system("cls");
            Output(p, num);
        }
        break;

        case 2: //删除学生信息
        {
            system("cls");
            Delete(p, num);
        }
        break;

        case 3: //查找学生信息
        {
            system("cls");
            Search(p, num);
        }
        break;

        case 4: //修改学生信息
        {
            system("cls");
            Change(p, num);
        }
        break;

        case 5: //添加学生信息
        {
            system("cls");
            Add(p, num);
        }
        break;

        case 6: //将学生的语文成绩按从大到小排序
        {
            system("cls");
            ScoreChinese(p, num);
        }
        break;

        case 7: //将学生的数学成绩按从大到小排序
        {
            system("cls");
            ScoreMath(p, num);
        }
        break;

        case 8: //将学生的英语成绩按从大到小排序
        {
            system("cls");
            ScoreEnglish(p, num);
        }
        break;

        case 9: //将学生的总成绩按从大到小排序
        {
            system("cls");
            ScoreTotal(p, num);
        }
        break;

        case 10: //退出程序
        {
            system("cls");
            printf("================================================================================\n\n");
            printf("***************************感谢您的使用，下次见!*********************************\n\n");
            printf("================================================================================\n\n");
            system("pause");
            return 0;
        }
        break;
        }
        system("pause");
    }
    return 0;
}

struct Student *Initialize(struct Student *pArr, int len) /*定义一个初始化函数*/
{
    pArr = (struct Student *)malloc(100 * sizeof(struct Student)); /*为学生分配内存*/
    char *names[] = {"凡小芬",
                     "文彭凤",
                     "王丽",
                     "王建华",
                     "王梓人",
                     "王震",
                     "王保真",
                     "王景亮",
                     "王丹",
                     "邓志勇",
                     "邓婕",
                     "尹会南",
                     "叶汝红",
                     "付伟娜",
                     "付双红",
                     "毕泗迁",
                     "孙平",
                     "毛华强",
                     "孙益奇",
                     "孙媛媛",
                     "伍婷",
                     "阳倩莹",
                     "刘小梅",
                     "刘俊鸣",
                     "刘海兵",
                     "刘伟华",
                     "文明",
                     "刘启龙",
                     "刘勇辉",
                     "吕红",
                     "朱智新",
                     "张建辉",
                     "李湘群",
                     "李自新",
                     "李俊",
                     "李娟",
                     "李君琳",
                     "罗咏梅",
                     "罗心悦",
                     "周婷",
                     "周灵灵",
                     "范文远",
                     "胡水洋"};
    int i;

    for (i = 0; i < len; i++)
    {
        strcpy(pArr[i].Name, names[i]);
        pArr[i].Num = 1000 + i;
        pArr[i].Age = rand() % 3 + 15;
        pArr[i].Score[0] = rand() % 30 + 70;
        pArr[i].Score[1] = rand() % 30 + 70;
        pArr[i].Score[2] = rand() % 30 + 70;

        //计算总分
        pArr[i].Total = pArr[i].Score[0] + pArr[i].Score[1] + pArr[i].Score[2];

        //计算平均分
        pArr[i].Ave = pArr[i].Total / 3.0f;
    }

    return pArr; /*返回学生的信息*/
}

/*定义一个输出函数，用于输出学生的信息*/
void Output(struct Student *pArr, int len)
{
    printf("姓名\t年龄\t学号\t语文\t数学\t英语\t总分\t平均分\n");

    for (int i = 0; i < len; i++)
    {
        printf("%s\t%d\t%d\t%g\t%g\t%g\t%g\t%g\n", pArr[i].Name, pArr[i].Age, pArr[i].Num, pArr[i].Score[0], pArr[i].Score[1], pArr[i].Score[2], pArr[i].Total, pArr[i].Ave);
    }
}

/*定义一个删除函数用于删除学生信息*/
void Delete(struct Student *pArr, int &len)
{
    int i, num, Item, ID;
    char Name[10];

    printf("请输入查找类型:\n");
    printf("1:按照姓名\n");
    printf("2:按照学号\n");
    printf("\n请选择操作命令;\n");
    scanf("%d", &Item);
    if (Item == 1)
    {
        printf("请输入你要删除数据的姓名:\n");
        scanf("%s", Name);        //得到删除学生的姓名
        for (i = 0; i < len; i++) //查找删除的学生的编号
        {
            if (0 == strcmp(pArr[i].Name, Name))
            {
                num = i;
                break;
            }
        }

        for (i = num + 1; i < len; i++) //删除学生
        {
            pArr[i - 1] = pArr[i];
        }
        len--;
        Output(pArr, len); //输出删除后的结果
    }
    else
    {
        printf("请输入你要删除数据的学号:\n");
        scanf("%d", &ID); //得到学生的ID

        for (i = 0; i < len; i++) //查找学生编号
        {
            if (ID == pArr[i].Num)
            {
                num = i;
                break;
            }
        }
        for (i = num + 1; i < len; i++) //删除学生
        {
            pArr[i - 1] = pArr[i];
        }
        len--;
        Output(pArr, len); //输出删除后的结果
    }
}

/*定义一个查找函数，用于查找结构体*/
void Search(struct Student *pArr, int len)
{
    int i, Item, ID;
    char Name[10];

    printf("请输入查找类型:\n");
    printf("1:按照姓名\n");
    printf("2:按照学号\n");
    printf("\n请选择操作命令;\n");
    scanf("%d", &Item);
    if (Item == 1)
    {
        printf("请输入你需要查找的学生的姓名\n");
        scanf("%s", Name); //得到学生的姓名

        for (i = 0; i < len; i++) //查找学生编号
        {
            if (0 == strcmp(pArr[i].Name, Name))
            {
                Output(&pArr[i], 1); //输出找到的学生的信息
            }
        }
    }
    else
    {
        printf("请输入你需要查找的学生的学号\n");
        scanf("%d", &ID); //得到学生的姓名

        for (i = 0; i < len; i++) //查找学生编号
        {
            if (ID == pArr[i].Num)
            {
                Output(&pArr[i], 1); //输出找到的学生的信息
                break;
            }
        }
    }
}

/*定义一个函数，用于修改结构体*/
void Change(struct Student *pArr, int len)
{
    int ID;

    printf("请输入你需要修改的学生的学号:\n");
    scanf("%d", &ID);

    int i, num(-1);

    for (i = 0; i < len; i++)
    {
        if (ID == pArr[i].Num) //查找学生编号
        {
            num = i;
            break;
        }
    }
    if (num == -1)
    {
        printf("查无此人\n");
    }
    else
    {
        printf("请输入学生的姓名:\n"); /*输入学生的姓名*/
        scanf("%s", pArr[num].Name);

        printf("请输入学生的年龄:\n"); /*输入学生的年龄*/
        scanf("%d", &pArr[num].Age);

        printf("请输入学生的学号:\n"); /*输入学生的学号*/
        scanf("%d", &pArr[num].Num);

        printf("请输入学生的语文成绩:\n"); /*输入学生的语文成绩*/
        scanf("%f", &pArr[num].Score[0]);

        printf("请输入学生的数学成绩:\n"); /*输入学生的数学成绩*/
        scanf("%f", &pArr[num].Score[1]);

        printf("请输入学生的英语成绩:\n"); /*输入学生的英语成绩*/
        scanf("%f", &pArr[num].Score[2]);

        //计算总分
        pArr[num].Total = pArr[num].Score[0] + pArr[num].Score[1] + pArr[num].Score[2];

        //计算平均分
        pArr[num].Ave = pArr[num].Total / 3.0f;

        Output(pArr, len); //输出学生信息
    }
}

//定义一个函数,用于添加学生信息
void Add(struct Student *pArr, int &len)
{
    int num, i;

    printf("请输入添加的学生的人数:\n");
    scanf("%d", &num);

    for (i = len; i < len + num; i++)
    {
        printf("请输入第%d个学生的姓名:\n", i + 1); /*输入学生的姓名*/
        scanf("%s", pArr[i].Name);

        printf("请输入第%d个学生的年龄:\n", i + 1); /*输入学生的年龄*/
        scanf("%d", &pArr[i].Age);

        printf("请输入第%d个学生的学号:\n", i + 1); /*输入学生的学号*/
        scanf("%d", &pArr[i].Num);

        printf("请输入第%d个学生的语文成绩:\n", i + 1); /*输入学生的语文成绩*/
        scanf("%f", &pArr[i].Score[0]);

        printf("请输入第%d个学生的数学成绩:\n", i + 1); /*输入学生的数学成绩*/
        scanf("%f", &pArr[i].Score[1]);

        printf("请输入第%d个学生的英语成绩:\n", i + 1); /*输入学生的英语成绩*/
        scanf("%f", &pArr[i].Score[2]);

        //计算总分
        pArr[i].Total = pArr[i].Score[0] + pArr[i].Score[1] + pArr[i].Score[2];

        //计算平均分
        pArr[i].Ave = pArr[i].Total / 3.0f;
    }
    len += num;
    Output(pArr, len); //输出学生信息
}

/*定义一个排序函数，用于对语文成绩排序*/
void ScoreChinese(struct Student *pArr, int len)
{
    struct Student temp; //中间变量

    for (int i = 0; i < len - 1; i++) //冒泡排序
    {
        for (int j = 0; j < len - i; j++)
        {
            if (pArr[j].Score[0] < pArr[j + 1].Score[0]) //对语文成绩从大到小排序
            {
                temp = pArr[j];
                pArr[j] = pArr[j + 1];
                pArr[j + 1] = temp;
            }
        }
    }

    Output(pArr, len); //输出排序后的结果
}

/*定义一个排序函数，用于对数学成绩排序*/
void ScoreMath(struct Student *pArr, int len)
{
    struct Student temp; //中间变量

    for (int i = 0; i < len - 1; i++) //冒泡排序
    {
        for (int j = 0; j < len - i; j++)
        {
            if (pArr[j].Score[1] < pArr[j + 1].Score[1]) //对数学成绩从大到小排序
            {
                temp = pArr[j];
                pArr[j] = pArr[j + 1];
                pArr[j + 1] = temp;
            }
        }
    }

    Output(pArr, len); //输出排序后的结果
}

/*定义一个排序函数，用于对英语成绩排序*/
void ScoreEnglish(struct Student *pArr, int len)
{
    struct Student temp; //中间变量
    int max;             //最大值的下标

    for (int i = 0; i < len - 1; i++)
    {
        max = i; //假定英语成绩的最大值的下标是i

        for (int j = i + 1; j < len; j++)
        {
            if (pArr[j].Score[2] > pArr[max].Score[2]) //查找英语成绩最大值的下标
            {
                max = j;
            }
        }

        if (max != i) //排序
        {
            temp = pArr[max];
            pArr[max] = pArr[i];
            pArr[i] = temp;
        }
    }

    Output(pArr, len); //输出排序后的结果
}

/*定义一个排序函数，用于对总成绩排序*/
void ScoreTotal(struct Student *pArr, int len)
{
    struct Student temp; //中间变量
    int max;             //最大值的下标

    for (int i = 0; i < len - 1; i++)
    {
        max = i; //假定总成绩的最大值的下标是i

        for (int j = i + 1; j < len; j++)
        {
            if (pArr[j].Total > pArr[max].Total) //查找总成绩最大值的下标
            {
                max = j;
            }
        }

        if (max != i) //排序
        {
            temp = pArr[max];
            pArr[max] = pArr[i];
            pArr[i] = temp;
        }
    }

    Output(pArr, len); //输出排序后的结果
}