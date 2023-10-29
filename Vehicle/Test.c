#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int proc_ID;
  int proc_order;
  char process;
} PROCESS;
PROCESS processes[10] = {{.proc_ID = 0, .proc_order = 1, .process = '*'},
                         {.proc_ID = 1, .proc_order = 1, .process = '/'},
                         {.proc_ID = 2, .proc_order = 2, .process = '+'},
                         {.proc_ID = 3, .proc_order = 2, .process = '-'},
                         {.proc_ID = 4, .proc_order = 1, .process = '/'},
                         {.proc_ID = 5, .proc_order = 2, .process = '-'}};

int main() {
  int Global_counter_1 = 6;
  printf("Global_Counter_1 = %d\n", Global_counter_1);

  PROCESS local_buffer = {0};
  int local_counter = Global_counter_1;
  for (int i = 0; i < (local_counter - 1); i++) {
    for (int j = 0; j < (local_counter - i - 1); j++) {
      if (processes[j].proc_order > processes[j + 1].proc_order) {
        local_buffer = processes[j + 1];
        processes[j + 1] = processes[j];
        processes[j] = local_buffer;
      }
    }
  }

  for (int i = 0; i < Global_counter_1; i++) {
    printf(".proc_ID = %d, .proc_order = %d, .process = %c\n",
           processes[i].proc_ID, processes[i].proc_order, processes[i].process);
  }
  return 0;
}