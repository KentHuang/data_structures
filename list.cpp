#include <iostream>

using std::cout;
using std::endl;

struct Node {
  void* data;
  Node* next;
};

struct List {
  Node* head;
  Node* tail;
};

Node* init(void* data, Node* next) {
  Node* n = new Node();
  if (n != NULL) {
    n->data = data;
    n->next = next;
  }
  return n;
};

List* init(Node* node) {
  List* list = new List();
  if (list != NULL) {
    list->head = node;
    list->tail = node;
  }
  return list;
};

// append to tail
int append(List* list, Node* node) {
  if (list == NULL || node == NULL) {
    return -1;
  } else {
    (list->tail)->next = node;
    list->tail = node;
    return 0;
  }
};

// remove from head
int remove(List* list, void* data) {
  if (list == NULL) {
    return -1;
  } else {
     data = (list->head)->data;
     Node* elem = list->head;
     list->head = (list->head)->next;
     elem->next = NULL;
     return 0;
  } 
};

void printList(List* list) {
  Node* node = list->head;
  while (node != NULL) {
    cout << *(int *)(node->data) << endl;
    node = node->next;
  }  
};

int main() {
  // test with ints
  int* five = new int;
  *five = 5;
  int* sixsix = new int;
  *sixsix = 66;
  Node* a = init(five, NULL);
  List* l = init(a);
  Node* b = init(sixsix, NULL);
  append(l, b);
  printList(l);
  int* popped;
  remove(l, popped);
  printList(l);
  return 0;
}
