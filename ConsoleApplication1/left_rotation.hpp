
#include <vector>
#include <iostream>

using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) {
    vector<int> arr_ret = { 0,0,0,0,0 };
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        /*if ((i + d) > size) {
            arr_ret[i] = (i + d) - size;
        }
        arr_ret[i] = arr[i+d];*/
        if ((i + d) >= size) {
            printf("%d\r\n", (i + d) - size);
            arr_ret[i] = arr[(i + d) - size];
        }
        else
        {
            printf("%d\r\n", i + d);
            arr_ret[i] = arr[i + d];
        }
    }
    return arr_ret;
}