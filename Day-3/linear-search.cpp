#include <iostream>
using namespace std;

int main()
{
    cout << time(0);
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == 3)
        {
            cout << endl
                 << "3 is present at" << i << endl;
        }
    }
}