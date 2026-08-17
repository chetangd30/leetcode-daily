class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:

        n = len(stoneValue)

        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + stoneValue[i]

        from functools import lru_cache

        @lru_cache(None)
        def dp(i, j):

            if i >= j:
                return 0

            ans = 0
            left = 0
            right = prefix[j + 1] - prefix[i]

            for k in range(i, j):

                left += stoneValue[k]
                right -= stoneValue[k]

                if left < right:

                    # Maximum possible result from this split
                    # is 2 * left.
                    if ans >= 2 * left:
                        continue

                    ans = max(
                        ans,
                        left + dp(i, k)
                    )

                elif left > right:

                    # Future splits will only make right smaller.
                    # If even 2 * right cannot beat ans,
                    # we can stop.
                    if ans >= 2 * right:
                        break

                    ans = max(
                        ans,
                        right + dp(k + 1, j)
                    )

                else:

                    ans = max(
                        ans,
                        left + dp(i, k),
                        right + dp(k + 1, j)
                    )

            return ans

        return dp(0, n - 1)