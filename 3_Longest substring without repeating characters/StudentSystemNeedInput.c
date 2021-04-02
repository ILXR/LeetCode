#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#pragma warning(disable : 4996)

struct Student /*����һ���ṹ��*/
{
    char Name[25];  /*����*/
    int Age;        /*����*/
    int Num;        /*ѧ��*/
    float Score[3]; /*���Ƴɼ� ����Ӣ*/
    float Total;    /*�ܷ�*/
    float Ave;      /*ƽ����*/
};

int num; //ѧ������

//�õ�ѧ������
int Num(void);

/*����һ�����뺯������������ѧ������Ϣ*/
struct Student *Initialize(struct Student *pArr, int len);

/*����һ������������������ѧ������Ϣ*/
void Output(struct Student *pArr, int len);

/*����һ��ɾ����������ɾ��ѧ����Ϣ*/
void Delete(struct Student *pArr, int len);

/*����һ�����Һ��������ڲ��ҽṹ��*/
void Search(struct Student *pArr, int len);

/*����һ�������������޸Ľṹ��*/
void Change(struct Student *pArr, int len);

//����һ������,�������ѧ����Ϣ
void Add(struct Student *pArr, int len);

/*����һ�������������ڶ����ĳɼ�����*/
void ScoreChinese(struct Student *pArr, int len);

/*����һ�������������ڶ���ѧ�ɼ�����*/
void ScoreMath(struct Student *pArr, int len);

/*����һ�������������ڶ�Ӣ��ɼ�����*/
void ScoreEnglish(struct Student *pArr, int len);

/*����һ�������������ڶ��ܳɼ�����*/
void ScoreTotal(struct Student *pArr, int len);

int main()
{
    int num, Item;
    struct Student *pArr = NULL;
    struct Student *p = NULL;

    printf("================================================================================\n\n");
    printf("*************************��ӭʹ��ѧ���ɼ�����ϵͳ*******************************\n\n");
    printf("================================================================================\n\n");

    printf("�밴���������ѧ������ϵͳ:\n");
    getchar();

    while (1)
    {
        system("cls");
        printf("================================================================================\n\n");
        printf("------------------------ ��ѡ��Ҫ���������-----------------------------------\n\n");
        printf("-------------------------- 1 ��������ѧ����Ϣ-----------------------------------\n\n");
        printf("-------------------------- 2 �鿴����ѧ����Ϣ-----------------------------------\n\n");
        printf("-------------------------- 3 ɾ��ѧ����Ϣ---------------------------------------\n\n");
        printf("-------------------------- 4 ����ѧ����Ϣ---------------------------------------\n\n");
        printf("-------------------------- 5 �޸�ѧ����Ϣ---------------------------------------\n\n");
        printf("-------------------------- 6 ����ѧ����Ϣ---------------------------------------\n\n");
        printf("-------------------------- 7 ��ѧ�������ĳɼ��Ӵ�С����-----------------------\n\n");
        printf("-------------------------- 8 ��ѧ������ѧ�ɼ��Ӵ�С����-----------------------\n\n");
        printf("-------------------------- 9 ��ѧ����Ӣ��ɼ��Ӵ�С����-----------------------\n\n");
        printf("-------------------------- 10 ��ѧ�����ܳɼ��Ӵ�С����------------------------\n\n");
        printf("-------------------------- 11 �˳�����----------------------------------------\n\n");
        printf("================================================================================\n\n");
        printf("\n��ѡ���������;\n");
        scanf("%d", &Item);

        switch (Item)
        {
        case 1: //����ѧ����Ϣ
        {
            system("cls");
            num = Num();
            p = Initialize(pArr, num);
        }
        break;

        case 2: //���ѧ����Ϣ
        {
            system("cls");
            Output(p, num);
        }
        break;

        case 3: //ɾ��ѧ����Ϣ
        {
            system("cls");
            Delete(p, num);
        }
        break;

        case 4: //����ѧ����Ϣ
        {
            system("cls");
            Search(p, num);
        }
        break;

        case 5: //�޸�ѧ����Ϣ
        {
            system("cls");
            Change(p, num);
        }
        break;

        case 6: //���ѧ����Ϣ
        {
            system("cls");
            Add(p, num);
        }
        break;

        case 7: //��ѧ�������ĳɼ����Ӵ�С����
        {
            system("cls");
            ScoreChinese(p, num);
        }
        break;

        case 8: //��ѧ������ѧ�ɼ����Ӵ�С����
        {
            system("cls");
            ScoreMath(p, num);
        }
        break;

        case 9: //��ѧ����Ӣ��ɼ����Ӵ�С����
        {
            system("cls");
            ScoreEnglish(p, num);
        }
        break;

        case 10: //��ѧ�����ܳɼ����Ӵ�С����
        {
            system("cls");
            ScoreTotal(p, num);
        }
        break;

        case 11: //�˳�����
        {
            system("cls");
            printf("================================================================================\n\n");
            printf("***************************��л����ʹ�ã��´μ�!*********************************\n\n");
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

//�õ�ѧ������
int Num(void)
{
    printf("������ѧ��������\n");
    scanf("%d", &num);

    return num; //����ѧ������
}

struct Student *Initialize(struct Student *pArr, int len) /*����һ�����뺯������������ѧ������Ϣ*/
{
    pArr = (struct Student *)malloc(len * sizeof(struct Student)); /*Ϊѧ�������ڴ�*/

    int i;

    for (i = 0; i < len; i++)
    {
        printf("�������%d��ѧ��������:\n", i + 1); /*����ѧ��������*/
        scanf("%s", pArr[i].Name);

        printf("�������%d��ѧ��������:\n", i + 1); /*����ѧ��������*/
        scanf("%d", &pArr[i].Age);

        printf("�������%d��ѧ����ѧ��:\n", i + 1); /*����ѧ����ѧ��*/
        scanf("%d", &pArr[i].Num);

        printf("�������%d��ѧ�������ĳɼ�:\n", i + 1); /*����ѧ�������ĳɼ�*/
        scanf("%f", &pArr[i].Score[0]);

        printf("�������%d��ѧ������ѧ�ɼ�:\n", i + 1); /*����ѧ������ѧ�ɼ�*/
        scanf("%f", &pArr[i].Score[1]);

        printf("�������%d��ѧ����Ӣ��ɼ�:\n", i + 1); /*����ѧ����Ӣ��ɼ�*/
        scanf("%f", &pArr[i].Score[2]);

        //�����ܷ�
        pArr[i].Total = pArr[i].Score[0] + pArr[i].Score[1] + pArr[i].Score[2];

        //����ƽ����
        pArr[i].Ave = pArr[i].Total / 3.0f;
    }

    return pArr; /*����ѧ������Ϣ*/
}

/*����һ������������������ѧ������Ϣ*/
void Output(struct Student *pArr, int len)
{
    printf("����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");

    for (int i = 0; i < len; i++)
    {
        printf("%s\t%d\t%d\t%g\t%g\t%g\t%g\t%g\n", pArr[i].Name, pArr[i].Age, pArr[i].Num, pArr[i].Score[0], pArr[i].Score[1], pArr[i].Score[2], pArr[i].Total, pArr[i].Ave);
    }
}

/*����һ��ɾ����������ɾ��ѧ����Ϣ*/
void Delete(struct Student *pArr, int len)
{
    int i, num;
    char Name[10];

    printf("��������Ҫɾ�����ݵ�����:\n");
    scanf("%s", Name); //�õ�ɾ��ѧ��������

    for (i = 0; i < len; i++) //����ɾ����ѧ���ı��
    {
        if (0 == strcmp(pArr[i].Name, Name))
        {
            num = i;
        }
    }

    for (i = num; i < len; i++) //ɾ��ѧ��
    {
        pArr[i - 1] = pArr[i];
    }

    Output(pArr, len - 1); //���ɾ����Ľ��
}

/*����һ�����Һ��������ڲ��ҽṹ��*/
void Search(struct Student *pArr, int len)
{
    int i;
    char Name[10];

    printf("����������Ҫ���ҵ�ѧ��������\n");
    scanf("%s", Name); //�õ�ѧ��������

    for (i = 0; i < len; i++) //����ѧ�����
    {
        if (0 == strcmp(pArr[i].Name, Name))
        {
            num = i;
        }
    }

    Output(&pArr[num], 1); //����ҵ���ѧ������Ϣ
}

/*����һ�������������޸Ľṹ��*/
void Change(struct Student *pArr, int len)
{
    char Name[10];

    printf("����������Ҫ�޸ĵ�ѧ��������:\n");
    scanf("%s", Name);

    int i, num;

    for (i = 0; i < len; i++)
    {
        if (0 == strcmp(pArr[i].Name, Name)) //����ѧ�����
        {
            num = i;
        }
    }

    printf("������ѧ��������:\n"); /*����ѧ��������*/
    scanf("%s", pArr[num].Name);

    printf("������ѧ��������:\n"); /*����ѧ��������*/
    scanf("%d", &pArr[num].Age);

    printf("������ѧ����ѧ��:\n"); /*����ѧ����ѧ��*/
    scanf("%d", &pArr[num].Num);

    printf("������ѧ�������ĳɼ�:\n"); /*����ѧ�������ĳɼ�*/
    scanf("%f", &pArr[num].Score[0]);

    printf("������ѧ������ѧ�ɼ�:\n"); /*����ѧ������ѧ�ɼ�*/
    scanf("%f", &pArr[num].Score[1]);

    printf("������ѧ����Ӣ��ɼ�:\n"); /*����ѧ����Ӣ��ɼ�*/
    scanf("%f", &pArr[num].Score[2]);

    //�����ܷ�
    pArr[num].Total = pArr[num].Score[0] + pArr[num].Score[1] + pArr[num].Score[2];

    //����ƽ����
    pArr[num].Ave = pArr[num].Total / 3.0f;

    Output(pArr, len); //���ѧ����Ϣ
}

//����һ������,�������ѧ����Ϣ
void Add(struct Student *pArr, int len)
{
    int num, i;

    printf("��������ӵ�ѧ��������:\n");
    scanf("%d", &num);

    struct Student *p = NULL;

    //��̬����num���ڴ�ռ�
    p = (struct Student *)malloc(sizeof(struct Student) * num);

    for (i = 0; i < num; i++)
    {
        printf("�������%d��ѧ��������:\n", i + 1); /*����ѧ��������*/
        scanf("%s", p[i].Name);

        printf("�������%d��ѧ��������:\n", i + 1); /*����ѧ��������*/
        scanf("%d", &p[i].Age);

        printf("�������%d��ѧ����ѧ��:\n", i + 1); /*����ѧ����ѧ��*/
        scanf("%d", &p[i].Num);

        printf("�������%d��ѧ�������ĳɼ�:\n", i + 1); /*����ѧ�������ĳɼ�*/
        scanf("%f", &p[i].Score[0]);

        printf("�������%d��ѧ������ѧ�ɼ�:\n", i + 1); /*����ѧ������ѧ�ɼ�*/
        scanf("%f", &p[i].Score[1]);

        printf("�������%d��ѧ����Ӣ��ɼ�:\n", i + 1); /*����ѧ����Ӣ��ɼ�*/
        scanf("%f", &p[i].Score[2]);

        //�����ܷ�
        p[i].Total = p[i].Score[0] + p[i].Score[1] + p[i].Score[2];

        //����ƽ����
        p[i].Ave = p[i].Total / 3.0f;
    }

    Output(pArr, len); //���ѧ����Ϣ
    Output(p, num);    //���ѧ����Ϣ
}

/*����һ�������������ڶ����ĳɼ�����*/
void ScoreChinese(struct Student *pArr, int len)
{
    struct Student temp; //�м����

    for (int i = 0; i < len - 1; i++) //ð������
    {
        for (int j = 0; j < len - i; j++)
        {
            if (pArr[j].Score[0] < pArr[j + 1].Score[0]) //�����ĳɼ��Ӵ�С����
            {
                temp = pArr[j];
                pArr[j] = pArr[j + 1];
                pArr[j + 1] = temp;
            }
        }
    }

    Output(pArr, len); //��������Ľ��
}

/*����һ�������������ڶ���ѧ�ɼ�����*/
void ScoreMath(struct Student *pArr, int len)
{
    struct Student temp; //�м����

    for (int i = 0; i < len - 1; i++) //ð������
    {
        for (int j = 0; j < len - i; j++)
        {
            if (pArr[j].Score[1] < pArr[j + 1].Score[1]) //����ѧ�ɼ��Ӵ�С����
            {
                temp = pArr[j];
                pArr[j] = pArr[j + 1];
                pArr[j + 1] = temp;
            }
        }
    }

    Output(pArr, len); //��������Ľ��
}

/*����һ�������������ڶ�Ӣ��ɼ�����*/
void ScoreEnglish(struct Student *pArr, int len)
{
    struct Student temp; //�м����
    int max;             //���ֵ���±�

    for (int i = 0; i < len - 1; i++)
    {
        max = i; //�ٶ�Ӣ��ɼ������ֵ���±���i

        for (int j = i + 1; j < len; j++)
        {
            if (pArr[j].Score[2] > pArr[max].Score[2]) //����Ӣ��ɼ����ֵ���±�
            {
                max = j;
            }
        }

        if (max != i) //����
        {
            temp = pArr[max];
            pArr[max] = pArr[i];
            pArr[i] = temp;
        }
    }

    Output(pArr, len); //��������Ľ��
}

/*����һ�������������ڶ��ܳɼ�����*/
void ScoreTotal(struct Student *pArr, int len)
{
    struct Student temp; //�м����
    int max;             //���ֵ���±�

    for (int i = 0; i < len - 1; i++)
    {
        max = i; //�ٶ��ܳɼ������ֵ���±���i

        for (int j = i + 1; j < len; j++)
        {
            if (pArr[j].Total > pArr[max].Total) //�����ܳɼ����ֵ���±�
            {
                max = j;
            }
        }

        if (max != i) //����
        {
            temp = pArr[max];
            pArr[max] = pArr[i];
            pArr[i] = temp;
        }
    }

    Output(pArr, len); //��������Ľ��
}