#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *aux = (List *) malloc(sizeof(List)); 
  if(aux == NULL) exit(EXIT_FAILURE); 
  aux->head = NULL; 
  aux->tail = NULL; 
  aux->current = NULL; 
  
  
     return aux;
}

void * firstList(List * list) {

  if(list->head){
    list->current = list->head;
  }
  else return NULL; 
  return(list->head->data); 
  
    return NULL;
}

void * nextList(List * list) {
  if(!list->current)return NULL; //Saber si existe current 
  if(!list->current->next)return NULL; //saber si existe un next dsp del current
  list->current = list->current->next; 
  
  return (list->current->data);
}

void * lastList(List * list) {
  if(!list->tail)return NULL; 
  if(!list->current)return NULL; 
  list->current = list->tail; 
    return (list->current->data); 
}

void * prevList(List * list) {
  if(!list->current)return NULL; 
  if(!list->current->prev)return NULL; 
  list->current = list->current->prev; 
  
  return (list->current->data);
    
}

void pushFront(List * list, void * data) {

  Node *nuevoNodo = createNode(data); 
  nuevoNodo->next = list->head;
  if(list->head){
    list->head->prev = nuevoNodo;
  }
  list->head = nuevoNodo; 
  list->tail = nuevoNodo; 
  nuevoNodo->prev = NULL;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {

  Node *nNodo = createNode(data); 
  if(list->current){
    nNodo->next =list->current->next; 
    nNodo->prev = list->current; 
    list->current->next = nNodo; 
  }
  else{
    list->head= nNodo; 
    list->tail=nNodo; 
    list->current=nNodo; 
  }
  list->tail=nNodo; 
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  //elimina nodo actual 
  //debe apuntar al sgte del actual 

  if(list->current->prev!=NULL){
    list->current->prev->next= list->current->next; 
  }
  else{
    list->head = list->current->next; 
  }
  if(list->current->next !=NULL)
    list->current->next->prev= list->current->prev; 
  if(list->current == list->tail)
    list->tail = list->tail->prev; 
  
  return(list->current->data); 
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}