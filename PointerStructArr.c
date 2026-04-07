#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct arr {
    char name[30];
    int studentID;
    int grade;
};


int main() {

    srand(time(NULL));

    int NUMBER;

    printf("학생 수를 입력하세요 ");
    scanf("%d", &NUMBER);

    struct arr* arr = (struct arr*)malloc(sizeof(struct arr) * NUMBER);

    ///////////////////////////////////////학생 정보 넣기/////////////////////////////////////////////
    FILE* fp;

    fp = fopen("C:\\Users\\kfc03\\Downloads\\name_list.txt", "r"); //파일 위치

    if (fp == NULL) {

        printf("Fail to open\n");
        free(arr);

        return 0;

    }

    char file_buff[50];
    int x = 0;

    while (fgets(file_buff, sizeof(file_buff), fp) != NULL && x < NUMBER) {

        char* p = file_buff;

        for (int i = 0; i < sizeof(file_buff); i++) {
            if (*(p + i) == '\n')
                *(p + i) = '\0';
        }

        strcpy((*(arr+x)).name, file_buff);
        (*(arr + x)).grade = (rand() % 100) + 1;
        (*(arr + x)).studentID = x + 1;

        memset(file_buff, 0, sizeof(file_buff));

        x++;
    }

    fclose(fp);
    ///////////////////////////////////////학생 정보 넣기/////////////////////////////////////////////

    int average = 0;
    int max, min;

    max = 0;
    min = max;

    for (int i = 0; i < NUMBER; i++) {
        average += (*(arr + i)).grade;

        if ((*(arr+max)).grade < (*(arr + i)).grade)
            max = i;
        else if ((*(arr + min)).grade > (*(arr + i)).grade)
            min = i;

    }

    for (int i = 0; i < NUMBER; i++)
        printf("학생 이름: %s, 학번: %d, 학점: %d\n", (*(arr + i)).name, (*(arr + i)).studentID, (*(arr + i)).grade);

    printf("평균 점수: %d\n", average / NUMBER);
    printf("최고점 학생: %s,학번: %d, 학점: %d\n", (*(arr + max)).name, (*(arr + max)).studentID, (*(arr + max)).grade);
    printf("최저점 학생: %s,학번: %d, 학점: %d\n", (*(arr + min)).name, (*(arr + min)).studentID, (*(arr + min)).grade);


    free(arr);

    return 0;
}