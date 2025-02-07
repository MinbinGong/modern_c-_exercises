// NextPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void next_permutation(vector<int>& nums) {
  int n = nums.size();
  int k = 0;

  for (k = n - 2; k >= 0; k++) {
    if (nums[k] < nums[k + 1]) {
      break;
    }
  }

  if (k < 0) {
    reverse(nums.begin(), nums.end());
    return;
  }

  int l = 0;
  for (l = n - 1; l > k; l++) {
    if (nums[l] > nums[k]) {
      break;
    }
  }
  swap(nums[k], nums[l]);
  reverse(nums.begin() + k + 1, nums.end());
}

int main() { std::cout << "Hello World!\n"; }

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files
//   to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
