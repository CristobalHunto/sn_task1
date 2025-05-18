#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm> // для min и max

using namespace std;

template <typename Type>
Type min_max_sum(vector<Type> arr)
{
    // Используем алгоритмы из <algorithm> для нахождения min_element и max_element.
    auto min_it = min_element(arr.begin(), arr.end());
    auto max_it = max_element(arr.begin(), arr.end());

    if (min_it == arr.end() || max_it == arr.end())
        throw "Vecrot is empty!";
        
    if (min_it == max_it)
        return 0;

    Type sum = 0;

    if (min_it < max_it)
        sum = std::accumulate(min_it + 1, max_it, Type(0));
    else
        sum = std::accumulate(max_it + 1, min_it, Type(0));


    return sum;
}

int main()
{
    int n;
    vector<double> arr;

    // test
    if (min_max_sum(vector<double>({0., -2., -1., -1., 3., 8.})) != 1.)
    {
        cout << "Test double is invalid." << endl;
        return 1;
    }

    if (min_max_sum(vector<int>({0, -2, -1, -1, -3, -1})) != -4)
    {
        cout << "Test double is invalid." << endl;
        return 1;
    }

    if (min_max_sum(vector<int>({-9, -8, -7, -6, -9})) != -15)
    {
        cout << "Test int is invalid." << endl;
        return 1;
    }

        if (min_max_sum(vector<int>({-1})) != -0)
    {
        cout << "Test int is invalid." << endl;
        return 1;
    }

    cout << "Input vector size: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error size." << endl;
        return 1;
    }

    arr.resize(n);
    cout << "Input elepents of vector: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    double sum;
    try
    {
        sum = min_max_sum(arr);
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
        return 1;
    }

    cout << "Sum = : " << sum << endl;

    return 0;
}
