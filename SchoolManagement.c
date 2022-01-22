#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
double total1=0.00,gpa1=0.00;
struct student
{
    int id;
    int cla;
    long int p_num;
    char group[20];
    char name[20];
    char name1[20];
    char gender[20];
    double bangla,english,math,reli,physics,chemistry,biology,acconting,economics,finance,sceince,ict,bgs,gpa,total,bwc,cc,ge;
    struct student *next,*prev;
}*start=NULL,*end=NULL,*current;

void create()
{
    char na[20];
    if(start==NULL && end==NULL)
    {
        struct student *new_node;
        new_node=(struct student*)malloc(1*sizeof(struct student));
        printf("Enter First Name: ");
        scanf("%s",&new_node->name);
        printf("\nEnter Last Name: ");
        scanf("%s",&new_node->name1);
        printf("\nEnter Gender: ");
        scanf("%s",&new_node->gender);
        printf("\nEnter Class: ");
        scanf("%d",&new_node->cla);
        while(1)
        {
            printf("\nEnter ID: ");
        scanf("%d",&new_node->id);
        int p1 = search(new_node->cla,new_node->id);
        if(p1>0)
        {
            printf("The ID is Already taken.\n");
            continue;
        }
        else
        {
            break;
        }
        }
        new_node->gpa = 0.00;
        new_node->total=0.00;
        if(new_node->cla ==9 || new_node->cla ==10)
        {
            printf("\nEnter Group: ");
            scanf("%s",&new_node->group);
        }
        else
        {
            char ec[10] = "NULL";
            strcpy(new_node->group,ec);
        }
        printf("\nEnter Parents Phone Number: ");
        scanf("%ld",&new_node->p_num);
        new_node->next=NULL;
        new_node->prev=NULL;
        start=new_node;
        end=new_node;
        current=new_node;
        system("cls");
    }
    else
    {
        struct student *new_node;
        new_node=(struct student*)malloc(1*sizeof(struct student));
        printf("Enter First Name: ");
        scanf("%s",&new_node->name);
        printf("\nEnter Last Name: ");
        scanf("%s",&new_node->name1);
        printf("\nEnter Gender: ");
        scanf("%s",&new_node->gender);
        printf("\nEnter Class: ");
        scanf("%d",&new_node->cla);
        new_node->gpa = 0.00;
        new_node->total=0.00;
       while(1)
        {
            printf("\nEnter ID: ");
        scanf("%d",&new_node->id);
        int p1 = search(new_node->cla,new_node->id);
        if(p1>0)
        {
            printf("The ID is Already taken.\n");
            continue;
        }
        else
        {
            break;
        }
        }
        if(new_node->cla ==9 || new_node->cla ==10)
        {
            printf("\nEnter Group: ");
            scanf("%s",&new_node->group);
        }
        else
        {
            char ec[10] = "NULL";
            strcpy(new_node->group,ec);
        }
        printf("\nEnter Parents Phone Number: ");
        scanf("%ld",&new_node->p_num);
        new_node->next=NULL;
        new_node->prev=NULL;
        current->next=new_node;
        new_node->prev=current;
        end=new_node;
        current=new_node;
        system("cls");
    }
}
void dis(int a)
{
    int n=0,i=1;
    struct student *c;
    c=start;
    while(c!=NULL)
    {
        if(c->cla==a)
        {

            printf("\t%d:\n\nName: %s %s  Gender: %s\nID: %d    Group: %s\nGPA: %.2lf   Total Marks: %.2lf",i,c->name,c->name1,c->gender,c->id,c->group,c->gpa,c->total);
            printf("\n\n");
            i++;


            n++;
        }
        c=c->next;
    }
    //return n;
    if(n==0)
        printf("\n\nThere is no student in this Class\n");
    else
        printf("\n\nTotal Student %d\n",n);
}

struct teacher
{
    int id;
    char name[20];
    char name1[20];
    char gender[20];
    char group[20];
    long int phnum;
    struct teacher *next,*prev;

}*start1=NULL,*end1=NULL,*current1;
void create1()
{
    struct teacher *new_node;
    if(start1==NULL && end1==NULL)
    {
        new_node=(struct teacher*)malloc(1*sizeof(struct teacher));
        printf("Enter First Name: ");
        scanf("%s",&new_node->name);
        printf("\nEnter Last Name: ");
        scanf("%s",&new_node->name1);
        printf("\nEnter ID: ");
        scanf("%d",&new_node->id);
        printf("\nEnter Group: ");
        scanf("%s",&new_node->group);
        printf("\nEnter Gender: ");
        scanf("%s",&new_node->gender);
        printf("\nEnter Phone Number: ");
        scanf("%ld",&new_node->phnum);
        new_node->next=NULL;
        new_node->prev=NULL;

        start1=new_node;
        end1=new_node;
        current1=new_node;
        system("cls");

    }
    else
    {
        new_node=(struct teacher*)malloc(1*sizeof(struct teacher));
        printf("Enter First Name: ");
        scanf("%s",&new_node->name);
        printf("\nEnter Last Name: ");
        scanf("%s",&new_node->name1);
        printf("\nEnter ID: ");
        scanf("%d",&new_node->id);
        printf("\nEnter Group: ");
        scanf("%s",&new_node->group);
        printf("\nEnter Gender: ");
        scanf("%s",&new_node->gender);
        printf("\nEnter Phone Number: ");
        scanf("%ld",&new_node->phnum);
        new_node->next=NULL;
        new_node->prev=NULL;

        current1->next=new_node;
        new_node->prev=current1;
        current1=new_node;
        end1=new_node;
        system("cls");
    }



}
void dis1()
{
    struct teacher *c;
    c=start1;
    while(c!=NULL)
    {
        printf("Teacher ID:%d\n",c->id);
        printf("Your group:%s\n",c->group);
        printf("Teacher Name:%s %s\n",c->name,c->name1);
        printf("Teacher Gender:%s\n",c->gender);
        printf("Teacher Phone number:%ld\n",c->phnum);
        c=c->next;
    }
}
int search(int a,int y)
{
    struct student *c;
    struct teacher *c1;
    int po=0;
    if(a>0 && y>0)
    {
        c=start;
        while(c != NULL)
        {
            po++;
            if(c->cla==a && c->id == y)
            {
                return po;
            }
            c=c->next;
        }
        return -1;
    }
    else
    {
        c1=start1;
        while(c1!=NULL)
        {
            po++;
            if(c1->id==a)
            {
                return po;
            }
            c1=c1->next;
        }
        return -1;

    }
}
void print1()
{
    printf("\n\n\n");
    printf("\t\t\t1.Enter Student Details.\n");
    printf("\t\t\t2.View All Student Details\n");
    printf("\t\t\t3.Search Student Details.\n");
    printf("\t\t\t4.Enter Teacher Details.\n");
    printf("\t\t\t5.View All Teacher Details\n");
    printf("\t\t\t6.Search Teacher Details.\n");
    printf("\t\t\t7.Enter Student Results\n");
    printf("\t\t\t8.View Student Result\n");
    printf("\t\t\t9.Exit.\n");
}
void print2()
{
    printf("\n\n\n");
    //printf("\t\t\t1.Enter Student Details.\n");
    printf("\t\t\t1.View All Student Details\n");
    //printf("\t\t\t3.Search Student Details.\n");
    //printf("\t\t\t4.Enter Teacher Details.\n");
    printf("\t\t\t2.View All Teacher Details\n");
    printf("\t\t\t3.Search Teacher Details.\n");
    //printf("\t\t\t7.Enter Student Results\n");
    printf("\t\t\t4.View Student Result\n");
    printf("\t\t\t5.Exit.\n");
}
void cls()
{
    system("cls");
}

void print()
{
    int i;
    printf(" ");
    for(i=1; i<=59; i++)
    {
        printf("* ");
    }
    printf("\n\n");
    printf("\t\t\t\t\tDAFFODIL INTERNATIONAL SCHOOL\n\n");
    printf(" ");
    for(i=1; i<=59; i++)
    {
        printf("* ");
    }
    printf("\n");
}
void admin_and_student(int z)
{
    int exit = 0,x;
    while(1)
    {

        if(exit==1)
        {
            break;
        }
        //int x;
        cls();
        print();
        if(z==1)
        {
            print1();
        }
        else if(z==2)
        {
            print2();
        }
        scanf("%d",&x);
        if(z==2)
        {
            if(x==1)
                x=2;
            else if(x==2)
                x=5;
            else if(x==3)
                x=6;
            else if(x==4)
                x=8;
            else if(x==5)
                x=9;
        }
        switch(x)
        {
        case 1:
        {
            while(1)
            {
                system("cls");
                print();
                create();
                print();
                printf("\t\tDo you want to continue?\n");
                printf("1.Yes   2.No\n");
                int e;
                scanf("%d",&e);
                if(e==1)
                    continue;
                else
                    break;
            }
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            print();
            printf("\t\t\t\t1.Class 6\n\t\t\t\t2.Class 7.\n\t\t\t\t3.Class 8.\n\t\t\t\t4.Class 9.\n\t\t\t\t5.Class 10.\n");
            int e;
            scanf("%d",&e);
            system("cls");
            switch(e)
            {
            case 1:
            {
                system("cls");
                print();
                dis(6);
                getch();
                system("cls");
                break;
            }
            case 2:
            {
                system("cls");
                print();
                dis(7);
                getch();
                system("cls");
                break;
            }
            case 3:
            {
                system("cls");
                print();
                dis(8);
                getch();
                system("cls");
                break;
            }
            case 4:
            {
                system("cls");
                print();
                dis(9);
                getch();
                system("cls");
                break;
            }
            case 5:
            {
                system("cls");
                print();
                dis(10);
                getch();
                system("cls");
                break;
            }
            }
            //dis();
            print();
            printf("\n\n\nPress any key to quit.");
            getch();
            system("cls");
            break;
        }
        case 3:
        {
            while(1)
            {
                system("cls");
                print();
                int x1,y1;
                printf("\n\n\nEnter Class: ");
                scanf("%d",&x1);
                printf("\nEnter Student ID: ");
                scanf("%d",&y1);
                system("cls");
                //print();
                int pos = search(x1,y1);
                if(pos==-1)
                {
                    print();
                    printf("\n\n\nNot Found.");
                    getch();
                    system("cls");
                }
                else
                {
                    print();
                    struct student *b;
                    b=start;
                    int j;
                    for(j=0; j<pos-1; j++)
                    {
                        b=b->next;
                    }
                    if(b->cla == 9 || b->cla == 10)
                    {
                        printf("\n\n\nName : %s %s\nGender : %s\nClass : %d\nID : %d\nGroup : %s\nParents Number : %ld\nTotal Marks: %.2lf   GPA: %.2lf\n",b->name,b->name1,b->gender,b->cla,b->id,b->group,b->p_num,b->total,b->gpa);
                    }
                    else
                    {
                        printf("\n\n\nName : %s %s\nGender : %s\nClass : %d\nID : %d\nParents Number : %ld\nTotal Marks: %.2lf   GPA: %.2lf\n",b->name,b->name1,b->gender,b->cla,b->id,b->p_num,b->total,b->gpa);
                    }
                    printf("\n\nPress any key to Quit.");
                    getch();
                    system("cls");
                }
                print();
                printf("\n\n\nDo you want to search again?\n 1.Yes  2.No\n");
                int e;
                scanf("%d",&e);
                if(e==1)
                    continue;
                else if(e==2)
                    break;

            }
            system("cls");
            break;
        }
        case 4:
        {
            while(1)
            {
                system("cls");
                print();
                create1();
                int e;
                print();
                printf("\n\n\nDo you want to Continue?\n1.Yes  2.No\n");
                scanf("%d",&e);
                if(e==1)
                    continue;
                else if(e==2)
                    break;
            }
            system("cls");
            break;
        }
        case 5:
        {
            system("cls");
            print();
            dis1();
            getch();
            system("cls");
            break;
        }
        case 6:
        {
            while(1)
            {
                system("cls");
                print();
                printf("\n\n\nEnter Id:\n");
                int k;
                scanf("%d",&k);
                int pos1 = search(k,0);
                if(pos1==-1)
                {
                    system("cls");
                    print();
                    printf("\n\n\nNot Found\n");
                    getch();
                    system("cls");
                }
                else
                {
                    system("cls");
                    print();
                    struct teacher *c;
                    c=start1;
                    int j;
                    for(j=0; j<pos1-1; j++)
                    {
                        c=c->next;
                    }
                    printf("\n\n\nTeacher Name       :%s\n",c->name);
                    printf("\nTeacher ID     :%d",c->id);
                    printf("\nGroup              :%s",c->group);
                    printf("\nTeacher Gender     :%s",c->gender);
                    printf("\nPhone number       :%ld",c->phnum);
                    getch();
                    system("cls");

                }
                print();
                printf("\n\n\nDo you want to continue?\n1.Yes 2.No\n");
                int e;
                scanf("%d",&e);
                if(e==1)
                    continue;
                else
                    break;
            }
            system("cls");
            break;
        }
        case 7:
        {
            while(1)
            {
                system("cls");
                print();
                int x1,y1;
                printf("\n\n\nEnter Class: ");
                scanf("%d",&x1);
                printf("\nEnter Student ID: ");
                scanf("%d",&y1);
                system("cls");
                int k;
                //y=2;
                int pos1 = search(x1,y1);
                if(pos1==-1)
                {
                    system("cls");
                    print();
                    printf("\n\n\nNot Found\n");
                    getch();

                }
                else
                {
                    print();
                    total1 = 0.00;
                    gpa1 = 0.00;
                    struct student *c;
                    c=start;
                    int j,k=0;
                    for(j=0; j<pos1-1; j++)
                    {
                        c=c->next;
                    }
                    printf("\n\n\nName : %s %s\n",c->name,c->name1);
                    printf("Bangla : ");
                    scanf("%lf",&c->bangla);
                    gpa(c->bangla);
                    printf("\nEnglish: ");
                    scanf("%lf",&c->english);
                    gpa(c->english);
                    printf("\nMath: ");
                    scanf("%lf",&c->math);
                    gpa(c->math);
                    if(strcmp(c->group,"Science") == 0 || strcmp(c->group,"science") == 0 || strcmp(c->group,"SCIENCE")==0)
                    {
                        printf("\nPhysics: ");
                        scanf("%lf",&c->physics);
                        gpa(c->physics);
                        printf("\nChemistry: ");
                        scanf("%lf",&c->chemistry);
                        gpa(c->chemistry);
                        printf("\nBiology: ");
                        scanf("%lf",&c->biology);
                        gpa(c->biology);
                    }
                    else if(strcmp(c->group,"Commerce") == 0 || strcmp(c->group,"commerce") == 0 || strcmp(c->group,"COMMERCE") == 0)
                    {
                        printf("\nAccounting: ");
                        scanf("%lf",&c->acconting);
                        gpa(c->acconting);
                        printf("\nFinance And Banking: ");
                        scanf("%lf",&c->finance);
                        gpa(c->finance);
                        printf("\nEconomics: ");
                        scanf("%lf",&c->economics);
                        gpa(c->economics);
                    }
                    else if(strcmp(c->group,"Arts") ==0 || strcmp(c->group,"arts")==0 || strcmp(c->group,"ARTS")==0)
                    {
                        printf("\nBangladesh and World Civilization: ");
                        scanf("%lf",&c->bwc);
                        gpa(c->bwc);
                        printf("\nGeography And Environment: ");
                        scanf("%lf",&c->ge);
                        gpa(c->ge);
                        printf("\nCivics and Citizenship :");
                        scanf("%lf",&c->cc);
                        gpa(c->cc);
                    }
                    else
                    {
                        printf("\nScience: ");
                        scanf("%lf",&c->sceince);
                        gpa(c->sceince);
                        printf("\nICT: ");
                        scanf("%lf",&c->ict);
                        gpa(c->ict);
                        printf("\nBangladesh And Global Studies: ");
                        scanf("%lf",&c->bgs);
                        gpa(c->bgs);
                    }
                    printf("\nReligion: ");
                    scanf("%lf",&c->reli);
                    gpa(c->reli);
                    //getch();
                    c->total = total1;
                    c->gpa   = gpa1/7.00;
                    getch();
                    system("cls");
                }
                int e;
                print();
                printf("\n\nDo you want to continue?\n1.Yes 2.No\n");
                scanf("%d",&e);
                if(e==1)
                    continue;
                else
                    break;

            }
            system("cls");
            break;
        }
        case 8:
        {
            while(1)
            {
                system("cls");
                print();
                int x1,y1;
                printf("\n\nEnter Class: ");
                scanf("%d",&x1);
                printf("\nEnter Student ID: ");
                scanf("%d",&y1);
                system("cls");
                int k;
                int pos1 = search(x1,y1);
                if(pos1==-1)
                {
                    printf("Not Found\n");
                    getch();
                    system("cls");
                }
                else
                {
                    system("cls");
                    struct student *c;
                    c=start;
                    int j;
                    for(j=0; j<pos1-1; j++)
                    {
                        c=c->next;
                    }
                    print();

                    if(c->cla==9 || c->cla==10)
                    {
                        printf("\n\nName : %s %s Group: %s\nClass : %d Roll : %d\n",c->name,c->name1,c->group,c->cla,c->id);
                    }
                    else
                    {
                        printf("\n\nName : %s %s Class : %d Roll : %d\n",c->name,c->name1,c->cla,c->id);
                    }
                    printf("Bangla : %.2lf",c->bangla);
                    printf("\n\nEnglish: %.2lf",c->english);

                    printf("\n\nMath: %.2lf\n",c->math);

                    if(strcmp(c->group,"Science") == 0 || strcmp(c->group,"science") == 0 || strcmp(c->group,"SCIENCE") == 0)
                    {

                        printf("\n\nPhysics: %.2lf\n",c->physics);

                        printf("\n\nChemistry: %.2lf\n",c->chemistry);

                        printf("\n\nBiology: %.2lf\n",c->biology);
                    }
                    else if(strcmp(c->group,"Commerce") ==0 || strcmp(c->group,"commerce") == 0 || strcmp(c->group,"COMMERCE")==0)
                    {
                        printf("\n\nAccounting: %.2lf",c->acconting);
                        printf("\n\nFinance And Banking: %.2lf",c->finance);
                        printf("\n\nEconomics: %.2lf",c->economics);
                    }
                    else if(strcmp(c->group,"Arts") ==0 || strcmp(c->group,"arts")==0 || strcmp(c->group,"ARTS")==0)
                    {
                        printf("\n\nBangladesh and World Civilization: %.2lf",c->bwc);
                        printf("\n\nGeography And Environment: %.2lf",c->ge);
                        printf("\n\nCivics and Citizenship: %.2lf",c->cc);
                    }
                    else
                    {
                        printf("\n\nScience: %.2lf",c->sceince);
                        printf("\n\nICT: %.2lf",c->ict);
                        printf("\n\nBangladesh And Global Studies: %.2lf",c->bgs);
                    }
                    printf("\n\nReligion: %.2lf\n",c->reli);
                    printf("\n\n\nTotal Number: %.2lf   GPA: %.2lf\n",c->total,c->gpa);

                    getch();
                    system("cls");

                }
                int e;
                print();
                printf("Do you want to continue?\n1.Yes 2.No\n");
                scanf("%d",&e);
                if(e==1)
                    continue;
                else if(e==2)
                    break;
            }
            system("cls");
            break;


        }
        case 9:
        {
            exit = 1;
            break;
        }

        }
    }
}
void gpa(double n)
{
    total1 = total1 + n;
    if(n>=80)
    {
        gpa1 = gpa1 + 5.00;
    }
    else if(n>=70 && n<80)
    {
        gpa1 = gpa1 + 4.00;
    }
    else if(n>=60 && n<70)
    {
        gpa1 = gpa1 + 3.50;
    }
    else if(n>=50 && n<60)
    {
        gpa1 = gpa1 + 3.00;
    }
    else if(n>=40 && n<50)
    {
        gpa1 = gpa1 + 2.00;
    }
    else if(n>=33 && n<40)
    {
        gpa1 = gpa1 + 0.00;
    }
}
void admin()
{
    int d=0;
    char c[10],p[10];
    while(1)
    {

        system("cls");
        print();
        if(d==1)
        {
            system("cls");
            print();
            printf("\t\t\tWrong Password! Try again.");
        }
        printf("\n\n\n");
        printf("\t\t\t\tEnter User Name: ");
        scanf("%s",c);
        printf("\n");
        printf("\t\t\t\tEnter Password: ");
        scanf("%s",&p);
        if(strcmp(c,"techy5")==0 && strcmp(p,"121172")==0)
        {
            system("cls");
            print();
            printf("\t\t\tWelcome To Daffodil International School.\n\n\n");
            printf("\t\t\tPress any key to enter in the Admin Panel\n");
            getch();
            system("cls");
            break;
        }
        else
        {
            system("cls");
            d=1;
            //printf("Wrong Password! Try again.\n");
            continue;
        }
    }
}

int main()
{
    int x,y,ex=0,d=0;
    char c[10],p[10];
    while(1)
    {
        if(ex==1)
        {
            break;
        }
        cls();
        print();
        printf("\n\n\n");
        printf("1.Admin Panel.\n\n2.Student Panel.\n\n3.Exit.\n\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
        {
            admin();
            //getch();
            admin_and_student(1);
            break;

        }
        case 2:
        {
            system("cls");
            print();
            printf("\t\t\tWelcome To Daffodil International School.\n\n\n");
            printf("\t\t\tPress any key to enter in the Student Portal.\n\n");
            getch();
            system("cls");
            admin_and_student(2);
            break;
        }
        case 3:
            {
                cls();
                print();
                printf("Thank You.\n");
                getch();
                ex=1;
                break;
            }
        }
    }
}
