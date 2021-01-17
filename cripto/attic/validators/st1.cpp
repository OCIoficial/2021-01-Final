#include "testlib.h"

using namespace std;


int main() {
    registerValidation();

    int unread = inf.readInt(300, 100000000, "LENGTH");
    inf.readEoln();

    while (unread > 0) {
        string word = inf.readToken("[A-Z]+");
        unread -= word.length();
        if (unread > 1) {
            inf.readSpace();
            unread--;
        }
    }
    inf.readEoln();
    inf.readEof();
}
