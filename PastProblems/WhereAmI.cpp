#include <bits/stdc++.h>
using namespace std;

bool allDiff(string str, int num){
    bool val = true;
    for(int i = 0; i < str.length()-num+1; i++){
        string temp = str.substr(i, num);
        int count = 0;
        for(int j = 0; j < str.length()-num+1; j++){
            if(temp==str.substr(j,num)){
                count++;
            }
        }
        if (count > 1){
            val = false;

        }
    }
    return val;
}

int main() {
    freopen ("whereami.in","r",stdin);
    freopen ("whereami.out","w",stdout);
    int n;
    string str;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++){
        if(allDiff(str, i)){
            cout <<i;
            break;
        }
    }

    
}
