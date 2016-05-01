typedef struct {
    int *front_st;
    int *back_st;
    int front_top;
    int back_top;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    queue->front_st = malloc(sizeof(int) * maxSize);
    queue->back_st = malloc(sizeof(int) * maxSize);
    queue->front_top = -1;
    queue->back_top = -1;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    queue->back_st[++queue->back_top] = element;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    if(queue->front_top == -1)
        while(queue->back_top > -1)
            queue->front_st[++queue->front_top] = queue->back_st[queue->back_top--];

    return queue->front_st[queue->front_top--];
}

/* Get the front element */
int queuePeek(Queue *queue) {
    if(queue->front_top == -1)
        while(queue->back_top > -1)
            queue->front_st[++queue->front_top] = queue->back_st[queue->back_top--];

    return queue->front_st[queue->front_top];
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    return queue->front_top == -1 && queue->back_top == -1;
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    free(queue->front_st);
    free(queue->back_st);
}
