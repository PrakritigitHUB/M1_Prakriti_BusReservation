#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "utils.h"
// #include "colors.c"

BSTR *getReservationInfo(BSTR *r, int s, int *custIDmatched) // find function
{
  if (r == NULL)
    return NULL;
  BSTR *current = r;
  while (current)
  {
    // --------------------

    if (current->passengerNumber == s)
    {
      *custIDmatched = 1;
      colorRed();
      printf("\n-----------------------------------------------------------------");
      printf("\n||              NAME: %10s                               ||", (current->name));
      printf("\n||              CUSTOMER ID: %d                              ||", current->passengerNumber);
      printf("\n||              BUS NUMBER: %d                                  ||", (current->passengerNumber) / 1000);
      printf("\n||              SEAT NUMBER: %d                                 ||", (current->passengerNumber) % 100);
      printf("\n||              TICKET COST: Rs.%d                             ||", getCost(current));
      printf("\n-----------------------------------------------------------------");
      colorReset();
      getch();
      return r;
    }
    else if (current->passengerNumber > s)
      current = current->left;
    else
      current = current->right;
  }

  return NULL;
}
BSTR *insertNode(BSTR **r, int custId)
{
  if (*r == NULL)
  {

    *r = (BSTR *)malloc(sizeof(BSTR));
    (*r)->passengerNumber = custId;
    if (*r == NULL)
    {
      printf("No memory…");
      return NULL;
    }
    else
    {
      (*r)->left = (*r)->right = NULL;
      printf("\n   ENTER THE PERSON NAME: ");
      scanf("%s", &((*r)->name));
    }
  }
  else
  {
    if ((*r)->passengerNumber > custId)
    {
      (*r)->left = insertNode(&((*r)->left), custId);
    }
    else if ((*r)->passengerNumber < custId)
    {
      (*r)->right = insertNode(&((*r)->right), custId);
    }
  }
  return *r;
}
void getStatus(int busSeats[32][9])
{
  int busNum;
  getBusList();
busInput:
  printf("\n\nENTER YOUR BUS NUMBER : ");
  scanf("%d", &busNum);
  if (busNum <= 0 || busNum >= 10)
  {
    colorRed();
    printf("\n  PLEASE ENTER CORRECT BUS NUMBER !!\n");
    colorReset();
    goto busInput;
  }
  printf("\n");
  displaySeats(busSeats[busNum]);
  getch();
}
void cancelBooking(int busSeats[32][9], int randomNum)
{
  int reservationNo;
  int seat;
  int choice;
  char c;
  int seatCancel;

aa:
{
  printf("\nENTER YOUR RESERVATION NO. : ");
  scanf("%d", &reservationNo);
  if (reservationNo == randomNum)
  {
    printf("\n IS THE RESERVATION NO. CORRECT ? %d \n ENTER (Y/N) : ", reservationNo);
    scanf("%s", &c);
    if (c == 'y' || c == 'Y')
    {
      printf("\n\n============================================\n\n");
      printf("   ENTER THE BUS NO.: ");
      scanf("%d", &choice);

      printf("\n NO. OF SEATS DO YOU WANT TO CANCEL : ");
      scanf("%d", &seatCancel);
      for (int i = 0; i < seatCancel; i++)
      {
        printf("  \n  ENTER THE SEAT NO.: ");
        scanf("%d", &seat);

        busSeats[choice][seat] = 0;
      }
      printf("\n\n YOUR RESERVATION HAS BEEN CANCELLED ! \n\n");
      printf("\n  PRESS 'ENTER'TO CONTINUE \n");
      getch();
      displaySeats(busSeats[choice]);
    }

    else if (c == 'n' || c == 'N')
    {
      printf("\n YOUR RESERVATION CANCELLATION HAS BEEN DENIED \n");
    }
  }
  else
  {
    printf("\n NOT FOUND! PLEASE ENTER THE CORRECT RESERVATION NO. \n");
    goto aa;
  }
}
}
