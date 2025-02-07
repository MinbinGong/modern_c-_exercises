// Leetcode 81. Search in Rotated Sorted Array II
// There is an integer array nums sorted in non - decreasing order(not necessarily with distinct values).
// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length),
// such that the resulting array is [nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ...,
// nums[k - 1]](0 - indexed).
// For example, [ 0, 1, 2, 4, 4, 4, 5, 6, 6, 7 ] might be rotated at pivot index 5 and
// become[4, 5, 6, 6, 7, 0, 1, 2, 4, 4].
// Given the array nums after the rotation and an integer target, return true if target is
// in nums, or false if it is not in nums.
// You must decrease the overall operation steps as much as possible.

#include <vector>
using namespace std;

bool search(vector<int> &nums, int target) {
  unsigned int l{0}, r{nums.size() - 1};

  while (l <= r) {
    unsigned int mid = l + (r - l) >> 1;
    if (nums[mid] == target) {
      return true;
    }

    if ((nums[l] == nums[mid]) && (nums[mid] == nums[r])) {
      l++;
      r--;
    } else if (nums[l] < nums[mid]) {
      if ((nums[l] <= target) && (nums[mid] > target)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    } else {
      if ((nums[mid] < target) && (nums[r] >= target)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  return false;
}

bool search1(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return true;
        }

        if (nums[start] == nums[mid]) {
            ++start;
        } else if (nums[mid] <= nums[end]) {
            if (target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else {
            if (target >= nums[start] && target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }

    return false;
}
