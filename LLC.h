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
        LLC(const LLC &list);
        LLC& operator=(const LLC& other);
        ~LLC();
        bool contains(const std::string &);
        bool insert(const std::string &);
        void remove(const std::string &);
        void shuffle();
        LLC& operator+(const LLC& other);
        void head(int n);
        std::string tail();
        friend std::ostream& operator<<(ostream& os, const LLC& list);
        LLC& operator+=(int n);
        int len();
        void join(LLC other);
};
