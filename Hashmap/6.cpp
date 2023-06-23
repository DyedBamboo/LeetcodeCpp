/***
 * @Author: RanZhuJun
 * @Date: 2023-06-23 11:33:50
 * @LastEditTime: 2023-06-23 11:33:56
 * @Description: Leetcode 383 赎金信
 * @FilePath: \LeetcodeCpp\Hashmap\6.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransom, string magazine) {
    unordered_map<char, int> map;
    for (char ch : magazine) {
        map[ch]++;
    }
    for (char ch : ransom) {
        map[ch]--;
        if (map[ch] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string ransom = "aa";
    string magazine = "ab";
    bool res = canConstruct(ransom, magazine);
    cout << res << endl;
    return 0;
}
