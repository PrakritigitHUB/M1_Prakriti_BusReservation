#include<stdio.h>

void loginCred()
{
  char username[20] = "demo";
  char password[10] = "password";
  char passMatch[10];
  char userMatch[10];
  int value;
  printf("\n\n=========================================================================================\n");
  printf("\n\t\t\tWELCOME TO ONLINE BUS RESERVATION");
  printf("\n\n=========================================================================================\n\n");
loginCred:
{
  printf("\n\nusername: ");
  gets(userMatch);

  printf("\npassword: ");
  gets(passMatch);
}

  value = strcmp(password, passMatch); /// string compare is function defined in headerfile i.e string.h
  if (value != 0)
  {
    printf("\nINVALID USERNAME/ PASSWORD TRY AGAIN...\n");
    goto loginCred;
  }
  else
  {
    printf("\nLOGGING IN SUCCESSFULLY...\n");
  }
}
