//선형큐 

#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct QueueType{
    element data[MAX_QUEUE_SIZE];
    int rear, front;
} QueueType;

void error(char * message){
    fprintf(stderr, "%s\n", message);
}

void init(QueueType *q){
    q->rear = q->front = -1;
}

int is_empty(QueueType *q){
    return q->rear == q->front;
}

int is_full(QueueType *q){
    return q->rear == MAX_QUEUE_SIZE-1;
}

void enqueue(QueueType *q, element item){
    if(is_full(q)){
        error("큐가 포화상태입니다");
    }
    q->data[++(q->rear)] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        error;
    }
    return q->data[++q->front];
}

element peek(QueueType *q){
    if(is_empty(q)){
        error;
    }
    return q->data[q->front];
}


int main(){
    return 0;
}
// 기본 사이즈가 정해져있다(동적할당 교재에서는 하지않는다.) 무한으로 사용할 순 있어도 (크기에맞게)
// 선형큐와 원형큐 원형큐에서 확장된 덱(double ended queue)
// 선형큐의 adt
/*
선형큐
create
init
in_empty
is_full
enqueue
dequeue
peek

원형큐
craete
init
is_empty
is_full
enqueue
dequeue
peek
선형큐와는 구현방식에 차이가 있음 동작방식이나

덱
원형큐와 같고, 
add_front, add_rear
get_front  get_reawr
delete front, delete rear

원형큐의 요소 최대 개수는 n-1개이다
그리고 원형큐의 front가 가르키고 있는 부분은 공백임.

*/