/***
 * @Author: RanZhuJun
 * @Date: 2023-06-22 21:35:40
 * @LastEditTime: 2023-06-22 21:35:46
 * @Description: leetcode 242 有效的字母异位词
 * @FilePath: \LeetcodeCpp\Hashmap\1.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char,int> map;
    for(char ch : s) {
        map[ch]++;
    }
    for(char ch : t) {
        map[ch]--;
    }
    for(auto it : map) {
        if(it.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";
    bool res = isAnagram(s, t);
    cout << res << endl;
    return 0;
}
