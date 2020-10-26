#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#include <algorithm>
#include <iterator>     // std::distance
#include <list>         // std::list
#include <map>

// implement a solution with a linear runtime complexity and without using extra memory
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        if(nums.empty()) {
            return -1;
        }
        int idx_of_single_num = 0;

        std::map<int, int> appear_map; // {appear value, appear times}
        for(int i = 0 ; i < nums.size() ; i++) {
            appear_map[nums[i]] += 1;
        }

        for(auto it = appear_map.begin(); it != appear_map.end(); it++) {
            printf("{%d:%d}\n", it->first, it->second);
            if(it->second == 1) {
                return it->first;
            }
        }
        return 0;
    }

    // 
    int singleNumber_no_extra_memory(std::vector<int>& nums) {
        
        return 0;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> nums{2,2,9,2,5,5,5,17,17,17};
    printf("output:%d\n", s -> singleNumber(nums));
}
