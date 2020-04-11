class Solution {
public:
    /*
       # '#' means backspace operation
      "ab#c" --> ac
      "ad#c" --> ac 
       
    */
    bool backspaceCompare(string S, string T) {
        if (S.size() == 0 || T.size() == 0) return false;
        int ii = -1;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] != '#') {
                S[++ii] = S[i]; // in-place copy
            } else {
                if (ii > -1) ii -= 1;
            }
        } 
        int jj = -1;
        for (int j = 0; j < T.size(); j++) {
            if (T[j] != '#') {
                T[++jj] = T[j]; // in-place copy
            } else {
                if (jj > -1) jj -= 1;
            }
        } 
        if (jj != ii) return false;
            
        for (int i = 0; i <= ii; i++) {
            if (S[i] != T[i]) return false;
        }
        return true;
    }
};
