#include <stdio.h>
#include "System.h"
#include "column.h"
#include <conio.h>
#include <string.h>
#include "MACRO.h"
#include <stdlib.h>
#include "string.h"

void    CreatClass  (Class* pc,u8 NumSeats){
    u8 i,j;
    pc->Size=0;
    pc->LastSeat=NULL;
    pc->FirstSeat=NULL;
    pc->MaxSize=NumSeats;
    if(NumSeats==FirstClassMaxSize)
    {
        for(i=1; i<=3; i++)
        {
            for(j=0; j<6; j++)
            {
                CreatSeat(i,j,G1,pc);
            }
        }
    }
    else if(NumSeats==BusinessClassMaxSize)
    {
        for(i=7; i<=10; i++)
        {
            for(j=0; j<6; j++)
            {
                CreatSeat(i,j,G1,pc);
            }
        }
    }
    else if(NumSeats==EconomyClassMaxSize)
    {
        for(j=0; j<4; j++)
        {
            CreatSeat(22,j,G2,pc);
        }
        for(i=23; i<=29; i++)
        {
            for(j=0; j<8; j++)
            {
                CreatSeat(i,j,G3,pc);
            }
        }
        for(j=0; j<4; j++)
        {
            CreatSeat(45,j,G2,pc);
        }
        for(i=46; i<=50; i++)
        {
            for(j=0; j<8; j++)
            {
                CreatSeat(i,j,G3,pc);
            }
        }

    }

}

void    CreatSeat(u8 i,u8 j,u8 *pa,Class *pc){
    Seat *ps=(Seat*)malloc(sizeof(Seat));
    CharSeat ((ps->SeatNum),i);

    ps->SeatNum[2]=*(pa+j);
    ps->Reserve=0;
    ps->BackSeat=pc->LastSeat;
    ps->NextSeat=NULL;
    if(!(pc->LastSeat==NULL))
        pc->LastSeat->NextSeat=ps;
    else
        pc->FirstSeat=ps;
    pc->LastSeat=ps;
}
void CharSeat (u8 *pa,u8 i){
    int x=0,y=1;
    pa[0]='0';
    while(i>0)
    {
        x=i%10;
        pa[y]=x+'0';
        y--;
        i/=10;
    }

}

void    ReadSeat(u8 arr[]){

    u8 i;
    u8 a[5];
    fgets(a,5,stdin);
    a[(strlen(a)-1)]='\0';
    strupr(a);
    if(strlen(a)==2)
    {
        arr[0]='0';
        for(i=1;i<4;i++)
        {
        arr[i]=a[i-1];
        }
    }
    else
    {
        for(i=0;i<=4;i++)
        {
        arr[i]=a[i];
        }
    }
}

Seat * FindSeat(Class* pc,u8 arr[]){
    Seat* ps=pc->LastSeat;
    while(ps)
    {
        if(!(strcmp(ps->SeatNum,arr)))
        {
            return ps;
        }
        else
        {
            ps=ps->BackSeat;
        }
    }
    printf("Wrong Seat Number\n");
    return NULL;
}

void NewPassenger(Seat *ps,Class *pc){
    Passenger *pp=(Passenger*)malloc(sizeof(Passenger));
    ps->T=pp;
    u8 i,f=1;
while(f==1)
{
    printf("Please enter passenger full name: ");
    fgets(pp->Name,50,stdin);
    pp->Name[(strlen(pp->Name)-1)]='\0';
    for(i=0;i<(strlen(pp->Name));i++)
    {
        if((pp->Name[i]>='A'&&pp->Name[i]<='Z')||(pp->Name[i]>='a'&&pp->Name[i]<='z')||(pp->Name[i]==' ')||pp->Name=='-')
        {
            f=0;
        }
        else
        {
            printf("Wrong Name Input\n");
            f=1;
            break;
        }
    }
}
f=1;


    printf("Please enter passenger address: ");
    fgets(pp->Address,200,stdin);
    pp->Address[(strlen(pp->Address)-1)]='\0';

while(f==1)
{
    printf("Please enter passenger ID: ");
    fgets(pp->ID,16,stdin);
    pp->ID[(strlen(pp->ID)-1)]='\0';
    if(strlen(pp->ID)-1==13){
    for(i=0;i<(strlen(pp->ID));i++)
    {
        if((pp->ID[i]>='0'&&pp->ID[i]<='9'))
        {
            f=0;
        }
        else
        {
            printf("Wrong ID Input\n");
            f=1;
            break;
        }
    }
    }
    else
    {
            printf("Wrong ID Input\n");
    }
}
f=1;
    Date *pd=(Date*)malloc(sizeof(Date));
    pp->DateOfBirth=pd;
while(f==1)
{
    printf("Please enter passenger date of birth \nDay>>>");
    scanf("%d", &pd->Day);
    printf("Month>>>");
    scanf("%d",&pd->Month);
    printf("Year>>>");
    scanf("%d",&pd->Year);
    printf("\n");
        if((pd->Year>1910&&pd->Year<=2022)&&(pd->Day>0&&pd->Day<=31)&&(pd->Month>0&&pd->Month<=12))
        {
            f=0;
        }
        else
        {
            printf("Wrong Date Input\n");
            f=1;
        }
}

    ps->Reserve=1;
    pc->Size++;

}

void RegPassenger(Class* pc1,Class* pc2,Class* pc3){
        u8 *y=(u8*)malloc(sizeof(u8));
        u8 s[4];
        Seat *ps=NULL;
while(1){
        printf("1)First Class\n");
        printf("2)Business Class\n");
        printf("3)Economy Class\n");
        printf("Please Enter preferred Class >> ");
        scanf("%d",y);
        if(*y>0&&*y<4)
        {
        if(*y==1)
        {
            while(ps==NULL)
            {
                printf("\n\n");
                StarLine;
                printf("Seat Range 01A >> 03K\n");
                printf("Please Enter preferred >> ");
                fflush(stdin);
                ReadSeat(s);
                ps=FindSeat(pc1,s);
            }
            if(ps->Reserve==1)
            {
                printf("Sorry This Seat Is Reserved\n");
            }
            else
                NewPassenger(ps,pc1);


        }
        else if(*y==2)
        {
            while(ps==NULL)
            {
                printf("\n\n");
                StarLine;
                printf("Seat Range 07A >> 10K\n");
                printf("Please Enter preferred >> ");
                fflush(stdin);
                ReadSeat(s);
                ps=FindSeat(pc2,s);
            }
            if(ps->Reserve==1)
            {
                printf("Sorry This Seat Is Reserved\n");
            }
            else
            NewPassenger(ps,pc2);
        }
        else if(*y==3)
        {
            while(ps==NULL)
            {
                printf("\n\n");
                StarLine;
                printf("Seat Range 22A >> 29K And 45A >> 50K\n");
                printf("Please Enter preferred >> ");
                fflush(stdin);
                ReadSeat(s);
                ps=FindSeat(pc3,s);
            }if(ps->Reserve==1)
            {
                printf("Sorry This Seat Is Reserved\n");
            }
            else
            NewPassenger(ps,pc3);
        }
        free(y);
        break;
        }
        printf("Wrong Choice\n" );
        StarLine;
}
}

void DelPassenger(Class* pc1,Class* pc2,Class* pc3){
        u8 *y=(u8*)malloc(sizeof(u8));
        u8 s[4];
        Seat *ps=NULL;
while(1){
        printf("1)First Class\n");
        printf("2)Business Class\n");
        printf("3)Economy Class\n");
        printf("Please Enter Client Class >>");
        scanf("%d",y);
        if(*y<4&&*y>0)
        {
        StarLine;
        if(*y==1)
        {
            while(ps==NULL)
            {
                printf("Please Enter Client Seat >>");
                fflush(stdin);
                ReadSeat(s);
                ps=FindSeat(pc1,s);
            }
            if(ps->Reserve==0)
            {
                printf("This Seat is not Reserved\n");
            }
            else
            {
                ps->Reserve=0;
                pc1->Size--;
                printf("Account Deleted\n");
            }
        }
        else if(*y==2)
        {
            while(ps==NULL)
            {
                printf("Please Enter Client Seat >>");
                fflush(stdin);
                ReadSeat(s);
                ps=FindSeat(pc2,s);
            }
            if(ps->Reserve==0)
            {
                printf("This Seat is not Reserved\n");
            }
            else
            {
                ps->Reserve=0;
                pc2->Size--;
                printf("Account Deleted\n");
            }
        }
        else if(*y==3)
        {
            while(ps==NULL)
            {
                printf("Please Enter Client Seat >>");
                fflush(stdin);
                ReadSeat(s);
                ps=FindSeat(pc3,s);
            }
            if(ps->Reserve==0)
            {
                printf("This Seat is not Reserved\n");
            }
            else
            {
                ps->Reserve=0;
                pc3->Size--;
                printf("Account Deleted\n");
            }
        }
        free(y);
        break;
        }
        printf("Wrong Choice\n" );
        StarLine;
    }
}

Class * ResSeats(Class* pc){
    Class* tpc=(Class*)malloc(sizeof(Class));
    Seat* ps=pc->LastSeat;
    tpc->LastSeat=NULL;
    tpc->Size=0;
    while(ps)
    {
        if(ps->Reserve==1)
        {
            push(ps,tpc);
        }
        ps=ps->BackSeat;
    }
    StarLine;
    return tpc;
}

void    push        (Seat* ps,Class* tpc){
    u8 i;
    Seat *tps=(Seat*)malloc(sizeof(Seat));
    tps->T=ps->T;
    for(i=0;i<4;i++)
	{tps->SeatNum[i]=ps->SeatNum[i];}
    tps->BackSeat=tpc->LastSeat;
    tpc->LastSeat=tps;
    tpc->Size++;
}


void Edit(Class* pc1,Class* pc2,Class* pc3){
 u8 *y=(u8*)malloc(sizeof(u8));
        u8 s[4];
        Seat *ps=NULL;
while(1){
        printf("1)First Class\n");
        printf("2)Business Class\n");
        printf("3)Economy Class\n");
        printf("Please Enter Client Class >>");
        scanf("%d",y);
        StarLine;
        if(*y>0&&*y<4){
        if(*y==1)
        {
            while(ps==NULL)
            {
                printf("Please Enter Client Seat >>");
                fflush(stdin);
                ReadSeat(s);
                ps=FindSeat(pc1,s);
            }
            if(ps->Reserve==1)
            {
            StarLine;
            printf("1)Edit Name.\n");
            printf("2)Edit ID.\n");
            printf("3)Edit Address.\n");
            printf("4)Edit Date Of Birth.\n");
            printf("Please Enter Client Class >>");
            scanf("%d",y);
            StarLine;
            if(*y==1)
            {
                printf("Enter The New Name: ");
                fflush(stdin);
                fgets(ps->T->Name,50,stdin);
                ps->T->Name[(strlen(ps->T->Name)-1)]='\0';
            }
            else if(*y==2)
            {
                printf("Enter The New ID: ");
                fflush(stdin);
                fgets(ps->T->ID,16,stdin);
                ps->T->ID[(strlen(ps->T->ID)-1)]='\0';

            }
           else if(*y==3)
            {
                printf("Enter The New Address: ");
                fflush(stdin);
                fgets(ps->T->Address,200,stdin);
                ps->T->Address[(strlen(ps->T->Address)-1)]='\0';

            }
           else if(*y==4)
            {
                printf("Please enter passenger date of birth \nDay>>>");
                scanf("%d", &ps->T->DateOfBirth->Day);
                printf("Month>>>");
                scanf("%d",&ps->T->DateOfBirth->Month);
                printf("Year>>>");
                scanf("%d",&ps->T->DateOfBirth->Year);
            }
        }
            else
            {
                printf("Seat Is Not Reserved\n");
            }

        }
        else if(*y==2)
        {
            while(ps==NULL)
            {
                printf("Please Enter Client Seat >>");
                fflush(stdin);
                ReadSeat(s);
                ps=FindSeat(pc2,s);
            }
            if(ps->Reserve==1)
            {
             StarLine;
            printf("1)Edit Name.\n");
            printf("2)Edit ID.\n");
            printf("3)Edit Address.\n");
            printf("4)Edit Date Of Birth.\n");
            printf("Please Enter Client Class >>");
            scanf("%d",y);
            StarLine;
            if(*y==1)
            {
                printf("Enter The New Name: ");
                fflush(stdin);
                fgets(ps->T->Name,50,stdin);
                ps->T->Name[(strlen(ps->T->Name)-1)]='\0';
            }
            else if(*y==2)
            {
                printf("Enter The New ID: ");
                fflush(stdin);
                fgets(ps->T->ID,16,stdin);
                ps->T->ID[(strlen(ps->T->ID)-1)]='\0';

            }
           else if(*y==3)
            {
                printf("Enter The New Address: ");
                fflush(stdin);
                fgets(ps->T->Address,200,stdin);
                ps->T->Address[(strlen(ps->T->Address)-1)]='\0';

            }
           else if(*y==4)
            {
                printf("Please enter passenger date of birth \nDay>>>");
                scanf("%d", &ps->T->DateOfBirth->Day);
                printf("Month>>>");
                scanf("%d",&ps->T->DateOfBirth->Month);
                printf("Year>>>");
                scanf("%d",&ps->T->DateOfBirth->Year);
            }
        }
            else
            {
                printf("Seat Is Not Reserved\n");
            }
        }
        else if(*y==3)
        {
            while(ps==NULL)
            {
                printf("Please Enter Client Seat >>");
                fflush(stdin);
                ReadSeat(s);
                ps=FindSeat(pc3,s);
            }
            if(ps->Reserve==1)
            {
             StarLine;
            printf("1)Edit Name.\n");
            printf("2)Edit ID.\n");
            printf("3)Edit Address.\n");
            printf("4)Edit Date Of Birth.\n");
            printf("Please Enter Client Class >>");
            scanf("%d",y);
            StarLine;
            if(*y==1)
            {
                printf("Enter The New Name: ");
                fflush(stdin);
                fgets(ps->T->Name,50,stdin);
                ps->T->Name[(strlen(ps->T->Name)-1)]='\0';
            }
            else if(*y==2)
            {
                printf("Enter The New ID: ");
                fflush(stdin);
                fgets(ps->T->ID,16,stdin);
                ps->T->ID[(strlen(ps->T->ID)-1)]='\0';

            }
           else if(*y==3)
            {
                printf("Enter The New Address: ");
                fflush(stdin);
                fgets(ps->T->Address,200,stdin);
                ps->T->Address[(strlen(ps->T->Address)-1)]='\0';

            }
           else if(*y==4)
            {
                printf("Please enter passenger date of birth \nDay>>>");
                scanf("%d", &ps->T->DateOfBirth->Day);
                printf("Month>>>");
                scanf("%d",&ps->T->DateOfBirth->Month);
                printf("Year>>>");
                scanf("%d",&ps->T->DateOfBirth->Year);
            }
            }
            else
            {
                printf("Seat Is Not Reserved\n");
            }
        }
            free(y);
            break;
        }
        printf("Wrong Choice\n" );
        StarLine;
}
}


void Show (Class* pc,Class* tpc){
    u8 i=1;
    Seat* ps=pc->LastSeat;
    Seat* tps=tpc->LastSeat;

    while(tps)
    {
        while(ps)
        {
        if(!(strcmp(ps->SeatNum,tps->SeatNum)))
        {
        printf("%d>>   ",i);
       printf("Seat :%s\t\t",ps->SeatNum);
       printf("Name :%s\t\t",ps->T->Name);
       printf("ID :%s\t",ps->T->ID);
       printf("Address :%s\t\t",ps->T->Address);
       printf("Born in : ");
       PrintDate;
       ps=pc->LastSeat;
       i++;
       break;
        }
       ps=ps->BackSeat;
    }
        tps=tps->BackSeat;

    }
}



void FreeSeats( Class* pc1,Class* pc2,Class* pc3){
        u8 *y=(u8*)malloc(sizeof(u8));
        Seat *ps=NULL;
        u8 i=1;
while(1){
        printf("1)First Class\n");
        printf("2)Business Class\n");
        printf("3)Economy Class\n");
        printf("Please Enter The Class >>");
        scanf("%d",y);
        StarLine;
        if(*y>0&&*y<4){
        if(*y==1)
        {
            printf("Total Number Of Free Seats Is : %d\n\n",pc1->MaxSize-pc1->Size);
        ps=pc1->FirstSeat;
            while(ps)
            {

                if(!ps->Reserve)
                    {
                    printf("%s\t",ps->SeatNum);
                    i++;
                    if(i==7)
                    {
                        printf("\n\n");
                        i=1;
                    }
                    }
                  else
                  {
                      printf("RES\t");
                      i++;
                      if(i==7)
                    {
                        printf("\n\n");
                        i=1;
                    }
                  }
                ps=ps->NextSeat;
            }
            printf("\n");
        }
        else if(*y==2)
        {
            printf("Total Number Of Free Seats Is : %d\n\n",pc2->MaxSize-pc2->Size);
        ps=pc2->FirstSeat;
            while(ps)
            {

                if(!ps->Reserve)
                    {
                    printf("%s\t",ps->SeatNum);
                    i++;
                    if(i==7)
                    {
                        printf("\n\n");
                        i=1;
                    }
                    }
                    else
                  {
                      printf("RES\t");
                      i++;
                      if(i==7)
                    {
                        printf("\n\n");
                        i=1;
                    }
                  }
            ps=ps->NextSeat;
            }
            printf("\n");
        }
        else if(*y==3)
        {
            printf("Total Number Of Free Seats Is : %d\n\n",pc3->MaxSize-pc3->Size);
        ps=pc3->FirstSeat;
            while(ps)
            {

                if(!ps->Reserve)
                    {
                    printf("%s\t",ps->SeatNum);
                    i++;
                    if(i==5)
                    {
                        printf("\n\n");
                        i=1;
                    }
                    }
                    else
                  {
                      printf("RES\t");
                      i++;
                      if(i==5)
                    {
                        printf("\n\n");
                        i=1;
                    }
                  }
            ps=ps->NextSeat;
            }
            printf("\n");
        }
            free(y);
            break;
        }
        printf("Wrong Choice\n" );
        StarLine;
}
}


void ClassSeatList(Class* pc1,Class* pc2,Class* pc3){
        u8 *y=(u8*)malloc(sizeof(u8));
        Seat *ps=NULL;
while(1){
        printf("1)First Class\n");
        printf("2)Business Class\n");
        printf("3)Economy Class\n");
        printf("Please Enter The Class >>");
        scanf("%d",y);
        StarLine;
        if(*y>0&&*y<4){
        if(*y==1)
        {
        ps=pc1->FirstSeat;

            while(ps)
            {

                if(ps->Reserve)
                    {
                       printf("%s : ",ps->SeatNum);
                       printf("%s\n",ps->T->Name);
                       printf("ID :%s\n",ps->T->ID);
                       printf("Address :%s\n",ps->T->Address);
                       printf("Born in : ");
                       PrintDate;
                       printf("\n\n");

                    }
                    ps=ps->NextSeat;
            }
            StarLine;

        }
        else if(*y==2)
        {
        ps=pc2->FirstSeat;
            while(ps)
            {

                if(ps->Reserve)
                    {
                       printf("%s : ",ps->SeatNum);
                       printf("%s\n",ps->T->Name);
                       printf("ID :%s\n",ps->T->ID);
                       printf("Address :%s\n",ps->T->Address);
                       printf("Born in : ");
                       PrintDate;
                       printf("\n\n");
                    }
                    ps=ps->NextSeat;
            }
            StarLine;

        }
        else if(*y==3)
        {
        ps=pc3->FirstSeat;
            while(ps)
            {

                if(ps->Reserve)
                    {
                       printf("%s : ",ps->SeatNum);
                       printf("%s\n",ps->T->Name);
                       printf("ID :%s\n",ps->T->ID);
                       printf("Address :%s\n",ps->T->Address);
                       printf("Born in : ");
                       PrintDate;
                       printf("\n\n");
                    }
                    ps=ps->NextSeat;
            }
            StarLine;
        }
            free(y);
            break;
        }
        printf("Wrong Choice\n" );
        StarLine;
}
}

void Sort(Class* pc1,Class* pc2,Class* pc3){
        Class* tpc=(Class*)malloc(sizeof(Class));
        u8 *y=(u8*)malloc(sizeof(u8));
        u8 x;
while(1){
        printf("1)First Class\n");
        printf("2)Business Class\n");
        printf("3)Economy Class\n");
        printf("Please Enter The Class >>");
        scanf("%d",y);
        StarLine;
        if(*y>0&&*y<4){
        if(*y==1)
        {
        for(x=0;x<2;x++){
        tpc=ResSeats(pc1);
        Bubble(tpc,tpc->Size);
        }
        Show(pc1,tpc);
        if(tpc->Size==0)
        {
            printf("There are no Reserved seats\n");
        }
        }
        else if(*y==2)
        {
        for(x=0;x<2;x++){
        tpc=ResSeats(pc2);
        Bubble(tpc,tpc->Size);
        }
        Show(pc2,tpc);
        }
        if(tpc->Size==0)
        {
            printf("There are no Reserved seats\n");
        }
        else if(*y==3)
        {
        for(x=0;x<2;x++){
        tpc=ResSeats(pc3);
        Bubble(tpc,tpc->Size);
        }
        Show(pc3,tpc);
        }
        if(tpc->Size==0)
        {
            printf("There are no Reserved seats\n");
        }
        free(y);
        free(tpc);
        break;
        }
        printf("Wrong Choice\n" );
        StarLine;
    }
}

/*
void    pop         (Passenger* pe,Class* ps)
{
    Passenger *pn=ps->LastSeat;
    *pe=ps->LastSeat->T;
    ps->top=ps->top->next;
    free(pn);
    ps->Size --;
}
*/




/*
void    ClearStack  (Class* ps)
{
    Seat *pn=ps->LastSeat;
    while(pn)
    {
        if(pn->Reserve==0)
        {
            printf("%s\n",pn->SeatNum);
        }
        pn=pn->BackSeat;

        pn=pn->BackSeat;
        free(ps->LastSeat);
        ps->LastSeat=pn;
    }
    ps->Size=0;
}
*/
/*Seat * FindName(Class* pc,u8 arr[]){
    Seat* ps=pc->LastSeat;
    while(ps)
    {
        if(!(strcmp(ps->SeatNum,arr)))
        {
            return ps;
        }
        else
        {
            ps=ps->BackSeat;
        }
    }
    printf("Wrong Seat Number\n");
    return NULL;
}*/
