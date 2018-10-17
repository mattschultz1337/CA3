#ifndef LLC_H
#define LLC_H

#include <iostream>
#include <stdlib.h>
#include <string>
struct Node {
 std::string data;
 Node *next;
};
class LLC {
    private:
      Node *first;
      Node *last;
    public:
        int main(int argc, char *argv[]);
        LLC(){
          first=NULL;
          last=NULL;
        }
        Node* newNode(std::string d);
        LLC(const LLC &list);
        LLC(int *vals[]);
        LLC& operator=(const LLC& other);
        ~LLC();
        bool contains(const std::string &d);
        bool insert(const std::string &d);
        void remove(const std::string &d);
        void shuffle();
        LLC& operator+(const LLC& other);
        void head(int n);
        std::string tail();
        friend std::ostream& operator<<(std::ostream& os, const LLC& list);
        LLC& operator+=(int n);
        int len();
        void join(LLC other);
};
#endif
