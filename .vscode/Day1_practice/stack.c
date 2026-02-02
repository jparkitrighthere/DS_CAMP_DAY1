// #include <stdio.h>

// //stack push
// void push (int x){
//     if(full_check()){
//         printf("Stack Overflow\n");
//         return;
//     }

//     stack[top] = x;
//     top++;
// }

// // stack pop
// int pop(){
//     if(empty_check()){
//         printf("Stack Underflow\n");
//         return -1;
//     }
// }

// // stack empty check
// bool empty_check(){
//     if (top==0){
//         return true;
//     }else {
//         return false;
//     }
// }

// //stack full check

// //queue insert
// void insert(int x){
//     if (queue_full()){
//         printf("Queue Overflow\n");
//         return;
//     }

//     queue[rear] = x;
//     rear++;
// }

// //queue full_check
// bool queue_full(){
//     if (rear == Q_SIZE)
//         return true;
//     else 
//         return false;
// }

// //queue delete
// int delete(){
//     int value;

//     if (queue_empty()){
//         printf("Queue Underflow\n");
//         return -1;
//     }

//     value = queue[front];
//     front++;
//     return value;
// }

// //queue empty_check
// bool queue_empty(){
//     if(front == rear)
//         return true;
//     else   
//         return false;
// }