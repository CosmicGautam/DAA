#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Jobs {
   char id; // Jobs Id
   int dead; // Deadline of Jobs
   int profit; // Profit if Jobs is over before or on deadline
} Jobs;
int compare(const void* a, const void* b){
   Jobs* temp1 = (Jobs*)a;
   Jobs* temp2 = (Jobs*)b;
   return (temp2->profit - temp1->profit);
}
int min(int num1, int num2){
   return (num1 > num2) ? num2 : num1;
}
int main(){
   Jobs arr[] = { 
      { 'a', 2, 100 },
      { 'b', 2, 20 },
      { 'c', 1, 40 },
      { 'd', 3, 35 },
      { 'e', 1, 25 }
   };
   int n = sizeof(arr) / sizeof(arr[0]);
   printf("Following is maximum profit sequence of Jobs: \n");
   qsort(arr, n, sizeof(Jobs), compare);
   int result[n]; // To store result sequence of Jobs
   bool slot[n];
   for (int i = 0; i < n; i++)
      slot[i] = false;
   for (int i = 0; i < n; i++) {
      for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
         if (slot[j] == false) {
            result[j] = i;
            slot[j] = true;
            break;
         }
      }
   }
   for (int i = 0; i < n; i++)
      if (slot[i])
         printf("%c ", arr[result[i]].id);
    printf("\nName:Cosmic Gautam\tRoll no.:07");
   return 0;
}
