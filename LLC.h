#include <iostream>
#include <stdlib.h>
#include <string>
struct Node {
 string data;
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
        LLC(const LLC &list);
        LLC& operator=(const LLC& other);
        ~LLC();
        bool contains(const string &);
        bool insert(const string &);
        void remove(const string &);
        void shuffle();
        LLC& operator+(const LLC& other);
        void head(int n);
        string tail();
        friend ostream& operator<<(ostream& os, const LLC& list);
        LLC& operator+=(int n);
        int len();
        void join(LLC other);
};
