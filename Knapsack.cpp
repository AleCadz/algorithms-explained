#include <bits/stdc++.h>

int main()
{
    int N, W, max = 0;
    std::cin >> N >> W;

    int items[N + 1][2], tab[N + 1][W + 1];
    
    for (int i = 1; i < N + 1; i++)
        std::cin >> items[i][0] >> items[i][1];
    
    for (int i = 0; i < W + 1; i++)
        tab[0][i] = 0;
    
    for (int i = 0; i < N + 1; i++)
        tab[i][0] = 0;
    
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (items[i][0] > j)
            {
                tab[i][j] = tab[i - 1][j];
                continue;
            }
            if ((items[i][1] + tab[i - 1][j - items[i][0]]) > tab[i - 1][j])
                max = (items[i][1] + tab[i - 1][j - items[i][0]]);
            else
                max = tab[i - 1][j];
            tab[i][j] = max;
        }
    }
    std::cout << max;
    return 0;
}


/* --------------------------------------------------
# Implemented by Alejandro del Castillo Diaz / 01/06/2025
# Description:
# This algorithm solves the 0-1 Knapsack problem using
# dynamic programming and returns an optimal solution.
#
# How to get the solution:
# The 0-1 Knapsack problem states:
# Given a set of items, each with a specific weight
# and value, our goal is to pack the most valuable
# subset of these items without exceeding a maximum
# weight capacity.
#
# To solve this, we use a DP table 'tab' where:
# tab[i][j] represents the maximum value achievable
# using items from 1..i with a weight limit j.
#
# The main recurrence relation is:
#   if items[i].weight > j:
#      tab[i][j] = tab[i-1][j]
#   else:
#      tab[i][j] = max(
#        tab[i-1][j],  // don't take item i
#        items[i].value + tab[i-1][j - items[i].weight] // take item i
#      )
#
# We start by initializing tab[0][j] and tab[i][0]
# to 0, meaning if we have zero capacity or zero
# items, the maximum value is 0.
#
# Finally, tab[N][W] (where N is the number of items
# and W is the capacity) holds the answer. We simply
# return/print this result.
# --------------------------------------------------
*/
