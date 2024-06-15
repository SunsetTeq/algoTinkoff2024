#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long D = 379, mod = 1e9 + 7;

// Функции сравнения строк с одним несоответствием
bool checker(const string& s, int start, const string& p) {
    int count_mis = 0;
    for (int i = 0; i < p.length(); ++i) {
        if (s[start + i] != p[i]) {
            ++count_mis;
            if (count_mis > 1) {
                return false;
            }
        }
    }
    return count_mis == 1;
}

// Основная функция поиска подстроки
vector<long long> find_substring(const string& s, const string& p, vector<long long>& hash_s, vector<long long>& hash_p, vector<long long>& d, long long n, long long m) {

    vector<long long> positions;
    // Проходим по всем подстрокам в s, проверяем хэш и условие одного несоответствия
    for (int i = 0; i <= n - m; i++) {
        long long current_hash = (hash_s[i + m] + mod - hash_s[i] * d[m] % mod) % mod;
        if (current_hash == hash_p[m] || checker(s, i, p)) {
            positions.push_back(i + 1); // Сдвиг на 1 для соответствия условию задачи
        }
    }

    return positions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);



    string s, p;
    cin >> p >> s;

    long long n = s.length(), m = p.length();
    vector<long long> hash_p(m + 1, 0), hash_s(n + 1, 0), d(m + 1, 1);

    for (int i = 0; i < m; i++) {
        hash_p[i + 1] = (hash_p[i] * D + p[i]) % mod;
        d[i + 1] = (d[i] * D) % mod;
    }

    for (int i = 0; i < n; i++) {
        hash_s[i + 1] = (hash_s[i] * D + s[i]) % mod;
    }

    vector<long long> positions = find_substring(s, p, hash_s, hash_p, d, n, m);



    // Выводим результат
    cout << positions.size() << "\n";
    for (long long pos : positions) {
        cout << pos << " ";
    }

    return 0;
}