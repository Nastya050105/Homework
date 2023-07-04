#include<cstdio>
#include<string>
#include <iostream>
#include <vector>

using namespace std; 

struct Del {
    int pos;

    char c1;

    char c2;
};

vector<Del>minify(string& s) {
    vector<Del>deleted;
    int last = -1;
    for (int i = 0; i < (int)s.size(); i++){
        if (last == -1) {
            last++;
            s[last] = s[i];
        }
        else if (
            (s[last] == 'a' && s[i] == 'A') ||
            (s[last] == 'A' && s[i] == 'a') ||
            (s[last] == 'b' && s[i] == 'B') ||
            (s[last] == 'B' && s[i] == 'b')
            ) {
            deleted.push_back(Del{ last, s[last],s[i] });
            last--;
        }
        else {
            last++;
            s[last] = s[i];
        }
    }
    s.resize(last + 1);
    return deleted;
}


void getMaxSubstr(const string &x, const string &y, int& xPos, int& yPos, int& len) {
    if (x.empty() || y.empty()) {
        xPos = -1;
        yPos = -1;
        len = 0;
        return;
    }
    xPos = -1;
    yPos = -1;
    len = 0;
    vector<int> maxMatch(x.size());
    for (int ix = 0; ix < (int)x.size(); ix++) {
        int iy = 0;
        if (x[ix] == y[iy]) {
            maxMatch[ix] = 1;
            if (maxMatch[ix] > len) {
                len = maxMatch[ix];
                xPos = ix;
                yPos = iy;
            }
        }
        else {
            maxMatch[ix] = 0;
        }
    }
    for (int iy = 1; iy < (int)y.size(); iy++) {
        for (int ix = (int)x.size() - 1; ix > 0; ix--) {
            if (x[ix] == y[iy]) {
                maxMatch[ix] = maxMatch[ix - 1] + 1;
                if (maxMatch[ix] > len) {
                    len = maxMatch[ix];
                    xPos = ix;
                    yPos = iy;
                }
            }
            else {
                maxMatch[ix] = 0;
            }
        }
        int ix = 0;
        if (x[ix] == y[iy]) {
            maxMatch[ix] = 1;
            if (maxMatch[ix] > len) {
                len = maxMatch[ix];
                xPos = ix;
                yPos = iy;
            }
        }
        else {
            maxMatch[ix] = 0;
        }
    }
}
int main() {
    char buffer[2000 + 1];
    scanf("%2000s", buffer);
    string x(buffer);
    scanf("%2000s", buffer);
    string y(buffer);
    minify(x);
    vector <Del> yDel=minify(y);
    int xPos, yPos,len;
    getMaxSubstr(x, y, xPos, yPos,len);

    for (int iy = yPos + 1; iy < (int)y.size(); iy++) {
        if (y[iy] == 'a') {
            x.insert(xPos + iy - yPos, "aA");
        }
        else if (y[iy] == 'A') {
            x.insert(xPos + iy - yPos, "Aa");
        }
        else if (y[iy] == 'b') {
            x.insert(xPos + iy - yPos, "bB");
        }
        else if (y[iy] == 'B') {
            x.insert(xPos + iy - yPos, "Bb");
        }
        else {
            throw 1;
        }

    }for (int iy = yPos - len; iy >= 0; iy--) {
        if (y[iy] == 'a') {
            x.insert(xPos -len+1+( iy - (yPos-len)), "Aa");
        }
        if (y[iy] == 'a') {
            x.insert(xPos - len + 1 + (iy - (yPos - len)), "Aa");
        }else if (y[iy] == 'A') {
            x.insert(xPos - len + 1 + (iy - (yPos - len)), "aA");
        }else if (y[iy] == 'b') {
            x.insert(xPos - len + 1 + (iy - (yPos - len)), "Bb");
        }else if (y[iy] == 'B') {
            x.insert(xPos - len + 1 + (iy - (yPos - len)), "bB");
        }
        else {
            throw 1;
        }

    }

    int yStart = xPos + 1 - len + yPos + 1 - len;
    for (int i = (int)yDel.size() - 1; i >= 0; i--) {
        x.insert(yStart + yDel[i].pos, string() + yDel[i].c1 + yDel[i].c2);
    }
    printf("%s\n", x.c_str());
}


 
