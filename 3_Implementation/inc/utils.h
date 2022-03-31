#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "bst.h"
#include "colors.c"


int getCost(BSTR *r)
{
  int getCost, buscost;
  buscost = (r->passengerNumber) / 1000;
  switch (buscost % 3)
  {
  case 1:
    return 70;
    break;
  case 2:
    return 55;
    break;
  case 0:
    return 40;
    break;
  default:
    return 0;
    break;
  }
}


void displaySeats(int bus[33])
{
  for (int i = 1; i <= 32; i++)
  {
    colorRed();
    if (i < 10 && i > 0)
    {
      printf("0%d .", i);
    }
    else
    {
      printf("%d .", i);
    }

    colorReset();
    {
      if (bus[i] == 0)
        printf("EMPTY ");
      else
        printf("BOOKED"); // reserved
    }
    printf("         ");
    if (i % 4 == 0)
      printf("\n");
  }
}

void getBusList()
{
  colorRed();
  printf("-----------------------------------------------------------------------------------------");
  printf("\nBus.No \tName\t     \t\tDestinations   \t\tCharges   \t\tTime\n");
  printf("-----------------------------------------------------------------------------------------");
  colorReset();
  printf("\n1  \tShivom               \tCTC to Kolkata         \tRs.70    \t\t07:00  AM");
  printf("\n2  \tRoll down travels    \tKolkata To Delhi       \tRs.55    \t\t01:30  PM");
  printf("\n3  \tSushree Bus          \tAllahabad To Westbengal\tRs.40    \t\t03:50  PM");
  printf("\n4  \tSuper Deluxe         \tPokhara To BBSR        \tRs.70    \t\t01:00  AM");
  printf("\n5  \tSai ram Travels      \tBurla To Puri          \tRs.55    \t\t12:05  AM");
  printf("\n6  \tGanapati Travels     \tOlatpur to Patna       \tRs.40    \t\t09:30  AM");
  printf("\n7  \tMayuri Travels       \tPatna To Gaya          \tRs.70    \t\t11:00  PM");
  printf("\n8  \tParth Travels        \tJammu To Patna         \tRs.55    \t\t08:15  AM");
  printf("\n9  \tShree Travels        \tGaya To Chhapra        \tRs.40    \t\t04:00  PM");
  printf("\n");
  printf("\n   PRESS 'ENTER' TO CONTINUE ");
  getch();
}

