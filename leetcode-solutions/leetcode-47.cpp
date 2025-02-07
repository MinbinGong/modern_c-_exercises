/*
    Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any
    order.



    Example 1:

    Input: nums = [1,1,2]
    Output:
    [[1,1,2],
    [1,2,1],
    [2,1,1]]
    Example 2:

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


    Constraints:

    1 <= nums.length <= 8
    -10 <= nums[i] <= 10
 */

/*

    Time Complexity : O(N!*KlogK), In worst case when all element of Array(nums) will different then there will
    be N! permutations and N! function calls and for every permutation we have to check in Hash Table(set) for
    inserting which take O(KlogK) time .Where N is the size of the array(nums) and ! stands for factorial. K is
    the worst case size of Array(output).

    Space Complexity: O(N!*N), In worst case when all element of Array(nums) will different, since we have to
    store all the possible solutions which are N! in size where N is the size of the array and ! stands for
    factorial.

    Solved using Array + BackTracking + Hash Table(set).

*/
#include <algorithm>
#include <set>
#include <vector>

/* Solution 1: using Array + Backtracking + Hash table */

void permuteUnique1(std::vector<int>& nums, std::set<std::vector<int>>& set, std::vector<int>& temp, int index) {
  if (index == nums.size()) {
    set.insert(temp);
    return;
  }

  for (int i = index; i < temp.size(); i++) {
    std::swap(temp[index], temp[i]);
    permuteUnique(nums, set, temp, index + 1);
  }
}

std::vector<std::vector<int>> permuteUnique1(std::vector<int>& nums) {
  std::vector<std::vector<int>> output;
  std::vector<int> temp = nums;

  std::sort(temp.begin(), temp.end());
  std::set<std::vector<int>> set;
  permuteUnique(nums, set, temp, 0);
  for (auto it : set) {
    output.push_back(it);
  }
  return output;
}

/* Solution 2: Array + Backtracking */
void permuteUnique2(std::vector<int>& nums, std::vector<std::vector<int>>& output, std::vector<int>& temp, int index) {
  if (index == nums.size()) {
    output.push_back(temp);
    return;
  }

  for (int i = index; i < temp.size(); i++) {
    std::swap(temp[index], temp[i]);
    bool is_present = std::find(output.begin(), output.end(), temp) != output.end();
    if (is_present) {
      continue;
    }
    permuteUnique(nums, output, temp, index + 1);
  }
}

std::vector<std::vector<int>> permuteUnique2(std::vector<int>& nums) {
  std::vector<std::vector<int>> output;
  std::vector<int> temp = nums;
  std::sort(temp.begin(), temp.end());
  permuteUnique(nums, output, temp, 0);
  return output;
}

/* Solution 3 : Array + BackTracking */
void permuteUnique3(std::vector<int>& nums, std::vector<std::vector<int>>& output, std::vector<int>& temp, int index) {
  if (index == nums.size()) {
    output.push_back(temp);
    return;
  }

  for (int i = index; i < temp.size(); i++) {
    std::swap(temp[index], temp[i]);
    bool is_present = std::find(output.begin(), output.end(), temp) != output.end();
    if (is_present) {
      continue;
    }
    permuteUnique3(nums, output, temp, index + 1);
  }
}

std::vector<std::vector<int>> permuteUnique3(std::vector<int>& nums) {
  std::vector<std::vector<int>> output;
  std::vector<int> temp = nums;
  std::sort(temp.begin(), temp.end());
  permuteUnique3(nums, output, temp, 0);
  return output;
}