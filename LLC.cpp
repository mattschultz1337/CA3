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
  LLC link = *(new LLC());
  int size = * ( & vals + 1) - vals;
  for (int i = 0; i < size; i++) {
    link.insert(vals[i]);
  }
  cout << "Testing <<\n";
  cout << link;
  cout<<"testing copy constructor\n";
  LLC lilink = *(new LLC(link));
  cout<<lilink;
  cout << "testing head(3)\n";
  link.head(3);
  cout << "testing remove\n";
  link.remove("c");
  cout<<link;
  cout << "testing len\n";
  cout<< link.len() << endl;

  LLC twofer = *(new LLC());
  size = * ( & arr + 1) - arr;
  for (int x = 0; x < size; x++) {
     twofer.insert(arr[x]);
  }
  cout << "testing join\n";
  link.join(twofer);
  cout<<link;
  cout<<"testing +\n";
  twofer = link + lilink;
  cout<<twofer;
  cout<<"testing +=\n";
  lilink+=2;
  cout<<lilink;


}
Node * LLC::newNode(string d) {
  Node* n = new Node;
  n -> data = d;
  n -> next = NULL;
  return n;
}

LLC::LLC(const LLC & list) {
  if (list.first != NULL) {
    first= newNode(list.first -> data);
    last=first;
    Node * curr = list.first->next;
    while (curr!= NULL) {
      insert(curr -> data);
      curr = curr -> next;

    }
  }

}
LLC & LLC::operator = (const LLC & other) {
  LLC* copy = new LLC(other);
  first = copy -> first;
  last = copy -> last;
  return *this;
}

bool LLC::insert(const string & d) {
  Node* ins = newNode(d);
  if (first == NULL) {
    first = ins;
    last = ins;
  } else {
    last -> next = ins;
    last = ins;
  }
  return true;
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
void LLC::join(const LLC &other){
  if(other.first!=NULL){
    Node* curr = other.first;
    while(curr!=NULL){
      insert(curr->data);
      curr = curr->next;
    }

  }

}
LLC LLC::operator+(const LLC& other){
  LLC retLLC = *(new LLC(*this));
  if(other.first!=NULL){
    Node* curr = other.first;
    while(curr!=NULL){
      retLLC.insert(curr->data);
      curr = curr->next;
    }
  }
    return retLLC;
}
int LLC::len(){
  Node* curr = first;
  int retval = 0;
  while(curr!=NULL){
    retval++;
    curr = curr->next;
  }
  return retval;
}
LLC LLC::operator+=(int n){
  LLC retLLC = *(new LLC(*this));
  for(int i=0;i<n;i++){
    last->next = first;
    last = first;
    first = first->next;
    last->next = NULL;
  }
  return retLLC;
}
