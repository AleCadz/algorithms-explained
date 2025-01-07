#include <bits/stdc++.h>

using mapInt = std::unordered_map<int, unsigned long long int>;

unsigned long long int fibonacci(int N, mapInt &memo);

int main()
{

    mapInt memo;
    int N;
    std::cin >> N;
    std::cout << fibonacci(N, memo);

    return 0;
}

unsigned long long int fibonacci(int N, mapInt &memo)
{
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    if (memo.find(N) != memo.end())
        return memo[N];
    memo[N] = fibonacci(N - 1, memo) + fibonacci(N - 2, memo);
    return memo[N];
}

/* --------------------------------------------------
# Implemented by Alejandro del Castillo Diaz / 01/06/2025
# Description:
# This algorithm computes the N-th Fibonacci number using a Dynamic Programming approach with memoization.
# How this solution works:
# 1) We first check if N is in our memo (an unordered_map). If it is, we return the stored value.
# 2) If not, we recursively compute fibonacci(N - 1) and fibonacci(N - 2), store the sum in our memo, then return it.
# 3) Base Cases:
#    - When N == 0 the function returns 0
#    - When N == 1 the function returns 1
# Time Complexity:
#    - Each state is computed once and stored in the memo. Consequently, the time complexity is O(N).
# --------------------------------------------------
*/
