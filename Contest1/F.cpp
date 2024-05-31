# include <iostream>
# include <cmath>
# include <vector>

using namespace std;

int n;
long long inv;
vector<long long>a;

void mergeSort(vector<long long>& a, int left, int right);
void merge(vector<long long>& a, int left, int mid, int right);

int main()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int left = 0, right = n - 1;
    mergeSort(a, left, right);

    cout << inv << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}


void mergeSort(vector<long long>& a, int left, int right)
{
    if (left >= right) return;

    int midle = left + (right - left) / 2;

    mergeSort(a, left, midle);
    mergeSort(a, midle + 1, right);
    merge(a, left, midle, right);

}


void merge(vector<long long>& a, int left, int mid, int right)
{
    int n1 = mid - left + 1; \
        int n2 = right - mid;

    vector<int> left_a(n1), right_a(n2);

    for (int i = 0; i < n1; i++)
        left_a[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        right_a[j] = a[mid + 1 + j];


    int i = 0, j = 0, k = left;


    while (i < n1 && j < n2) {
        if (left_a[i] <= right_a[j]) {
            a[k] = left_a[i];
            i++;
        }
        else {
            a[k] = right_a[j];
            j++;
            inv += (n1 - i);
        }
        k++;
    }


    while (i < n1) {
        a[k] = left_a[i];
        i++;
        k++;
    }


    while (j < n2) {
        a[k] = right_a[j];
        j++;
        k++;
    }
}