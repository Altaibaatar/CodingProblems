
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/// <summary>
/// HackerRank
/// Left Rotation
/// Array element rotating function with d times to the left
/// </summary>
/// 
/// Usage
//vector<int> arr_input = { 1, 2, 3, 4, 5 };

//vector<int> result = ArrayRotateLeft(2, arr_input);
//int size = result.size();
//printf("Size: %d\r\n", size);
//for (int i = 0; i < size; ++i) {
//    printf("%d ", result[i]);
//}
//std::cout << "\r\n";
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
}

/// <summary>
/// HackerRank
/// Sparse Arrays
/// </summary>
/// Usage
//    vector<string> stringList = { "abcde", "sdaklfj", "asdjf", "na", "basdn", "sdaklfj", "asdjf", "na", "asdjf", "na", "basdn", "sdaklfj", "asdjf" };
//    vector<string> queries = { "abcde", "sdaklfj", "asdjf", "na", "basdn" };
//
//    vector<int> result = ArrayMatchingStrings(stringList, queries);
//
//    for (int i = 0; i < queries.size(); ++i) {
//        printf("%s: %d\r\n", queries[i].c_str(), result[i]);
//    }
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

/// <summary>
/// HackerRank
/// Array Manipulation
/// </summary>
/// Usage
    
////    int size_n = 4000;
////    vector<vector<int>> queries = {
////        {2250, 2540, 180674}
////      , {2459, 3892, 434122}
////      , {2321, 3289, 363503}
////      , {1975, 2754, 374161}
////      , {3283, 3759, 45954}
////    };
////    int size_n = 5;
////    vector<vector<int>> queries = {
////          {1, 2, 100}
////        , {2, 5, 100}
////        , {3, 4, 100}
////    };
//    int size_n = 10;
//    vector<vector<int>> queries = {
//          {2, 6, 8}
//        , {3, 5, 7}
//        , {1, 8, 1}
//        , {5, 9, 15}
//    };
//    long maxValue = ArrayManipulation(size_n, queries);
//
//    printf("The maxvalue is %ld\r\n", maxValue);
inline long ArrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 2, 0);  // extra space to handle end+1 safely

    for (const auto &q : queries) {
        int a = q[0];
        int b = q[1];
        int k = q[2];
        arr[a] += k;
        arr[b + 1] -= k;
    }

    long maxVal = 0, current = 0;
    for (int i = 1; i <= n; ++i) {
        current += arr[i];
        if (current > maxVal)
            maxVal = current;
    }

    return maxVal;
}

vector<int> DynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> arr(n);      // 2D array of n empty arrays
    vector<int> result;              // Stores answers to type 2 queries
    int lastAnswer = 0;

    for (auto& query : queries) {
        int type = query[0];
        int x = query[1];
        int y = query[2];

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            arr[idx].push_back(y);
        }
        else if (type == 2) {
            int size = arr[idx].size();
            lastAnswer = arr[idx][y % size];
            result.push_back(lastAnswer);
        }
    }

    return result;
}
