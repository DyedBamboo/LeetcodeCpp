/***
 * @Author: RanZhuJun
 * @Date: 2023-06-22 23:07:04
 * @LastEditTime: 2023-06-22 23:07:05
 * @Description: leetcode 第202题. 快乐数
 * @FilePath: \LeetcodeCpp\Hashmap\3.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>
#include <unordered_set>

using namespace std;

int getSum(int n) {
    int sum = 0;
    while(n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> set;
    while(true) {
        int sum = getSum(n);
        if(sum == 1) {
            return true;
        }
        // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
        if(set.find(sum) != set.end()) {
            return false;
        }else {
            set.insert(sum);
        }
        n = sum;
    }
}

int main() {
    int num = 19;
    bool ans = isHappy(num);
    cout << ans << endl;
}