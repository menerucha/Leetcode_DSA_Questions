<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("%s", isSorted(arr, n) ? "True" : "False");

    return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("%s", isSorted(arr, n) ? "True" : "False");

    return 0;
}
>>>>>>> 6c811e6a51d2cf42f27eaaea6ddf4a8e2f5de596
