


#include <iostream>
using namespace std;

#define BIG_DATA
#ifdef BIG_DATA

template <typename Type>
auto min_max_sum(Type arr)
{
    if (arr.empty())
        throw "Vector is empty!";

    using type_val =  typename Type::value_type;

    type_val max_val = *arr.begin();
    type_val min_val = max_val;
    type_val sum = type_val(0), acum = type_val(0);
    size_t max_pos = 0, min_pos = 0, pos = 0;

    for(auto a : arr)
    {
        if (a > max_val)
        {
            if(max_pos < min_pos)
                sum = acum - sum - min_val;
            else
                sum = acum;
            acum = sum;
            max_pos = pos;
            max_val = a;
        }
        if (a < min_val)
        {
            if(min_pos < max_pos)
                sum = acum - sum - max_val;
            else
                sum = acum;
            acum = sum;
            min_pos = pos;
            min_val = a;
        }

        if (pos > 0)
            acum += a;
        pos++;

    }

    return sum;
}

#else
#include <vector>
#include <numeric>
#include <algorithm> // для min и max

template <typename Type>
Type min_max_sum(vector<Type> arr)
{
    // Используем алгоритмы из <algorithm> для нахождения min_element и max_element.
    auto min_it = min_element(arr.begin(), arr.end());
    auto max_it = max_element(arr.begin(), arr.end());

    if (min_it == arr.end() || max_it == arr.end())
        throw "Vector is empty!";
        
    if (min_it == max_it)
        return 0;

    Type sum = 0;

    if (min_it < max_it)
        sum = std::accumulate(min_it + 1, max_it, Type(0));
    else
        sum = std::accumulate(max_it + 1, min_it, Type(0));


    return sum;
}

#endif

#include <vector>
#include <list>


int main()
{
    int n;
    vector<double> arr;

    // test
    if (min_max_sum(vector<double>({0., -2., -1., -1., 3., 8.})) != 1.)
    {
        cout << "Test1 double is invalid." << endl;
        return 1;
    }

    if (min_max_sum(vector<int>({0, -2, -1, -1, -3, -1, 7})) != -1)
    {
        cout << "Test2 double is invalid." << endl;
        return 1;
    }

    if (min_max_sum(vector<int>({-9, -8, -7, -6, -9})) != -15)
    {
        cout << "Test3 int is invalid." << endl;
        return 1;
    }

    if (min_max_sum(vector<int>({-1})) != -0)
    {
        cout << "Test4 int is invalid." << endl;
        return 1;
    }

    if (min_max_sum(list<int>({-1, -2, 5, 6, 8})) != 11)
    {
        cout << "Test5 int is invalid." << endl;
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
