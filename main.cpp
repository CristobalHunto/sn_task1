#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
#include <algorithm> // для min и max

using namespace std;

int main() {
    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0) {
        cout << "Размер массива должен быть положительным." << endl;
        return 1;
    }

    vector<double> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    //Используем алгоритмы из <algorithm> для нахождения min_element и max_element.
    auto min_it = min_element(arr.begin(), arr.end());
    auto max_it = max_element(arr.begin(), arr.end());


    if (min_it == arr.end() || max_it == arr.end()) {
        cout << "Массив пуст." << endl;
        return 1;
    }

    double sum = 0; // используем long double для предотвращения переполнения с плавающей точкой
    int minIndex = distance(arr.begin(), min_it);
    int maxIndex = distance(arr.begin(), max_it);
    int start = min(minIndex, maxIndex);
    int end = max(minIndex, maxIndex);

    

    for (int i = start + 1; i < end; ++i) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }

    cout << "Сумма отрицательных элементов между максимальным и минимальным: " << sum << endl;

    return 0;
}
