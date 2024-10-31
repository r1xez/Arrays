#include <iostream> 

using namespace std;

int main()

{

    int n;

    cout << "Enter a number: ";

    cin >> n;

    int arr[3] = { n, n * 2, n * 4 };

    cout << "The array is: ";

    for (int i = 0; i < 3; i++)

        cout << arr[i] << " ";

    return 0;

}
