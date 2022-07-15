#include <conio.h>
#include <string.h>
#include <stdio.h>
#include "System.h"
#include "UI.h"
#include "System.h"
#include "Sort.h"
#include "MACRO.h"
#include <stdlib.h>

void Welcome(void)
{
    printf("\t\t\t\t\t\t******************************\n");
    printf("\t\t\t\t\t\t*\tWelcome To Our       *\n\t\t\t\t\t\t*     Flight Booking System  *\n");
    printf("\t\t\t\t\t\t******************************\n\n\n\n");

}

u8 MainMenu(void)
{

    u8 *x=(u8*)malloc(sizeof(u8));
    u8 y;
    while(!(*x>0&&*x<=7))
    {
        StarLine;
        printf("1)Add  New Client.\n");
        printf("2)Delete a Client.\n");
        printf("3)Client List.\n");
        printf("4)Edit a Client.\n");
        printf("5)Display Free Seats.\n");
        printf("6)Class List.\n");
        printf("7)Exist Program.\n");
        printf("\nPlease chose an option >> ");
        scanf("%d",x);
    if(!(*x>0&&*x<=7))
    {
        printf("Wrong Choice\n");
        StarLine;
    }
    }

    y=*x;
    free(x);
    return y;

}

void Handler (Class* pc1,Class* pc2,Class* pc3,u8 x)
{
    u8 y;


    StarLine;
    if(x==1)
    {
        RegPassenger(pc1,pc2,pc3);
    }
    else if(x==2)
    {
       DelPassenger(pc1,pc2,pc3);
    }
    else if(x==3)
    {
        Sort(pc1,pc2,pc3);
    }
    else if(x==4)
    {
        Edit(pc1,pc2,pc3);
    }
    else if(x==5)
    {
        FreeSeats(pc1,pc2,pc3);
    }
    else if(x==6)
    {
        ClassSeatList(pc1, pc2, pc3);
    }
    else if(x==7)
    {
        printf("Are You Sure You Want To Exit?\n1)Yes\n2)No\n");
        scanf("%d",&y);
        if(y==1)
            exit(1);
    }
}
/*
void fun1(void){
Class* tpc=ResSeats(pc1);
        //Show(pc1,tpc);
        Bubble(tpc,tpc->Size);
}*/
