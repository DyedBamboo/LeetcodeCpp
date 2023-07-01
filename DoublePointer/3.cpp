/***
 * @Author: RanZhuJun
 * @Date: 2023-07-01 15:58:31
 * @LastEditTime: 2023-07-01 15:58:39
 * @Description: 剑指Offer 05.替换空格
 * @FilePath: \LeetcodeCpp\DoublePointer\3.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <string>

using namespace std;

string replaceSpace(string s) {
    int count = 0;  // 统计空格的个数
    int sOldSize = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            count++;
        }
    }
    // 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
    s.resize(s.size() + count * 2);
    int sNewSize = s.size();
    // 从后先前将空格替换为"%20"
    for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
        if (s[j] != ' ') {
            s[i] = s[j];
        } else {
            s[i] = '0';
            s[i - 1] = '2';
            s[i - 2] = '%';
            i -= 2;
        }
    }
    return s;
}

int main() {
    string s{"we are happy"};
    string res = replaceSpace(s);
    cout << res << endl;
}