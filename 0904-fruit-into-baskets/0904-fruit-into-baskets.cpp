class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> baskets;   
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            baskets[fruits[right]]++;

            
            while (baskets.size() > 2) {
                baskets[fruits[left]]--;
                if (baskets[fruits[left]] == 0) {
                    baskets.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};