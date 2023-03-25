#include <string.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define member struct membe
#define data struct dat
int totalMem = 1;
float amount, rate;
int all = 0;
float fatRate;
void gotoxy(int x, int y);
struct dat
{
    int acNum;
    char date[12];
    float fat;
    int clr;
    float ltr;
};
struct membe
{
    int acNum;
    char name[100];
};
FILE *tp;
FILE *fd;
void dateSee(FILE *fp);
void allSee(FILE *fp);
void newMember(FILE *fp);
void milk_See(FILE *fp);
int totalMember(FILE *fp);
void collectMilk(FILE *fdata, FILE *fp);
void *delMember(FILE *fp, FILE *fd);
void setting();
float Rate();
void display();
int main()
{
    system("color f1");
    display();
    fatRate = Rate();
    int option;
    FILE *fp;
    if ((fp = fopen("member.txt", "rb+")) == NULL)
    {
        if ((fp = fopen("member.txt", "wb+")) == NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }
    if ((fd = fopen("data.txt", "rb+")) == NULL)
    {
        if ((fd = fopen("data.txt", "wb+")) == NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }
    totalMem = totalMember(fp);
    while (1)
    {
        system("cls");
        printf("\n\t\t\t\t Total Member in our system : %d\n", totalMember(fp));
        printf("\n\t\t\t1 : Add new Member\n");
        printf("\n\t\t\t2 : collect milk \n");
        printf("\n\t\t\t3 : see collected milk\n");
        printf("\n\t\t\t4 : See all data\n");
        printf("\n\t\t\t5 : Delete RECORD\n");
        printf("\n\t\t\t6 : See data of spasific DATE\n");
        printf("\n\t\t\t7 : Setting\n");
        printf("\n\t\t\t0 : exit\n");
        printf("\t\t\t\t");
        option = getch();
        switch (option)
        {
        case '1':
            newMember(fp);
            break;
        case '2':
            collectMilk(fd, fp);
            break;
        case '3':
            milk_See(fp);
            break;
        case '0':
            fclose(fp);
            fclose(fd);
            exit(0);
            break;
        case '4':
            allSee(fp);
            break;
        case '5':
            delMember(fp, fd);
            break;
        case '6':
            dateSee(fp);
            break;
        case '7':
            setting();
            break;
        }
    }
    // printf("Enter the ac number\n");
    // scanf("%d",&acNum);
    // printf("Enter The quntity of milk\n");
    // scanf("%f",&s1.ltr);
    // printf("Enter The FAT\n");
    // scanf("%f",&s1.vfat);
    // printf("Enter TheCLR\n");
    // scanf("%d",&s1.clr);
    // rate =fat*fatRate;
    // amount=ltr*rate;
    // printf("AC no : %d\n",acNum);
    // printf("Name : %s\n",name);
    // printf("Milk Qun.ltr. : %.1f\n",ltr);
    // printf("FAT. :          %.1f\n",fat);
    // printf("CLR :           %d\n",clr);
    // printf("Rs / ltr :      %.2f\n",rate);
    // printf("Total Amount :  %.2f\n",amount);
    getch();

    return 0;
}
void newMember(FILE *fp)
{
    system("cls");
    int a = 'y';
    member m;
    fseek(fp, 0, SEEK_END);
    while (a == 'y' || a == 'Y')
    {
        m.acNum = (totalMem + 1);
        printf("\t\t\t\t");
        printf("Your AC number is :%d\n", m.acNum);
        printf("\t\t\t\t");
        printf("Enter the full name of member\n");
        printf("\t\t\t\t");
        fflush(stdin);
        fgets(m.name, 100, stdin);
        m.name[strlen(m.name) - 1] = '\0';
        // printf("Enter The quntity of milk\n");
        // scanf("%f",&m.ltr);
        // printf("Enter The FAT\n");
        // scanf("%f",&m.fat);
        // printf("Enter TheCLR\n");
        // scanf("%d",&m.clr);
        // write in file
        fwrite(&m, sizeof(m), 1, fp);
        totalMem++;
        printf("\t\t\t\t");
        printf("Do you want to add more member\n");
        printf("\t\t\t\t");
        scanf("%c", &a);
    }
    printf("\t\t\t\t");
    system("pause");
}
void gotoxy(int x, int y)
{
    COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}
void collectMilk(FILE *fdata, FILE *fp)
{
    system("cls");
    char date[11];
    printf("\t\t\t\t");
    printf("Enter date of today in DD/MM/YYYY format\n");
    printf("\t\t\t\t");
    scanf("%s", &date);
    char ab = '1';
    fseek(fdata, 0, SEEK_END);
    member mem;

    do
    {
        system("cls");
        data m;
        m.date[0] = date[0];
        m.date[1] = date[1];
        m.date[2] = date[2];
        m.date[3] = date[3];
        m.date[4] = date[4];
        m.date[5] = date[5];
        m.date[6] = date[6];
        m.date[7] = date[7];
        m.date[8] = date[8];
        m.date[9] = date[9];
        m.date[10] = date[10];

        printf("\t\t\t\t");
        printf("Enter the AC number\n");
        printf("\t\t\t\t");
        scanf("%d", &m.acNum);
        printf("\t\t\t\t");
        rewind(fp);
        while ((fread(&mem, sizeof(mem), 1, fp)) == 1)
        {
            if (mem.acNum == m.acNum)
            {
                printf("NAME OF MEMBER -> %s\n", mem.name);
            }
        }
        printf("\t\t\t\t");
        printf("Enter the quntity of milk \n");
        printf("\t\t\t\t");
        scanf("%f", &m.ltr);
        printf("\t\t\t\t");
        printf("Enter the FAT of mlk \n");
        printf("\t\t\t\t");
        scanf("%f", &m.fat);
        if (m.fat > 10)
            m.fat = 10;
        printf("\t\t\t\t");
        printf("Enter the CLR of milk\n");
        printf("\t\t\t\t");
        scanf("%d", &m.clr);
        if (m.clr > 29)
            m.clr = 29;
        if (m.clr < 23)
            m.clr = 23;
        fwrite(&m, sizeof(m), 1, fdata);
        //-----------------------------
        printf("\t\t\t\t");
        printf("Do you want to add more member\n\t\t\t\t(Y/N)\n\t\t\t\t1. YES \n\t\t\t\t2. NO\n");
        // scanf("%c", &ab);
        printf("\t\t\t\t");
        ab = getch();
        system("cls");
    } while (ab == 49 || ab == 10);

    system("pause");
    system("cls");
    // ab=getch();
}
void milk_See(FILE *fp)
{
    system("cls");
    data s;
    member m;
    int temp;
    int i, siz = sizeof(s);
    rewind(fd);
    rewind(fp);
    printf("Enter the AC number of member \n");
    scanf("%d", &temp);
    // FILE *fptr = fopen("sample.txt", "w");
    // if (fptr == NULL)
    // {
    //     printf("Could not open file");
    //     return 0;
    // }
    system("cls");
    all = 1;
    printf("\n\n AC num %d|", temp);

    while ((fread(&m, sizeof(m), 1, fp)) == 1)
    {
        if (m.acNum == temp)
        {
            printf(" NAME -%-24s \n", m.name);
        }
    }
    while ((fread(&s, siz, 1, fd)) == 1)
    {
        if (s.acNum == temp)
        {

            // printf("\n\t    date : %s", s.date);
            //     printf("\n\t\tAC NUM       : %d", s.acNum);
            // printf("\n\t\tMILK         : %.2f", s.ltr);
            // printf("\n\t\tCLR          : %d", s.clr);
            // printf("\n\t\tFAT          : %.2f", s.fat);
            rate = fatRate * s.fat;
            amount = rate * s.ltr;
            // printf("\n\t\tRATE         : %.2f", rate);
            // printf("\n\t\tTotal amount : %.2f\n", amount);

            if (all == 1)
            {
                printf("\n|     Date    |    Milk Qun|    CLR    |    FAT    |    RATE   |  Total Amount \n");
                all = 0;
            }

            printf("| %-12s", s.date);
            printf("| %-11.2f", s.ltr);
            printf("| %-10d", s.clr);
            printf("| %-10.2f", s.fat);
            printf("| %-10.2f", rate);
            printf("| %-13.2f|\n", amount);

            // printf("\n\t\t");
        }
    }
    system("pause");
}
void See(FILE *fp, int i)
{
    data s;
    member m;
    int siz = sizeof(s);
    rewind(fd);
    rewind(fp);
    while ((fread(&s, siz, 1, fd)) == 1)
    {

        // while ((fread(&m, sizeof(m), 1, fp)) == 1)
        // {
        //     if (m.acNum == i)
        //     {
        //         printf("\n\t\tNAME   : %s", m.name);
        //     }
        // }

        if (s.acNum == i)
        {
            // printf("\n\t    date : %s", s.date);
            //     printf("\n\t\tAC NUM       : %d", s.acNum);
            // printf("\n\t\tMILK         : %.2f", s.ltr);
            // printf("\n\t\tCLR          : %d", s.clr);
            // printf("\n\t\tFAT          : %.2f", s.fat);
            rate = fatRate * s.fat;
            amount = rate * s.ltr;
            // printf("\n\t\tRATE         : %.2f", rate);
            // printf("\n\t\tTotal amount : %.2f\n", amount);

            if (all == 1)
            {
                printf("\n  Ac no.| Name                    |     Date    |    Milk Qun|    CLR    |    FAT    |    RATE   |  Total Amount \n");
                all = 0;
            }
            printf("  %-6d|", s.acNum);
            rewind(fp);
            while ((fread(&m, sizeof(m), 1, fp)) == 1)
            {
                if (m.acNum == i)
                {
                    printf(" %-24s", m.name);
                }
            }

            printf("| %-12s", s.date);
            printf("| %-11.2f", s.ltr);
            printf("| %-10d", s.clr);
            printf("| %-10.2f", s.fat);
            printf("| %-10.2f", rate);
            printf("| %-13.2f|\n", amount);
        }
        // printf("\n\t\t");
    }
}
void allSee(FILE *fp)
{
    system("cls");
    system("color f1");
    for (int i = 1; i <= totalMem; i++)
    {
        if (i == 1)
            all = 1;

        See(fp, i);
        // printf("\nRady for next\n\n");
        // system("pause");
        // system("cls");
    }
    system("pause");
}
int totalMember(FILE *fp)
{
    int big = 0;
    member m;
    rewind(fp);
    while ((fread(&m, sizeof(m), 1, fp)) == 1)
    {
        if (m.acNum > big)
        {
            big = m.acNum;
        }
    }
    return big;
}
void *delMember(FILE *fp, FILE *fd)
{
    system("cls");
    // change color of console
    system("color f1");
    data s;
    int flag = 0, tempAcNum, siz = sizeof(s);
    // control of delete if we delete multiple record
    FILE *ft;
    // make new temp.txt file for copy the data of data.txt and rename it
    if ((ft = fopen("temp.txt", "wb+")) == NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fd;
    }
    char date[12];
    printf("Enter DATE for delete record in DD/MM/YYYY format\n");
    scanf("%s", &date);
    all = 1;
    system("cls");
    // check the ac num with 1 and incress i for next ac
    member m;
    int i = 1;
    while (i <= totalMem)
    {
        int siz = sizeof(s);
        // rewind file for again read
        rewind(fd);
        rewind(fp);
        while ((fread(&s, siz, 1, fd)) == 1)
        {
            if (strcmp(s.date, date) == 0)
            {
                // to view in gt formate
                if (s.acNum == i)
                {
                    rate = fatRate * s.fat;
                    amount = rate * s.ltr;
                    if (all == 1)
                    {
                        printf("\n  Ac no.| Name                    |     Date    |    Milk Qun|    CLR    |    FAT    |    RATE   |  Total Amount \n");
                        all = 0;
                    }
                    printf("  %-6d|", s.acNum);
                    rewind(fp);
                    while ((fread(&m, sizeof(m), 1, fp)) == 1)
                    {
                        if (m.acNum == i)
                        {
                            printf(" %-24s", m.name);
                        }
                    }

                    printf("| %-12s", s.date);
                    printf("| %-11.2f", s.ltr);
                    printf("| %-10d", s.clr);
                    printf("| %-10.2f", s.fat);
                    printf("| %-10.2f", rate);
                    printf("| %-13.2f|\n", amount);
                }
            }
        }
        i++;
    }
    printf("Enter the AC number for delete record\n");
    scanf("%d", &tempAcNum);
    rewind(fd);
    while ((fread(&s, siz, 1, fd)) == 1)
    {
        if (s.acNum == tempAcNum)
        {
            if (strcmp(s.date, date) == 0)
            {
                flag = 1;
                printf("\n\tRecord Deleted for");
                rewind(fp);
                printf("\n\t    date : %s", s.date);
                while ((fread(&m, sizeof(m), 1, fp)) == 1)
                {
                    if (m.acNum == tempAcNum)
                    {
                        printf("\n\t\tname - %s ", m.name);
                    }
                }
                printf("\n\t\tAC NUM       : %d", s.acNum);
                printf("\n\t\tMILK         : %.2f", s.ltr);
                printf("\n\t\tCLR          : %d", s.clr);
                printf("\n\t\tFAT          : %.2f", s.fat);
                rate = fatRate * s.fat;
                amount = rate * s.ltr;
                printf("\n\t\tRATE         : %.2f", rate);
                printf("\n\t\tTotal amount : %.2f\n", amount);
                char A;
                printf("CONFORM:(Y/N)\n");
                A = getch();
                if (A == 'y' || A == 'Y')
                    continue;
            }
        }
        fwrite(&s, siz, 1, ft);
    }

    // close the file pointer
    fclose(fd);
    fclose(ft);

    remove("data.txt");
    // rename the  temp.txt to data.txt
    rename("temp.txt", "data.txt");
    if ((fd = fopen("data.txt", "rb+")) == NULL)
    {
        printf("ERROR");
        return NULL;
    }
    if (flag == 0)
        printf("\n\n\t\tNO RECORD FOUND WITH THE INFORMATION\n\t");
    printf("\n\t");
    // printf("\n\n\t !!! DO you want to delete MORE \n\t YES/NO (Y/N) ");
    // char option = getch();
    // if (option == 'Y' || option == 'y')
    // {
    //     again = 1;
    //     goto delete;
    // }

    system("pause");
    return fd;
}
void dateSee(FILE *fp)
{
    // for not repet the table header
    all = 1;

    system("cls");
    // change color of console
    system("color f1");
    // check the ac num with 1 and incress i for next ac
    int i = 1;
    char date[12];
    printf("Enter date\n");
    scanf("%s", &date);
    data s;
    member m;
    while (i <= totalMem)
    {

        int siz = sizeof(s);
        // rewind file for again read
        rewind(fd);
        rewind(fp);
        while ((fread(&s, siz, 1, fd)) == 1)
        {
            if (strcmp(s.date, date) == 0)
            {
                // to view in gt formate

                // while ((fread(&m, sizeof(m), 1, fp)) == 1)
                // {
                //     if (m.acNum == i)
                //     {
                //         printf("\n\t\tNAME   : %s", m.name);
                //     }
                // }

                // to view in a table formate

                if (s.acNum == i)
                {
                    rate = fatRate * s.fat;
                    amount = rate * s.ltr;
                    if (all == 1)
                    {
                        printf("\n  Ac no.| Name                    |     Date    |    Milk Qun|    CLR    |    FAT    |    RATE   |  Total Amount \n");
                        all = 0;
                    }
                    printf("  %-6d|", s.acNum);
                    rewind(fp);
                    while ((fread(&m, sizeof(m), 1, fp)) == 1)
                    {
                        if (m.acNum == i)
                        {
                            printf(" %-24s", m.name);
                        }
                    }

                    printf("| %-12s", s.date);
                    printf("| %-11.2f", s.ltr);
                    printf("| %-10d", s.clr);
                    printf("| %-10.2f", s.fat);
                    printf("| %-10.2f", rate);
                    printf("| %-13.2f|\n", amount);
                }
            }
            // printf("\n\t\t");
        }
        i++;
    }
    system("pause");
}
void display()
{
    system("cls");
    printf("\n\t\t\t\t-------------------------------------------------------------------------\n");
    printf("\t\t\t\t|                                 HELLO                                  |\n");
    printf("\t\t\t\t|                                                                        |\n");
    printf("\t\t\t\t|                                                                        |\n");
    printf("\t\t\t\t|             WELCOME TO THE DOODH SAGAR OF GRAM KHEDAWAD                |\n");
    printf("\t\t\t\t|                                                                        |\n");
    printf("\t\t\t\t|                                                                        |\n");
    printf("\t\t\t\t|                    ADMIN NAME  ANANDILAL JI PATIDAR                    |\n");
    printf("\t\t\t\t|                                                                        |\n");
    printf("\t\t\t\t|                                                                        |\n");
    printf("\t\t\t\t|          YOU CAN COLLECT YOUR MILK TO THIS MILK COLLECTION APP         |\n");
    printf("\t\t\t\t|                                                                        |\n");
    printf("\t\t\t\t|                                                                        |\n");
    printf("\t\t\t\t|                     PREES ENTER TO START COLLECTIN                     |\n");
    printf("\t\t\t\t|                                                                        |\n");
    printf("\t\t\t\t-------------------------------------------------------------------------\n");
    getch();
}
void setting()
{
    system("cls");
    printf("\n\t\t\t\t\tSetting\n");
    printf("\t\t\t\tChose option !!\n");
    printf("\t\t\t\t1. Change Rate of the FAT\n");
    printf("\t\t\t\t2. Option\n");
    printf("\t\t\t\t3. Option\n");
    printf("\t\t\t\t4. Option\n");
    printf("\t\t\t\t");
    char option = getch();
    switch (option)
    {
    case '1':
        fatRate = Rate();
        break;

    case '2':

        break;
    }
}
float Rate()
{
    system("cls");
    float rate;

    FILE *fRate;
    if ((fRate = fopen("rate.txt", "r+")) == NULL)
    {
        if ((fRate = fopen("rate.txt", "w+")) == NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }
    printf("\t\t\t\t");

    printf("Do you want change the RATE of milk\n");
    printf("\t\t\t\t");

    printf("1 .Yes \n\t\t\t\t2 .No\n");
    printf("\t\t\t\t");
    int option = getch();
    system("cls");
    switch (option)
    {
    case '1':
        // printf("enter the date of today:");
        // scanf("%s",&ratedate);
        char pass[]="ritik777";
        char inputpass[9];
        printf("\t\t\t\t");
        printf("Please Enter PASSWORD to change the rate of milk\n");
        printf("\t\t\t\t");
        printf("PASSWORD :");
        scanf("%s",&inputpass);
        if(strcmp(pass,inputpass)==0)
        {
        printf("\t\t\t\t");
        printf(" Enter the Rate of 1.0 fat :\n");
        printf("\t\t\t\t");
        scanf("%f", &rate);
        fwrite(&rate, sizeof(rate), 1, fRate);
        }
        else
        {
            printf("\t\t\t\t !!!! WRONG PASSWORD !!!!\n");
        }
        break;

    default:
        rewind(fRate);
        fread(&rate, sizeof(rate), 1, fRate);

        printf("\t\t\t\t !!!! THANK YOU !!!!\n");
        printf("\t\t\t\t");
        printf("Rate/Fat = %f\n", rate);
        break;
    }
    printf("\t\t\t\t");
    system("pause");
    return rate;
}