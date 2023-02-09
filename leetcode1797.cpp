#include "bits/stdc++.h"
using namespace std;
class AuthenticationManager {
public:
    int timeToLive;
    map<string,int> keyMap;
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    void TimeCheck(int currentTime) {
        for (auto &[k,v] : keyMap) {
            if (v <= currentTime) {
                keyMap.
            }
        }
    }
    void generate(string tokenId, int currentTime) {
        keyMap[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        TimeCheck(currentTime);

    }

    int countUnexpiredTokens(int currentTime) {

    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
int main() {
    return 0;
}