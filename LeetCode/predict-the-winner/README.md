# Predict the Winner

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | python3 |
| **Solved On** | August 14, 2026 |
| **Tags** | Array, Math, Dynamic Programming, Recursion, Minimax, Game Theory, Zero-Sum Game |
| **Link** | [View Problem](https://leetcode.com/problems/predict-the-winner/) |
| **Runtime** | 0 ms |
| **Memory** | 19.3 MB |

## Problem Description

<p>You are given an integer array <code>nums</code>. Two players are playing a game with this array: player 1 and player 2.</p>

<p>Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of <code>0</code>. At each turn, the player takes one of the numbers from either end of the array (i.e., <code>nums[0]</code> or <code>nums[nums.length - 1]</code>) which reduces the size of the array by <code>1</code>. The player adds the chosen number to their score. The game ends when there are no more elements in the array.</p>

<p>Return <code>true</code> if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return <code>true</code>. You may assume that both players are playing optimally.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,5,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,5,233,7]
<strong>Output:</strong> true
<strong>Explanation:</strong> Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 20</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Easy Python | 100% Speed | Recursion + Memoization
**Author**: [@Aragorn_](https://leetcode.com/Aragorn_/)
**Upvotes**: 31 👍
**Link**: [View Original Post](https://leetcode.com/problems/predict-the-winner/solutions/746142/)

---

**Easy Python | 100% Speed | Recursion + Memoization**

Easy Python solution tracking the maximum score that Player 1 can achieve. The score of Player 2 can be calculated afterwards by noting that both scores must sum the total of the array: Player_1 + Player_2 = Sum(nums).

For each turn of Player_1, we do the following:
1. We consider picking the first or the last element of the (remaining) array separately. Each alternative is assigned a score, according to the rules of step-2.

2. For each alternative in step-1, we consider that Player 2 is smart and will leave us with the worst possible score afterwards. So, from the 2 upcoming turns (with Player 2 picking his/her first or last element), we consider that we achieve the **minimum** score from these possibilities.

3. After using the previous rules, we pick the **best** score from the 2 alternatives described in (1).

4. Steps (1-3) are repeated recursively until we reach an answer. We use memoization to avoid redundant calculations.

I hope the expalanation was helpful. Cheers,

```
class Solution:
    def PredictTheWinner(self, A):
        memo = {}
        def maxscore(i,j):
            if (i,j) in memo:
                return memo[i,j]
            if i>j:
                return 0
            #
            sA = A[i] + min( maxscore(i+1,j-1), maxscore(i+2,j  ) ) # pick A[i] + min of the 2 possible upcoming turns (player 2 is smart)
            sB = A[j] + min( maxscore(i  ,j-2), maxscore(i+1,j-1) )
            score = max(sA,sB)
            memo[i,j] = score
            return score
        p1 = maxscore(0,len(A)-1) # Score Player 1
        return p1>=(sum(A)-p1) # p1 >= p2
```

</details>
