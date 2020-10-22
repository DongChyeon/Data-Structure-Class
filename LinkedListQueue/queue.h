#include <stdbool.h>

typedef int Element;
typedef struct list_node* list_pointer;
typedef struct head_pointer* LinkedList;
typedef LinkedList Queue;
typedef list_pointer Node;
typedef struct list_node {
    Element value;
    list_pointer link;
} list_node;
typedef struct head_pointer {
    list_pointer front;
    list_pointer rear;
} head_pointer;

bool isEmpty(Queue queue);
void printQueueItems(Queue queue);
Queue makeQueue();
void enqueue(Queue queue, Element elem);
Element dequeue(Queue queue);
void makeQueueEmpty(Queue queue);
void deleteQueue(Queue queue);