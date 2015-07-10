typedef struct {
    int *st1;
    int *st2;
    int top1;
    int top2;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    queue->st1 = (int *)malloc(sizeof(int) * maxSize);
    queue->st2 = (int *)malloc(sizeof(int) * maxSize);
    queue->top1 = 0;
    queue->top2 = 0;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    queue->st1[queue->top1++] = element;
    //queue->top1++;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    if(queue->top2 > 0){
        queue->top2--;
        return ;
    }

    while(queue->top1 > 0){
        queue->st2[queue->top2++] = queue->st1[--queue->top1];
    }

    queue->top2--;
}

/* Get the front element */
int queuePeek(Queue *queue) {
    if(queue->top2 > 0){
        return queue->st2[queue->top2-1];
    }

    while(queue->top1 > 0){
        queue->st2[queue->top2++] = queue->st1[--queue->top1];
    }

    return queue->st2[queue->top2-1];
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    return queue->top1 == 0 && queue->top2 == 0;
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    if(!queue)
        return ;

    free(queue->st1);
    free(queue->st2);
}
