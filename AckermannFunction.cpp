#include <bits/stdc++.h>

using map = std::map<std::pair<int, int>, unsigned long long>;
unsigned long long int AckermannFunction(int x, int y, map &memo);

int main()
{
    map memo;
    int x, y;
    std::cin >> x >> y;
    std::cout << AckermannFunction(x, y, memo);
}

unsigned long long int AckermannFunction(int x, int y, map &memo)
{
    if (memo.find({x, y}) != memo.end())
        return memo[{x, y}];
    if (x == 0)
        return y + 1;
    if (y == 0)
        memo[{x, y}] = AckermannFunction(x - 1, 1, memo);
    else
        memo[{x, y}] = AckermannFunction(x - 1, AckermannFunction(x, y - 1, memo), memo);
    return memo[{x, y}];
}

/* --------------------------------------------------
# Implemented by Alejandro del Castillo Diaz / 01/07/2025
# Description:
# This program implements the Ackermann function, a well-known example of a highly recursive function that grows extremely fast.
# The Ackermann function is defined as follows:
#   A(x, y) =
#   - y + 1, if x == 0
#   - A(x - 1, 1), if x > 0 and y == 0
#   - A(x - 1, A(x, y - 1)), if x > 0 and y > 0
# How the solution works:
# - This implementation uses a `map` as a memoization structure to store previously computed values of the function.
# - Memoization avoids redundant recursive calls by storing the result of `A(x, y)` in the `memo` map for future reference.
# - The function first checks if the value for the current pair `(x, y)` exists in the memoization table. If it does, the stored value is returned.
# - Otherwise, the recursive formula for the Ackermann function is applied according to its definition.
# Input format:
# - The program reads two integers `x` and `y` from the standard input.
# Output:
# - The program outputs the result of `AckermannFunction(x, y)`.
# Notes:
# - Due to the rapid growth of the Ackermann function, even small values of `x` and `y` can lead to extremely large results.
# - This implementation may still hit recursion depth limits for high values of `x` and `y`, despite memoization.
# Example:
# Input:
# 2 1
# Output:
# 5 (since A(2, 1) = 5)
# --------------------------------------------------
*/
