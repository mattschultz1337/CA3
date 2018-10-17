#include <iostream>
#include <stdlib.h>
#include "LLC.h"
using namespace std;

int main(int argc, char *argv[]){
  string arr [] = {"a","b","c","d","e","f"};
  LLC link = new LLC(arr);
  cout<<link;
}
Node* LLC::newNode(std::string d){
  Node *n = new Node;
  n->data = d;
  n->next=NULL;
  return n;
}
LLC::LLC(int *vals[]){
  for(int i=0;i<&vals.length;i++){
    insert(newNode(&vals[i]));
  }
}
LLC::LLC(const LLC &list){
  if(list.first!=NULL){
    first->data=list.first->data;
    Node *curr = first;
    while(curr->next!=NULL){
      curr=curr->next;
      insert(curr->data);
    }
   }

};
LLC& LLC::operator=(const LLC& other){

}

bool LLC::insert(const std::string &d){
   Node *ins = newNode(d);
   if(first=NULL){
      first=ins;
      last=ins;
      ins=NULL;
    } else{
        last->next = ins;
        last=ins;
      }
   if(last==ins && ins->data==d && ins->next==first){
      return true;
   }
   return false;
}
LLC::~LLC(){
  Node* current = first;
  while( current != NULL ) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  first = NULL;
}
bool LLC::contains(const std::string &d){
  for(Node* curr = first;curr!=NULL;curr = curr->next){
    if(curr->data==d) return true;
  }
  return false;
}
void LLC::remove(const std::string &d){
  Node* last = NULL;
  for(Node* curr = first;curr!=NULL;curr = curr->next){
    if(curr->data==d){
      if(curr==first){
        first = curr->next;
      } else{
        last->next = curr->next;
      }
    }
    last = curr;
  }
}
void shuffle(){

}
