#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "System.h"
#include "string.h"
#include "UI.h"
#include <conio.h>
#include "MACRO.h"

int main()
{

    u8 x;

    Class FirstClass,BusinessClass,EconomyClass,*pc1,*pc2,*pc3;

    pc1=&FirstClass;
    pc2=&BusinessClass;
    pc3=&EconomyClass;

    CreatClass(&FirstClass,FirstClassMaxSize);
    CreatClass(&BusinessClass,BusinessClassMaxSize);
    CreatClass(&EconomyClass,EconomyClassMaxSize);
    Welcome();

    while(1)
    {
    x=MainMenu();
    Handler (pc1,pc2,pc3,x);
    }
}


