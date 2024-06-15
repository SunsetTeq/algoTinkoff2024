# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int damerau_levenshtein_distance(const string& s1, const string& s2) {
    int lenstr1 = s1.size();
    int lenstr2 = s2.size();
    vector<vector<int>> d(lenstr1 + 1, vector<int>(lenstr2 + 1));

    for (int i = 0; i <= lenstr1; ++i)
        d[i][0] = i;
    for (int j = 0; j <= lenstr2; ++j)
        d[0][j] = j;

    for (int i = 1; i <= lenstr1; ++i) {
        for (int j = 1; j <= lenstr2; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min({
                d[i - 1][j] + 1,              // deletion
                d[i][j - 1] + 1,              // insertion
                d[i - 1][j - 1] + cost        // substitution
                });
            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                d[i][j] = min(d[i][j], d[i - 2][j - 2] + 1); // transposition
            }
        }
    }
    return d[lenstr1][lenstr2];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << damerau_levenshtein_distance(s1, s2);
}