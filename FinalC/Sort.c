#include <stdio.h>
#include<stdlib.h>
#include "System.h"
#include "STD_TYPES.h"
void Swap(Seat *ps1,Seat *ps2)
{
    u8 i;
	u8 arr[4];
	u8 * pa=arr;
	u8 t;
	t=ps1->T->Name[0];
	for(i=0;i<4;i++)
	{arr[i]=ps1->SeatNum[i];}
	ps1->T->Name[0]=ps2->T->Name[0];
	for(i=0;i<4;i++)
	{ps1->SeatNum[i]=ps2->SeatNum[i];}
	ps2->T->Name[0]=t;
	for(i=0;i<4;i++)
	{ps2->SeatNum[i]=pa[i];}
}
void Bubble(Class* tpc,u8 n)
{
    Seat* tps=tpc->LastSeat;
	u8 i,j,flag=0;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		tps=tpc->LastSeat;
		for(j=0;j<n-i-1;j++)
		{
			if(tps->T->Name[0]>tps->BackSeat->T->Name[0])
			{
			Swap(tps,tps->BackSeat);
			flag=1;
            }
            tps=tps->BackSeat;
	}
	if(flag==0)
		break;
	}
}
