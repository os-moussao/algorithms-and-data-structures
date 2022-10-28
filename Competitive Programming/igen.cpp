#include <testlib.h>
using namespace std;
// g++ -std=c++17 igen.cpp -I testlibPath -o igen
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    println(rnd.next(-100000 + 1, -2));
}