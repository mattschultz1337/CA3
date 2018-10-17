#include <iostream>
#include <stdlib.h>
#include "LLC.h"
using namespace std;

int main(int argc, char * argv[]) {
  string vals[] = {
    "a",
    "b",
    "c",
    "d",
    "e",
    "f"
  };
  string arr[] = {
    "g",
    "h",
    "i",
    "j",
    "k",
    "l"
  };
  LLC link;
  int size = * ( & vals + 1) - vals;
  for (int i = 0; i < size; i++) {
    link.insert(vals[i]);
  }
  cout << "Testing <<\n";
  cout << link;
  cout << "testing head(3)\n";
  link.head(3);
  cout << "testing join\n";
  LLC twofer;
  size = * ( & arr + 1) - arr;
  for (int x = 0; x < size; x++) {
    twofer.insert(arr[x]);
  }
  link.join(twofer);
  cout<<link;
}
Node * LLC::newNode(std::string d) {
  Node* n = new Node;
  n -> data = d;
  n -> next = NULL;
  return n;
}

LLC::LLC(const LLC & list) {
  if (list.first != NULL) {
    first -> data = list.first -> data;
    Node * curr = first;
    while (curr -> next != NULL) {
      curr = curr -> next;
      insert(curr -> data);
    }
  }

};
LLC & LLC::operator = (const LLC & other) {
  LLC* copy = new LLC(other);
  first = copy -> first;
  last = copy -> last;
  return *this;
}

bool LLC::insert(const std::string & d) {
  Node* ins = newNode(d);
  if (first == NULL) {
    first = ins;
    last = ins;
    ins = NULL;
  } else {
    last -> next = ins;
    last = ins;
  }
  if (last == ins && ins -> data == d && ins -> next == first) {
    return true;
  }
  return false;
}
LLC::~LLC() {
  Node * current = first;
  while (current != NULL) {
    Node * next = current -> next;
    delete current;
    current = next;
  }
  first = NULL;
}
bool LLC::contains(const std::string & d) {
  for (Node * curr = first; curr != NULL; curr = curr -> next) {
    if (curr -> data == d) return true;
  }
  return false;
}
void LLC::remove(const std::string & d) {
  Node * last = NULL;
  for (Node * curr = first; curr != NULL; curr = curr -> next) {
    if (curr -> data == d) {
      if (curr == first) {
        first = curr -> next;
      } else {
        last -> next = curr -> next;
      }
    }
    last = curr;
  }
}
void shuffle() {

}
ostream & operator << (ostream & os, LLC & list) {
  Node * curr;
  os << "[";
  for (curr = list.first; curr -> next != NULL; curr = curr -> next) {
    os << curr -> data << ",";
  }
  os << curr -> data << "]\n";
  return os;
}
void LLC::head(int n) {
  cout << "[";
  Node * curr = first;
  if (curr != NULL) {
    for (int i = 0; i < n - 1 && curr -> next != NULL; i++) {
      cout << curr -> data << ",";
      curr = curr -> next;
    }
    cout << curr -> data;
    cout << "]\n";
  }
}
void LLC::join(LLC other){
  Node* curr = other.first;
  while(curr->next!=NULL){
    insert(curr->data);
  }
  insert(curr->data);
}
