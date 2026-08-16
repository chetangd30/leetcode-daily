# Stone Game IX

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | python3 |
| **Solved On** | August 16, 2026 |
| **Tags** | Array, Math, Greedy, Minimax, Counting, Game Theory, Nim Game, Zero-Sum Game |
| **Link** | [View Problem](https://leetcode.com/problems/stone-game-ix/) |
| **Runtime** | 0 ms |
| **Memory** | 19.6 MB |

## Problem Description

<p>Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an associated value. You are given an integer array <code>stones</code>, where <code>stones[i]</code> is the <strong>value</strong> of the <code>i<sup>th</sup></code> stone.</p>

<p>Alice and Bob take turns, with <strong>Alice</strong> starting first. On each turn, the player may remove any stone from <code>stones</code>. The player who removes a stone <strong>loses</strong> if the <strong>sum</strong> of the values of <strong>all removed stones</strong> is divisible by <code>3</code>. Bob will win automatically if there are no remaining stones (even if it is Alice's turn).</p>

<p>Assuming both players play <strong>optimally</strong>, return <code>true</code> <em>if Alice wins and</em> <code>false</code> <em>if Bob wins</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> stones = [2,1]
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;The game will be played as follows:
- Turn 1: Alice can remove either stone.
- Turn 2: Bob removes the remaining stone. 
The sum of the removed stones is 1 + 2 = 3 and is divisible by 3. Therefore, Bob loses and Alice wins the game.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> stones = [2]
<strong>Output:</strong> false
<strong>Explanation:</strong>&nbsp;Alice will remove the only stone, and the sum of the values on the removed stones is 2. 
Since all the stones are removed and the sum of values is not divisible by 3, Bob wins the game.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> stones = [5,1,2,4,3]
<strong>Output:</strong> false
<strong>Explanation:</strong> Bob will always win. One possible way for Bob to win is shown below:
- Turn 1: Alice can remove the second stone with value 1. Sum of removed stones = 1.
- Turn 2: Bob removes the fifth stone with value 3. Sum of removed stones = 1 + 3 = 4.
- Turn 3: Alices removes the fourth stone with value 4. Sum of removed stones = 1 + 3 + 4 = 8.
- Turn 4: Bob removes the third stone with value 2. Sum of removed stones = 1 + 3 + 4 + 2 = 10.
- Turn 5: Alice removes the first stone with value 5. Sum of removed stones = 1 + 3 + 4 + 2 + 5 = 15.
Alice loses the game because the sum of the removed stones (15) is divisible by 3. Bob wins the game.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= stones.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= stones[i] &lt;= 10<sup>4</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: [Python3] freq table
**Author**: [@ye15](https://leetcode.com/ye15/)
**Upvotes**: 5 👍
**Link**: [View Original Post](https://leetcode.com/problems/stone-game-ix/solutions/1500343/)

---

**Intuition**
Here, the specific numbers don\'t matter. Only the modulos do. 
In order for Alice to win, the sequence would be like 
1) 1(12)(12)...(12)2 with even number of 0\'s between first 1 and final 2
2) 1(12)(12)...(12)11 with odd number of 0\'s between first 1 and final 1

where 1\'s and 2\'s are interchangable due to symmetry. So the strategy is 
1) if there are even number of 0\'s, Alice would choose 1 or 2 whoever is less or equal frequent as long as they both exist. Without loss of generality, let\'s say 1 is less frequent. In this case, it is guranteed to be Bob\'s turn to place the last number 2 when they run out of 1\'s. 
2) if there are odd number of 0\'s, Alice would choose 1 or 2 whoever is more frequent. Let\'s say 1 is more frequent in the input. In this case, Alice need three extra 1\'s to win. Besides, it is not difficult to figure out that as long as there are three (or more) extra 1\'s Alice will win. 

```
class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        freq = defaultdict(int)
        for x in stones: freq[x % 3] += 1
        
        if freq[0]%2 == 0: return freq[1] and freq[2]
        return abs(freq[1] - freq[2]) >= 3
```

</details>
