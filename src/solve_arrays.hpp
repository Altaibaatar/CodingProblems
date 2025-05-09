
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/// <summary>
/// HackerRank
/// Left Rotation
/// Array element rotating function with d times to the left
/// </summary>
/// <param name="d">Rotate number</param>
/// <param name="arr">Input array</param>
/// <returns>Rotated array</returns>
vector<int> ArrayRotateLeft(int d, vector<int> arr) {
    vector<int> arr_ret = { 0,0,0,0,0 };
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        if ((i + d) >= size) {
            //printf("%d\r\n", (i + d) - size);
            arr_ret[i] = arr[(i + d) - size];
        }
        else
        {
            //printf("%d\r\n", i + d);
            arr_ret[i] = arr[i + d];
        }
    }
    return arr_ret;

    /// Usage
    //vector<int> arr_input = { 1, 2, 3, 4, 5 };

    //vector<int> result = ArrayRotateLeft(2, arr_input);
    //int size = result.size();
    //printf("Size: %d\r\n", size);
    //for (int i = 0; i < size; ++i) {
    //    printf("%d ", result[i]);
    //}
    //std::cout << "\r\n";
}

/// <summary>
/// HackerRank
/// Sparse Arrays
/// </summary>
/// <param name="stringList"></param>
/// <param name="queries"></param>
/// <returns></returns>
vector<int> ArrayMatchingStrings(vector<string> stringList, vector<string> queries) {
    vector<int> arr_ret;

    // Find duplicate counts from stringList and put it to a dictionary
    unordered_map<string, int> dictOccurences;
    for (int i = 0; i < stringList.size(); ++i) {
        string key = stringList[i];
        // next occurences
        if (dictOccurences.find(key) != dictOccurences.end()) {
            dictOccurences[key]++;
        }
        // first occurence
        else {
            dictOccurences[key] = 1;
        }
    }

    // Search queries occurences from the dict
    for (int i = 0; i < queries.size(); ++i) {
        string key = queries[i];
        if (dictOccurences.find(key) != dictOccurences.end()) {
            arr_ret.push_back(dictOccurences[key]);
        }
        else {
            arr_ret.push_back(0);
        }
    }

    return arr_ret;
}