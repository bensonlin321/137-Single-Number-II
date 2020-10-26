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

    /*
        example: [1,3,1,3,7,1,3]

        |value||     bits      |
           1    0 0 0 0 0 0 0 1
           3    0 0 0 0 0 0 1 1
           1    0 0 0 0 0 0 0 1
           3    0 0 0 0 0 0 1 1
           7    0 0 0 0 0 1 1 1
           1    0 0 0 0 0 0 0 1
           3    0 0 0 0 0 0 1 1
        ------------------------
                          | | |
                          | | |-> column 1, number of 1 is 7, can not be divided by 3  => the column 1 of answer is 1
                          | |---> colume 2, number of 1 is 4, can not be divided by 3  => the column 2 of answer is 1
                          |-----> colume 2, number of 1 is 1, can not be divided by 3  => the column 3 of answer is 1
        
        ans :   0 0 0 0 0 1 1 1
        _______________________
                         dec: 7
    */
    int singleNumber_no_extra_memory(std::vector<int>& nums) {
        int ans = 0;

        // max bit is 32
        for(int i = 0; i < 32; i++) {
            int count = 0;
            printf("===============\n");
            // number value
            for (int j = 0; j < nums.size(); j++) {
                // calculate the number of "1" in each row
                if (( (nums[j] >> i) & 1 ) == 1) {
                    count++;
                }

                printf("%d\n", (nums[j] >> i) & 1);
            }
            printf("===============\n");
            // check if the number of "1" can be divided by 3
            if (count % 3 != 0) {
                ans = ans | (1 << i);
            }
            printf("[%d] %d %d %d %d %d\n", i, (ans >> 4) & 1, (ans >> 3) & 1, (ans >> 2) & 1, (ans >> 1) & 1, (ans >> 0) & 1);
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> nums{1,3,1,3,7,1,3};
    printf("output:%d\n", s -> singleNumber_no_extra_memory(nums));
}
