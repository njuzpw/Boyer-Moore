#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class boyerMoore {
    private:
        string needle;
        vector<int> gsv;

        void goodSuffixVec(const string& s, vector<int> &v);

        ssize_t crfind(const string& str, const char c, size_t pos);

    public:
        boyerMoore(const string& needle);

        bool bmC(const string& haystack);
};