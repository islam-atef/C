/**
 * @file LAP_4.c
 * @author islam_atef (islam_atef@domain.com)
 * @brief   Vehicle Control System.
 * @version 0.1
 * @date 2023-10-19
 *
 * @copyright Copyright (c) 2023
 *
 */
/*  include Section starts  */
#include <stdio.h>
#include <stdlib.h>
/*  include Section Ends  */

/*  MACRO Section starts  */
/*  MACRO Section Ends  */

/*  Global Variables Section starts  */
int Car_Speed;
int Room_Temp;
char AC_Statue;
int Engine_Temp;
char Engine_TC_Statue;
/*  Global Variables Section Ends  */

/*  Sub_program Declaration Section starts  */
void ShowSensorMenu(void);
char TakeSensorMenuAnswer(void);
void ReadTrafficLight(void);
void ReadRoomTemp(void);
void ReadEngineTemp(void);
void CheckSpeed(void);
void DispalyStates(void);
/*  Sub_program Declaration Section Ends  */

/*  Main Function Section starts  */
int main() {
  char FLAG_1 = 1;
  int process_Val;
  volatile char SensorMenu_returnVal;
  while (FLAG_1) {
    printf("You Can Choose One Process From :-\n (1) Turn On The Engine \n (2) "
           "Turn Off The Engine \n (3) Quit The System \n You Choice is : ");
    scanf("%d", &process_Val);
    switch (process_Val) {
    case 1:
      // clear the console.
      system("cls");
      printf("The Engine Will be Turned ON. \n");
      FLAG_1 = TakeSensorMenuAnswer();
      break;
    case 2: // Repeat the Question.
      printf("The Engine Will be Turned OFF.\n");
      Car_Speed = 0;
      break;
    case 3: // Quit The System.
      FLAG_1 = 0;
      printf("You Will Quit From The System\n");
      break;
    default:
      break;
    };
  }
  return 0;
}
/*  Main Function Section Ends  */

/*  Sub_program Section starts  */
void ShowSensorMenu(void) {
  printf(" The Sensors Menu Processes are :-\n \
\t[a]. Turn off the engine.\n \
\t[b]. Set the traffic light color.\n \
\t[c]. Set the room temperature (Temperature Sensor).\n \
\t[d]. Set the engine temperature (Engine Temperature Sensor).\n");
}
/*-------------------------------------------------------------------*/
char TakeSensorMenuAnswer(void) {
  char FLAG_2 = 1;
  char SensorMenu_Val;
  while (FLAG_2 == 1) {
    CheckSpeed();
    DispalyStates();
    ShowSensorMenu();
    printf(" Choose the Process : ");
  Point_1:
    scanf("%c", &SensorMenu_Val);
    switch (SensorMenu_Val) {
    case 'a': // Turn oﬀ the engine.
    {
      printf("The Engine will be Turned off");
      FLAG_2 = 0;
      Car_Speed = 0;
      break;
    }
    case 'b': // Set the traffic light color.
    {
      ReadTrafficLight();
      break;
    }
    case 'c': // Set the room temperature (Temperature Sensor).
    {
      ReadRoomTemp();
      break;
    }
    case 'd': // Set the engine temperature (Engine Temperature Sensor).
    {
      ReadEngineTemp();
      break;
    }
    default: {
      goto Point_1;
      break;
    }
    }
    // clear the console.
    system("cls");
  }
  return FLAG_2;
}
/*-------------------------------------------------------------------*/
void ReadTrafficLight() {
  char Flag_3 = 0;
  char TrafficLight_Val;
  printf("The Traffic Light Reading {'G' / 'O' / 'R'} is ------->");
Point_1:
  if (Flag_3 == 1) {
    printf("Enter The Traffic Light Reading Again ------->");
  }
  scanf("%c\n", &TrafficLight_Val);
  switch (TrafficLight_Val) {
  case 'G': {
    Car_Speed = 100;
    break;
  }
  case 'O': {
    Car_Speed = 30;
    break;
  }
  case 'R': {
    Car_Speed = 0;
    break;
  }
  default: {
    Flag_3 = 1;
    goto Point_1;
    break;
  }
  }
  printf("\nThe Speed of the Car is -------> = %d", Car_Speed);
}
/*-------------------------------------------------------------------*/
void ReadRoomTemp() {
  int RoomTemp_Val;
  printf("The Room Temperature is ------->");
  scanf("%d", &RoomTemp_Val);
  if (RoomTemp_Val < 10) {
    AC_Statue = 1; // Turn On the AC;
    Room_Temp = 20;
  } else if (RoomTemp_Val > 30) {
    AC_Statue = 1; // Turn On the AC;
    Room_Temp = 20;
  } else {
    AC_Statue = 0; // Turn Off the AC;
    Room_Temp = RoomTemp_Val;
  }
  printf("\nThe AC state is : %d", AC_Statue);
  printf(", And The Room Temperature is : %d \n", Room_Temp);
}
/*-------------------------------------------------------------------*/
void ReadEngineTemp() {
  int EngineTemp_Val;
  printf("The Engine Temperature is ------->");
  scanf("%d", &EngineTemp_Val);
  if (EngineTemp_Val < 100) {
    Engine_TC_Statue = 1; // Turn On the AC;
    Engine_Temp = 125;
  } else if (EngineTemp_Val > 150) {
    Engine_TC_Statue = 1; // Turn On the AC;
    Engine_Temp = 125;
  } else {
    Engine_TC_Statue = 0; // Turn Off the AC;
    Engine_Temp = EngineTemp_Val;
  }
  printf("\nThe Engine Temperature Controller state is : %d", Engine_TC_Statue);
  printf(", And The Engine Temperature is : %d \n", Engine_Temp);
}
/*-------------------------------------------------------------------*/
void CheckSpeed(void) {
  if (Car_Speed == 30) {
    AC_Statue = 0;
    Room_Temp = ((Room_Temp * (5 / 4)) + 1);

    Engine_TC_Statue = 1;
    Engine_Temp = ((Engine_Temp * (5 / 4)) + 1);
  }
}
/*-------------------------------------------------------------------*/
void DispalyStates(void) {
  if (Car_Speed == 0) {
    printf("The Engine state is : OFF");
  } else {
    printf("The Engine state is : ON");
  }
  printf("\nThe AC state is : %d", AC_Statue);
  printf("\nThe Speed of the Car is : %d", Car_Speed);
  printf("\nThe Room Temperature is : %d", Room_Temp);
  printf("\nThe Engine Temperature Controller state is : %d", Engine_TC_Statue);
  printf("\nThe Engine Temperature is : %d \n", Engine_Temp);
}
/*-------------------------------------------------------------------*/
/*  Sub_program Section Ends  */