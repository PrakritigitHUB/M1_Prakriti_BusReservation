#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "login.c"
#include "bookings.h"

BSTR *root = NULL;
int busSeats[32][9] = {0};


int main()
{
  srand(time(0));
  int randomNum = rand();
  int num, i, custID, reservationNo;
  BSTR *root1;
  loginCred();
main:
{
  do
  {
    system("cls");
    printf("\n\n====================================================================\n\n");
    printf("\t\t\t\033[1;31mBUS RESERVATION\033[0m\t\t");
    printf("\n\n=====================================================================\n");
    printf("\n====================");
    colorRed();
    printf("  MAIN MENU ");
    colorReset();
    printf("=====================\n\n");
    printf("   \033[1;31m[1]\033[0m VIEW BUS LIST \n\n");
    printf("   \033[1;31m[2]\033[0m BOOK TICKETS\n\n");
    printf("   \033[1;31m[3]\033[0m CANCEL BOOKING\n\n");
    printf("   \033[1;31m[4]\033[0m BUSES SEATS INFO\n\n");
    printf("   \033[1;31m[5]\033[0m RESERVATION INFO\n\n");
    printf("   \033[1;31m[6]\033[0m EXIT\n");
    printf("\n=====================================================\n");
    printf("\n   ENTER YOUR CHOICE: ");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
      getBusList(); // for list of bus
      break;
    case 2:
      getBusList(); // for booking the tickets

      int customerID, choice, seats;

    busChoice:
      printf("\n\n CHOOSE YOUR BUS  : ");
      scanf("%d", &choice);
      if (choice <= 0 || choice > 9)
      {
        colorRed();
        printf("\n ENTER VALID BUS No. !! \n");
        colorReset();
        getch();
        goto busChoice;
      }
      printf("\n");
      displaySeats(busSeats[choice]);
    busSeatChoice:
      printf("\n\n NO. OF SEATS YOU WANT TO BOOK : ");
      scanf("%d", &seats);
      if (seats <= 0)
      {
        colorRed();
        printf("\n ENTER VALID SEAT NO.!\n");
        colorReset();
        goto busSeatChoice;
      }
      else if (seats > 32)
      {
        colorRed();
        printf("\nENTER VALID SEAT NO., AS WE HAVE ONLY 32 SEATS IN A BUS !!\n");
        colorReset();
        goto busSeatChoice;
      }
      int seat;
      for (int i = 1; i <= seats; i++)
      {
        printf("\n\n==================================================================================\n\n");
      seat:
        printf("   ENTER THE SEAT NO.: ");
        scanf("%d", &seat);
        if (seat <= 0)
        {
          colorRed();
          printf("\n   ENTER VALID SEAT NO.!\n\n");
          colorReset();
          goto seat;
        }
        else if (seat > 32)
        {
          colorRed();
          printf("\n   ENTER VALID SEAT NO.,AS WE HAVE ONLY 32 SEATS IN A BUS !!\n\n");
          colorReset();
          goto seat;
        }
        customerID = choice * 1000 + seat; // CustomerId
        busSeats[choice][seat] = 1;
        root = insertNode(&root, customerID);
        colorRed();
        printf("\n   YOUR CUSTOMER ID IS : %d", customerID);
        colorReset();
        printf("\n\n==================================================================================\n\n");
      }
      printf("\nYOUR RESERVATION NO. IS : ");
      colorRed();
      printf("%d\n", randomNum);
      printf("\nPLEASE NOTE DOWN YOUR RESERVATION NO. FOR CANCELLING TICKETS!!\n");
      colorReset();
      printf("PRESS 'ENTER' TO CONTINUE ");
      getch();
      break;

    case 3:
      cancelBooking(busSeats, randomNum);
      break;
    case 4:
      getStatus(busSeats);
      break;
    case 5:
    takingReservationNo:
      printf("\n   ENTER YOUR RESERVATION NO. :");
      scanf("%d", &reservationNo);

      if (randomNum == reservationNo)
      {
      cust:
        printf("\n   ENTER YOUR CUSTOMER ID :");
        scanf("%d", &custID);
        int custIDmatched = 0;
        root1 = getReservationInfo(root, custID, &custIDmatched);
        if (custIDmatched == 0)
        {
          colorRed();
          printf("\n pLEASE ENTER CORRECT CUSTOMER ID!!\n");
          colorReset();
          goto cust;
        }
      }
      else
      {
        colorRed();
        printf("\n INVALID RESERVATION NO, PLEASE ENTER CORRECT RESERVATION NO. !!\n");
        colorReset();
        goto takingReservationNo;
      }
      break;
    default:
      colorRed();
      printf("\n\n   INVALID INPUT, PLEASE CHOOSE CORRECT OPTION\n");
      colorReset();
      break;
    }
  } while (num != 6);
  printf("\n\n=====================================================================\n\n");
  printf("THANK YOU FOR USING OUR BUS RESERVATION SYSTEM");
  printf("\n\nPRESS ANY KEY TO END THE PROGRAM !! \n");
  printf("\n\n");
  getch();
  return 0;
}
}
