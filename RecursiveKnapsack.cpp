#include <bits/stdc++.h>
#include <vector>

int knapsack(int N, int W, int arr[][2], std::vector<std::vector<int>> &memo);

int main()
{

    int N, W, max = 0;
    std::cin >> N >> W;
    int items[N + 1][2];
    std::vector<std::vector<int>> memo(N + 1, std::vector<int>(W + 1, -1));
    for (int i = 1; i < N + 1; i++)
        std::cin >> items[i][0] >> items[i][1];

    std::cout << knapsack(N, W, items, memo) << "\n";

    return 0;
}

int knapsack(int N, int W, int arr[][2], std::vector<std::vector<int>> &memo)
{

    if (N == 0 || W == 0)
        return 0;
    if (arr[N][0] > W)
        return knapsack(N - 1, W, arr, memo);
    if (memo[N][W] != -1)
        return memo[N][W];
    int includeItem = arr[N][1] + knapsack(N - 1, W - arr[N][0], arr, memo);
    int excludeItem = knapsack(N - 1, W, arr, memo);
    memo[N][W] = std::max(includeItem, excludeItem);
    return memo[N][W];
}

/* --------------------------------------------------
# Implemented by Alejandro del Castillo Diaz / 01/07/2025
# Description:
# This program implements the 0/1 Knapsack problem using dynamic programming with memoization.
# The knapsack problem is a classic optimization problem where the goal is to maximize the total value of selected items without exceeding a given weight limit (W).
# How the solution works:
# - The input consists of the number of items (N), the maximum weight capacity (W), and a list of items where each item has a weight and a value.
# - A 2D memoization table (`memo`) is used to store subproblem results to avoid redundant calculations.
# - The function `knapsack` recursively considers two choices for each item:
#   1. Include the item in the knapsack (if its weight allows) and add its value to the total.
#   2. Exclude the item and proceed with the remaining items.
# - The base case occurs when there are no remaining items (N == 0) or when the weight limit (W == 0) is reached.
# - The optimal solution is computed by taking the maximum between including or excluding each item.
# Input format:
# - The first line contains two integers, N (number of items) and W (weight capacity).
# - The next N lines each contain two integers: the weight and value of each item.
# Output:
# - The maximum total value that can be obtained without exceeding the weight limit.
# Example:
# Input:
# 3 5
# 2 5
# 1 3
# 3 4
# Output:
# 9: Item 1 + Item 3
# --------------------------------------------------
*/
