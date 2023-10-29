/**
 * @file LAP_4.c
 * @author islam_atef (islam_atef@domain.com)
 * @brief   Library Management System.
 * @version 0.1
 * @date 2023-10-19
 *
 * @copyright Copyright (c) 2023
 *
 */
/*  include Section starts  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  include Section Ends  */

/*  MACRO Section starts  */
typedef struct {
  char name[100];
  char existence_state;
} _ID_;

typedef struct {
  char book_name[100];
  char author_name[100];
  int publish_year;
  int price;
  int copies_number[2];
  char existence_state;
} _BOOK_;

#define MAX_SIZE 100
/*  MACRO Section Ends  */

/*  Global Variables Section starts  */
_ID_ ID_Array[100];
_ID_ NULL_ID = {0};
_BOOK_ Book_Array[100];
_BOOK_ NULL_BOOK = {0};
int Book_Counter = 0;
/*  Global Variables Section Ends  */

/*  Sub_program Declaration Section starts  */
static int SearchByName(char *str);
static int SearchForID(void);
static void FillID(int id, char *str);

void scan(char *str);

void ADD_Book(void);
void PrintLibrary(void);
void Delete_Book(char *str);
void Borrow_Book(char *str);
void Show_Menu(void);
/*  Sub_program Declaration Section Ends  */

/*  Main Function Section starts  */
int main() {
  int proc;
  Show_Menu();
  while (1) {
  lable3:
    printf(" The process You want to perform is : ");
    scanf("%d", &proc);
    switch (proc) {
    case 1:
      system("cls");
      ADD_Book();
      Show_Menu();
      break;
    case 2:
      system("cls");
      char str[100] = {0};
      printf("\n Enter Book name :");
      scan(str);
      Borrow_Book(str);
      Show_Menu();
      break;
    case 3:
      system("cls");
      char str_1[100] = {0};
      printf("\n Enter Book name :");
      scan(str_1);
      Delete_Book(str_1);
      Show_Menu();
      break;
    case 4:
      system("cls");
      PrintLibrary();
      Show_Menu();
      break;
    default:
      if (proc != 1 || proc != 2 || proc != 3 || proc != 4) {
        goto lable3;
      }
      break;
    }
  }
  0;
}
/*  Main Function Section Ends  */

/*  Sub_program Section starts  */
/*-------------------------------------------------------------------*/
void Show_Menu(void) {
  printf("-------------------------------------------------------------\n");
  printf("                  Welcome To The Library!\n");
  printf("      You Can perform one of these Four Processes :-\n");
  printf("               (1) Adding a Book to the Library.\n");
  printf("               (2) Borrow a Book from the Library.\n");
  printf("               (3) Deleting a Book from the Library.\n");
  printf("               (4) Represent THe content of the Library.\n");
  printf("-------------------------------------------------------------\n\n");
}
/*-------------------------------------------------------------------*/
void ADD_Book(void) {
  _BOOK_ newBook = NULL_BOOK;
  volatile char local_Flag_1 = 0; // Existence Flag.
  // 1- enter the name.
  printf("Enter The Book Title : ");
  scan(newBook.book_name);

  // 2- search for this name.
  volatile int ID;
  ID = SearchByName(newBook.book_name);
  if (ID == 1111) {
    local_Flag_1 = 1; // Book already exists.
  } else {
    local_Flag_1 = 0; // The Book is new.
  }

  if (local_Flag_1 == 0) {
    Book_Array[ID].copies_number[0]++;
    Book_Array[ID].copies_number[1]++;
  } else {
    // find empty location.
    ID = SearchForID();
    if (ID != 1111) {
      printf("\nEnter The Author Name : ");
      scan(newBook.author_name);

      printf("\nEnter The Publish Year : ");
      scanf("%d", &newBook.publish_year);

      printf("\nEnter The  Price : ");
      scanf("%d", &newBook.price);

      printf("\nEnter The copies Number : ");
      scanf("%d", &newBook.copies_number[0]);
      newBook.copies_number[1] = newBook.copies_number[0];

      if (newBook.copies_number > 0) {
        newBook.existence_state = 1;
      } else {
        newBook.existence_state = 0;
      }

      if ((Book_Counter + newBook.copies_number[0]) <= MAX_SIZE) {
        Book_Array[ID] = newBook;
        FillID(ID, newBook.book_name);
        Book_Counter += newBook.copies_number[0];
      } else {
        printf("You Exceed The maximum Size of the Library");
      }
    }
  }
}
/*-------------------------------------------------------------------*/
void PrintLibrary(void) {
  int local_counter = Book_Counter;
  for (int counter = 0; (counter < 100) && (local_counter > 0); counter++) {
    if (ID_Array[counter].existence_state == 1) {
      printf("------------------------------------------------------------\n");
      printf("\n The Book Title is :%s", Book_Array[counter].book_name);
      printf("\n The Author Name is :%s", Book_Array[counter].author_name);
      printf("\n The Published Year is :%d", Book_Array[counter].publish_year);
      printf("\n The Book price is :%d", Book_Array[counter].price);
      printf("\n The total Number of Copies is :%d",
             Book_Array[counter].copies_number[0]);
      printf("\t ,The Existing Number of Copies is :%d",
             Book_Array[counter].copies_number[1]);
      if (Book_Array[counter].existence_state) {
        printf("\n The book is Available, and you can borrow \n");
      } else {
        printf("\n The book is Not available, and you can't borrow !\n");
      }
      printf("------------------------------------------------------------\n");
      local_counter -= Book_Array[counter].copies_number[0];
    }
  }
  printf(" The Number Of Books in the Library is : %d\n", Book_Counter);
  printf("------------------------------------------------------------\n");
}
/*-------------------------------------------------------------------*/
void Delete_Book(char *str) {
  int id = SearchByName(str);
  if (id == 1111) {
    printf("There is no Book With that name");
  } else {
    Book_Counter -= Book_Array[id].copies_number[0];
    Book_Array[id] = NULL_BOOK;
    ID_Array[id] = NULL_ID;
  }
}
/*-------------------------------------------------------------------*/
void Borrow_Book(char *str) {
  int id = SearchByName(str);
  if (id == 1111) {
    printf("There is no Book With that name");
  } else {
    Book_Array[id].copies_number[1]--;
    printf("You Can Borrow this Book");
  }
}
/*-------------------------------------------------------------------*/
static int SearchForID(void) {
  int returned_val = 1111;
  char local_Flag_1 = 0;
  for (int i = 0; ((i < 100) && (!local_Flag_1)); i++) {
    if (ID_Array[i].existence_state == 0) {
      returned_val = i;
      local_Flag_1 = 1;
    }
  }
  return returned_val;
}
/*-------------------------------------------------------------------*/
static int SearchByName(char *str) {
  int returned_val = 1111;
  char local_Flag_1 = 1;
  for (int i = 0; ((i < 100) && (local_Flag_1)); i++) {
    if (ID_Array[i].existence_state) {
      if (!strcmp(str, ID_Array[i].name)) {
        local_Flag_1 = 0;
        returned_val = i; // (i) is the ID of the book.
      }
    }
  }
  return returned_val;
}
/*-------------------------------------------------------------------*/
static void FillID(int id, char *str) {
  ID_Array[id].existence_state = 1;
  for (int counter = 0; str[counter] != '\0'; counter++) {
    ID_Array[id].name[counter] = str[counter];
  }
}
/*-------------------------------------------------------------------*/
void scan(char *str) {
  fflush(stdin);
  for (int i = 0; i < 100; i++) {
    scanf("%c", &str[i]);
    if (str[i] == '\n') {
      str[i] == '\0';
      break;
    }
  }
  fflush(stdin);
}
/*-------------------------------------------------------------------*/

/*  Sub_program Section Ends  */
