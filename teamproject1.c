#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int score;
} Student;

void printMenu();
void find_mvp(Student *s, int studentNum);
double get_average(Student *s, int studentNum);
void viewAllGrade (Student *s, int studentNum);
void check(Student *s, int studentNum);

int main(){
    Student *s;
    int studentNum = 0; 
    double studentAvg = 0.0;


    printf("전체 학생 수를 입력하세요 : ");
    scanf("%d", &studentNum);
    

    s = (Student *)malloc(sizeof(Student) * studentNum);

    if(s == NULL){
        printf("남은 공간이 없습니다.\n");
        return 1;
    }
    
    for(int i=0; i<studentNum; i++){
        printf("%d번째 학생의 이름을 입력하세요 : ", (i+1));
        scanf("%s",s[i].name);

        printf("%d번째 학생의 점수를 입력하세요 : ", (i+1));
        scanf("%d", &s[i].score); 

        if(s[i].score > 100 || s[i].score < 0){
            printf("잘못된 값이 입력되었습니다. 다시 입력하세요\n");
            i--;
        }
    }


    while (1) {
        int menu = 0;
        printMenu();        
        scanf("%d", &menu); 

        if (menu == 0) {
            printf("프로그램을 종료합니다.\n");
            break; // 반복문 탈출 -> 프로그램 종료
        }

        switch (menu) {
            case 1: 
                viewAllGrade (s,studentNum);
                break;
            case 2: 
                check(s, studentNum);
                break; 
            case 3: 
                find_mvp(s, studentNum);
                break; 
            default: 
                printf("잘못된 메뉴입니다. 다시 선택해주세요.\n");
        }
    }

    free(s);
    s = NULL;

    return 0;
}

void printMenu() {
    printf("\n------------------------------------------------------------\n");
    printf("[ 1:전체 학생의 기록 2:미달 학생 3.우수 학생 0:종료 ]\n");
    printf("------------------------------------------------------------\n");
    printf(" > 메뉴를 선택하세요 > ");
}

void find_mvp(Student *s, int studentNum) {
    int temp = 0;
    char firstName[20];
    
    for (int i=0;i<studentNum;i++){
        if(s[i].score>temp){
            temp = s[i].score;
            strcpy(firstName, s[i].name);
        }
    }
    printf("\n1등 학생은 %s입니다.\n",firstName);
}


double get_average(Student *s,int studentNum){
    int sum = 0;
    double avg = 0.0;

    for(int i = 0; i < studentNum; i++){
        sum += s[i].score;
    }
    avg = (double)sum / studentNum;
    return avg;
}

void viewAllGrade (Student *s, int studentNum){
    for(int i=0; i<studentNum; i++){
        printf("\n%s 학생의 점수는 : %d\n", s[i].name, s[i].score);
    }
}

void check(Student *s, int studentNum){
    double avg = 0.0;

    avg = get_average(s,studentNum);

    for(int i = 0; i < studentNum; i++){
        if(avg > s[i].score){

            printf("\n평균은 %.1f입니다\n",avg);
            printf("\n%s 학생은 평균보다 낮습니다. 추가학습이 필요합니다.(%d)\n",s[i].name, s[i].score);
        }
    }
}