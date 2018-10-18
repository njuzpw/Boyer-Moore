#include "bm.h"

boyerMoore::boyerMoore(const string& s) {
    needle = s;
    goodSuffixVec(s, gsv);
    return;
}

void boyerMoore::goodSuffixVec(const string& s, vector<int>& v) {
    size_t np = s.size();
    v.resize(np, -1);

    for (size_t r = np - 1; r > 0; --r) {
        size_t nn = np - r;
        size_t nsub = string::npos;
        size_t gm;

        string sstr = s.substr(r);

        if((nsub = s.rfind(sstr, r - 1)) == string::npos) {
            for (int i = 1; i != np - r; ++i) {
                if (strncmp(s.c_str(), sstr.c_str() + np - r - i, i) == 0) {
                    v[r] = np - 1;
                    continue;
                }
            }
            if (v[r] != -1) {
                continue;
            }
            v[r] = np - 1 - (-1);
        } else {
            v[r] = np - 1 - (nsub + nn - 1);
        }
    }
}

ssize_t boyerMoore::crfind(const string& str, const char c, size_t pos) {
    if (str.size() < pos + 1) {
        // cout << "failed" << endl;
        return -1;
    }
    for (int i = pos; i >= 0; --i) {
        // cout << str[i] << "-----" << c << endl;
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

bool boyerMoore::bmC(const string& haystack) {
    size_t index(0);
    size_t np = needle.size();
    size_t nh = haystack.size();
    size_t i = np - 1;

    for (/*do nothing*/; i != 0; --i) {
        if (needle[i] == haystack[index + i]) {
            continue;
        } else {
            ssize_t bad_pos = crfind(needle, haystack[index + i], i - 1);
            size_t bad_move = i - bad_pos;
            size_t good_move = i + 1 >= np ? 0 : gsv[i + 1];

            index += max(bad_move, good_move);

            if (index + np - 1  > nh) {
                return false;
            }

            i = np;
        }
    }

    if (i == 0) {
        return true;
    }
    return false;
}
