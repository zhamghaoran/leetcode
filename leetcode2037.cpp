#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int ans = 0;
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        for (int i = 0;i < seats.size();i ++) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};
int main() {

    return 0;
}