#include <iostream>
#include <vector>
// #include "extra.h"
#include "extra.cpp"

using namespace std;

int main() {
    vector<int> a = {1,2,3,4,5};
    for (int d : a) {
        cout << d << endl;
    }
    return 0;
}
