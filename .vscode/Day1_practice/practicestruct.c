#include <stdio.h>

typedef struct {
    char model[20]; // 모델명
    int temp;       // 온도
} Boiler;

void heat_up(Boiler *b) {
    b->temp +=1;
    printf("현재 온도: %d도 (난방 중...)\n",b->temp);
}

int main(void) {
    Boiler b = {"Navien", 20};
    heat_up(&b);
    heat_up(&b);

    return 0;
}
