#include <iostream>
#include <vector>
#include <climits>
<<<<<<< HEAD
#include <algorithm>
using namespace std;

//  Bubble Sort 
=======
using namespace std;

//  Bubble Sort
>>>>>>> 53743b1 (updating code)
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j]     = a[j+1];
                a[j+1]   = temp;
            }
        }
    }
}

<<<<<<< HEAD
// Sorting 
=======
// Sorting
>>>>>>> 53743b1 (updating code)
long long maxProductSorting(vector<int> a) {
    bubbleSort(a);
    int n = a.size();
    long long product1 = 1LL * a[n-1] * a[n-2] * a[n-3];
    long long product2 = 1LL * a[0]   * a[1]   * a[n-1];
    return max(product1, product2);
}

<<<<<<< HEAD
//  Iterative 
=======
//  Iterative
>>>>>>> 53743b1 (updating code)
long long maxProductIterative(vector<int>& a) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int x : a) {
        if (x > max1) { max3 = max2; max2 = max1; max1 = x; }
        else if (x > max2) { max3 = max2; max2 = x; }
        else if (x > max3) { max3 = x; }
        if (x < min1) { min2 = min1; min1 = x; }
        else if (x < min2) { min2 = x; }
    }
    long long p1 = 1LL * max1 * max2 * max3;
    long long p2 = 1LL * min1 * min2 * max1;
    return max(p1, p2);
}

<<<<<<< HEAD
// Recursive 
=======
// Recursive
>>>>>>> 53743b1 (updating code)
long long maxProductRecursive(vector<int>& a, int i, int count, long long product) {
    if (count == 3) return product;
    if (i == (int)a.size()) return LLONG_MIN;
    long long include = maxProductRecursive(a, i+1, count+1, product * a[i]);
    long long exclude = maxProductRecursive(a, i+1, count, product);
    return max(include, exclude);
}

int main() {
    vector<int> a = {2, 3, 4};
    vector<int> b = {6, 7, 8, 10};
    vector<int> c = {-10, -10, 5, 2};

    cout << "a {2,3,4}:" << endl;
    cout << "  Sorting:   " << maxProductSorting(a)            << endl;
    cout << "  Iterative: " << maxProductIterative(a)          << endl;
    cout << "  Recursive: " << maxProductRecursive(a, 0, 0, 1) << endl;
<<<<<<< HEAD
    
=======
>>>>>>> 53743b1 (updating code)




<<<<<<< HEAD
=======

>>>>>>> 53743b1 (updating code)
    cout << "b {6,7,8,10}:" << endl;
    cout << "  Sorting:   " << maxProductSorting(b)            << endl;
    cout << "  Iterative: " << maxProductIterative(b)          << endl;
    cout << "  Recursive: " << maxProductRecursive(b, 0, 0, 1) << endl;
<<<<<<< HEAD
   
=======

>>>>>>> 53743b1 (updating code)





    cout << "c {-10,-10,5,2}:" << endl;
    cout << "  Sorting:   " << maxProductSorting(c)            << endl;
    cout << "  Iterative: " << maxProductIterative(c)          << endl;
    cout << "  Recursive: " << maxProductRecursive(c, 0, 0, 1) << endl;

    return 0;
}


