#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> ans;
        vector<pair<int, int>> faq;
        for (auto & restaurant : restaurants) {
            if (restaurant[2] >= veganFriendly && restaurant[3] <= maxPrice &&
                restaurant[4] <= maxDistance) {
                faq.emplace_back(restaurant[0], restaurant[1]);
            }
            cout << restaurant[2] << " " << restaurant[3] << " " << restaurant[4] << endl;
        }
        std::sort(faq.begin(), faq.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second > b.second;
        });
        std::for_each(faq.begin(), faq.end(), [&](auto i) -> void {
            ans.push_back(i.first);
        });
        return ans;
    }
};

int main() {
    return 0;
}