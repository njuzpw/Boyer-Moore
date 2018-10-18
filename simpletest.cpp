#include <iostream>
#include "bm.h"

using namespace std;

int main(int argc, char** argv) {
    string needle = argv[1];
    boyerMoore bm(needle);

    ifstream infile; 
    infile.open(argv[2]);   //将文件流对象与文件连接起来 

    string s;
    while(getline(infile,s))
    {
        if(bm.bmC(s)) {
            cout << s << endl;
        }
    }
    infile.close();
}