#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

#define STUDENT 10 // 학생 수

typedef struct Student
{
    char num[10]; // 학번 
    char name[20];
    int java;
    int c;
    int HTML;
    int total;
    float avg;
    int rank;
} Student;

int main()
{
   FILE *fp;
   char str[100];
   char *ptr;
   char token[10][20];
   Student student[STUDENT];
   
      fp = fopen("src1.txt", "r");                  // 파일을 일기 모드로 엽니다...........

   int i = 0;

   while (1)                                  // 다 처리할 때까지 실행하자, 끝내는 것은 반복문 안에서 처리할 것이다
   {
     fgets(str, sizeof(str), fp);          // 파일로부터 한줄을 읽는 것입니다. 각 줄의 맨 뒤에는 CR/LF 글자가 있는데 여기까지 읽어서 str에 저장함 
     if (str[0] == 0x00)                   // 읽혀 온 것이 없으면 끝냄
     {
       break;
     }
     printf("파일에서 읽은 것 ---> %s\n", str);   // 파일에서 읽어 온 것을 출력해 봅니다.

     ptr = strtok(str, ",");               // 파일에서 읽은 것을 보면 학번, 성명, 3과목 성적이 콤마로 구분되어 있는 데 이를 쪼갭니다.
     if (ptr != 0x00)                      // 쪼개낸 것 중 첫 번째 strtok을 사용하려고 있는 지 확인하는 것임.
     {
       strcpy(student[i].num, ptr);
       ptr = strtok(0x00, ",");         // 쪼개낸 문자열 다음부터 구분자로 또 찾기
       strcpy(student[i].name, ptr);
       ptr = strtok(0x00, ",");         // 쪼개낸 문자열 다음부터 구분자 또 찾기
       student[i].java = atoi(ptr);
       ptr = strtok(0x00, ",");         // 쪼개낸 문자열 다음부터 구분자 또 찾기
       student[i].c = atoi(ptr);
       ptr = strtok(0x00, ",");         // 쪼개낸 문자열 다음부터 구분자 또 찾기
       student[i].HTML = atoi(ptr);
       student[i].total = student[i].java + student[i].c + student[i].HTML;
       student[i].avg = student[i].total / 3.0;

     }
      printf("쪼개서 구조체에 저장한 것 ===>  %s, %s, %d, %d, %d, %d, %3.1f \n", student[i].num, student[i].name, student[i].java, student[i].c, student[i].HTML, student[i].total, student[i].avg);
     printf("--------------------------------- \n\n");
     i++;
     str[0] = 0x00;                        // 방금 읽은 것을 무효화하고 또 다음 줄을 읽을 채비를 하는 동작임
   }
   fclose(fp);  // 파일을 다 읽으면 닫습니다............

   fp = fopen("out.txt", "w");              // 파일을 쓰기 모드로 엽니다...........
   char buff[100];

   for (i = 0; i < 3; i++)
   {
      sprintf(buff, "%s, %s, %d, %d, %d, %d, %3.1f\n", student[i].num, student[i].name, student[i].java, student[i].c, student[i].HTML, student[i].total, student[i].avg);
      fputs(buff, fp);
   }

   fclose(fp);  // 파일을 다 쓰면 닫습니다............
}