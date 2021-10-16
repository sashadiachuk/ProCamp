int enqueue(int data);
int dequeue();
int isFull();
int isEmpty();
int getBack();
int getFront();

#define CAPACITY 100

extern int queue[CAPACITY];
extern unsigned int size;
extern unsigned int back;
extern unsigned int front;