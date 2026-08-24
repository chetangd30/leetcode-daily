# Stone Game VIII

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Hard |
| **Language** | python3 |
| **Solved On** | August 24, 2026 |
| **Tags** | Array, Math, Dynamic Programming, Minimax, Prefix Sum, Game Theory, Zero-Sum Game |
| **Link** | [View Problem](https://leetcode.com/problems/stone-game-viii/) |
| **Runtime** | 40 ms |
| **Memory** | 19.3 MB |

## Problem Description

<p>Alice and Bob take turns playing a game, with <strong>Alice starting first</strong>.</p>

<p>There are <code>n</code> stones arranged in a row. On each player's turn, while the number of stones is <strong>more than one</strong>, they will do the following:</p>

<ol>
	<li>Choose an integer <code>x &gt; 1</code>, and <strong>remove</strong> the leftmost <code>x</code> stones from the row.</li>
	<li>Add the <strong>sum</strong> of the <strong>removed</strong> stones' values to the player's score.</li>
	<li>Place a <strong>new stone</strong>, whose value is equal to that sum, on the left side of the row.</li>
</ol>

<p>The game stops when <strong>only</strong> <strong>one</strong> stone is left in the row.</p>

<p>The <strong>score difference</strong> between Alice and Bob is <code>(Alice's score - Bob's score)</code>. Alice's goal is to <strong>maximize</strong> the score difference, and Bob's goal is the <strong>minimize</strong> the score difference.</p>

<p>Given an integer array <code>stones</code> of length <code>n</code> where <code>stones[i]</code> represents the value of the <code>i<sup>th</sup></code> stone <strong>from the left</strong>, return <em>the <strong>score difference</strong> between Alice and Bob if they both play <strong>optimally</strong>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> stones = [-1,2,-3,4,-5]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
- Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to her score, and places a stone of
  value 2 on the left. stones = [2,-5].
- Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, and places a stone of value -3 on
  the left. stones = [-3].
The difference between their scores is 2 - (-3) = 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> stones = [7,-6,5,10,5,-2,-6]
<strong>Output:</strong> 13
<strong>Explanation:</strong>
- Alice removes all stones, adds 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 to her score, and places a
  stone of value 13 on the left. stones = [13].
The difference between their scores is 13 - 0 = 13.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> stones = [-10,-12]
<strong>Output:</strong> -22
<strong>Explanation:</strong>
- Alice can only make one move, which is to remove both stones. She adds (-10) + (-12) = -22 to her
  score and places a stone of value -22 on the left. stones = [-22].
The difference between their scores is (-22) - 0 = -22.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == stones.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= stones[i] &lt;= 10<sup>4</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Top-Down and Bottom-Up
**Author**: [@votrubac](https://leetcode.com/votrubac/)
**Upvotes**: 57 👍
**Link**: [View Original Post](https://leetcode.com/problems/stone-game-viii/solutions/1224872/)

---

Regardless of how the game was played till now, ending a move with stone `i` will add sum of all `[0.. i]` stones to your score. So, we first compute a prefix sum to get scores in O(1); in other words, `st[i]` will be a sum of all stones `[0..i]`.

The first player can take all stones and call it a day if all values are positive. Since there could be negatives, we may want the other player to pick some stones too. 

Let\'s say `dp[i]` represents the maximum score difference if the *first player* ends their *first move* with stone `i` or later. We start from the right, and for `i == n - 1` it will be the sum of all stones.

If the *first players* ends the move with stone `i - 1`, the difference will be `st[i - 1] - dp[i]`. The reason for that is that `dp[i]` now represents the maximum score difference for the *second player*. If the first player ended the move with stone `i - 1`, the second player can play and end their turn with stone `i` or later.

So, if the first player picks `i - 1`, the difference will be `st[i - 1] - dp[i]`, or if the player picks some later stone, the difference will be `dp[i]`. Therefore, to maximize the difference, we pick the best of these two choices: `dp[i - 1] = max(dp[i], st[i - 1] - dp[i])`.

#### Approach 1: Top-Down
This approach looks kind of similar to Knapsack 0/1. We either stop our turn at the stone `i`, or keep adding stones.

**C++**
```cpp
int dp[100001] = { [0 ... 100000] = INT_MIN };
int dfs(vector<int>& st, int i) {
    if (i == st.size() - 1)
        return st[i];
    if (dp[i] == INT_MIN)
        dp[i] = max(dfs(st, i + 1), st[i] - dfs(st, i + 1));
    return dp[i];
}
int stoneGameVIII(vector<int>& st) {
    partial_sum(begin(st), end(st), begin(st));
    return dfs(st, 1);
}
```

#### Approach 2: Bottom-Up
Tabulation allows us to achieve O(1) memory complexity. Since we only look one step back, we can use a single variable `res` instead of the `dp` array.

**C++**
```cpp
int stoneGameVIII(vector<int>& st) {
    partial_sum(begin(st), end(st), begin(st));
    int res = st.back();
    for (int i = st.size() - 2; i > 0; --i)
        res = max(res, st[i] - res);
    return res;
}
```
**Python 3**
```python
class Solution:
    def stoneGameVIII(self, s: List[int]) -> int:
        s, res = list(accumulate(s)), 0
        for i in range(len(s) - 1, 0, -1):
            res = s[i] if i == len(s) - 1 else max(res, s[i] - res)
        return res
```

</details>
