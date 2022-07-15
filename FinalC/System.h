#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED
#include "STD_TYPES.h"


typedef struct BD{
    u8   Day;
    u8   Month;
    u16  Year;
} Date;

typedef struct NodeData{
    u8   Name[50];
    Date *DateOfBirth;
    u8   ID[16];
    u8   Address[200];
    u8   Phone[12];
}Passenger;

typedef struct StackNode{
    u8                   SeatNum[4];
    u8                   Reserve;
    struct StackNode    *BackSeat;
    struct StackNode    *NextSeat;
    Passenger           *T;
}Seat;

typedef struct Stack{
    Seat *LastSeat;
    Seat *FirstSeat;
    u8 Size;
    u8 MaxSize;
}Class;

void     CreatSeat      (u8 i,u8 j,u8 *pa,Class *pc);
void     CreatClass     (Class* pc,u8 NumSeats);
void     CharSeat       (u8 *pa,u8 i);
void     ReadSeat       (u8 arr[]);
Seat*    FindSeat       (Class* pc,u8 arr[]);
void     NewPassenger   (Seat *ps,Class *pc);

void RegPassenger(Class* pc1,Class* pc2,Class* pc3);
void DelPassenger(Class* pc1,Class* pc2,Class* pc3);

void Sort(Class* pc1,Class* pc2,Class* pc3);
void    push        (Seat* ps,Class* tpc);
void Show (Class* pc,Class* tpc);
void Edit(Class* pc1,Class* pc2,Class* pc3);
void FreeSeats( Class* pc1,Class* pc2,Class* pc3);
void ClassSeatList(Class* pc1,Class* pc2,Class* pc3);

#endif // SYSTEM_H_INCLUDED
