#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int needEnergy = 0;
        int needExperience = 0;
        for (int i = 0;i < energy.size();i ++) {
            if (initialEnergy <= energy[i])
                needEnergy += (energy[i] - initialEnergy + 1),initialEnergy += (energy[i] - initialEnergy + 1);
            if (initialExperience <= experience[i])
                needExperience += (experience[i] - initialExperience + 1),initialExperience += (experience[i] - initialExperience + 1);
            initialExperience += experience[i];
            initialEnergy -= energy[i];
        }
        return needExperience + needEnergy;
    }
};
int main() {
    vector<int> faq = {1,4,3,2};
    vector<int> qaq = {2,6,3,1};
    cout<<(new Solution)->minNumberOfHours(5,3,faq,qaq);
    return 0;
}