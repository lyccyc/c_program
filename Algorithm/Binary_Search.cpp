#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Algorithm{
public:
    int Binary_Search(vector<int> &nums, int target){
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;
            if(target < nums[mid]){
                right = mid - 1; 
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};

int main(){
    Algorithm AI;
    vector<int> nums = {1,5,3,9,8,10,20,17,35,12};
    int find = AI.Binary_Search(nums, 8);
    cout<<find;
}
