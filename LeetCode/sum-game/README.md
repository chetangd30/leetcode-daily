# Sum Game

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | python3 |
| **Solved On** | August 23, 2026 |
| **Tags** | Math, String, Greedy, Game Theory |
| **Link** | [View Problem](https://leetcode.com/problems/sum-game/) |
| **Runtime** | 0 ms |
| **Memory** | 19.3 MB |

## Problem Description

<p>Alice and Bob take turns playing a game, with <strong>Alice</strong><strong>&nbsp;starting first</strong>.</p>

<p>You are given a string <code>num</code> of <strong>even length</strong> consisting of digits and <code>'?'</code> characters. On each turn, a player will do the following if there is still at least one <code>'?'</code> in <code>num</code>:</p>

<ol>
	<li>Choose an index <code>i</code> where <code>num[i] == '?'</code>.</li>
	<li>Replace <code>num[i]</code> with any digit between <code>'0'</code> and <code>'9'</code>.</li>
</ol>

<p>The game ends when there are no more <code>'?'</code> characters in <code>num</code>.</p>

<p>For Bob&nbsp;to win, the sum of the digits in the first half of <code>num</code> must be <strong>equal</strong> to the sum of the digits in the second half. For Alice&nbsp;to win, the sums must <strong>not be equal</strong>.</p>

<ul>
	<li>For example, if the game ended with <code>num = "243801"</code>, then Bob&nbsp;wins because <code>2+4+3 = 8+0+1</code>. If the game ended with <code>num = "243803"</code>, then Alice&nbsp;wins because <code>2+4+3 != 8+0+3</code>.</li>
</ul>

<p>Assuming Alice and Bob play <strong>optimally</strong>, return <code>true</code> <em>if Alice will win and </em><code>false</code> <em>if Bob will win</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> num = "5023"
<strong>Output:</strong> false
<strong>Explanation:</strong> There are no moves to be made.
The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> num = "25??"
<strong>Output:</strong> true
<strong>Explanation: </strong>Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> num = "?3295???"
<strong>Output:</strong> false
<strong>Explanation:</strong> It can be proven that Bob will always win. One possible outcome is:
- Alice replaces the first '?' with '9'. num = "93295???".
- Bob replaces one of the '?' in the right half with '9'. num = "932959??".
- Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
- Bob replaces the last '?' in the right half with '7'. num = "93295927".
Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num.length</code> is <strong>even</strong>.</li>
	<li><code>num</code> consists of only digits and <code>'?'</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Python 3 | Simple Math | Explanation
**Author**: [@idontknoooo](https://leetcode.com/idontknoooo/)
**Upvotes**: 36 👍
**Link**: [View Original Post](https://leetcode.com/problems/sum-game/solutions/1330360/)

---

### Explanation
- Intuition: Starting with the three examples, you will soon realize that this is essentially a Math problem.
- Our goal is to see if left sum can equal to right sum, that is, `left_sum - right_sum == 0`. 
- To make it easier to understand, we can move digits to one side and `?` mark to the other side, for example, `?3295???`
	- Can be represented as `?329=5???` -> `3+2+9-5=???-?` -> `9=??`
	- Now, the original question becomes: Given `9=??`  and Alice plays first, can we get this left & right not equal to each other?
	- The answer is NO. It doesn\'t matter what number `x` Alice gives, Bob only need to provide `9-x` to make sure the left equals to right.
- Let\'s try out some other examples, based on the previous observation.
	- `8=??`, can Alice win? 
		- Yes, if Alice plays 9 first
	- `9=???`, can Alice win?
		- Yes, since Alice can play 1 time more than Bob
	- `9=????`, can Alice win?
		- Yes, if the sum of Alice\'s 2 plays is greater than 9
	- `18=????`, can Alice win?
		- No, ame as `9=??`, doesn\'t matter what `x` Alice plays, Bob just need to play `9-x`
	- `18=??`, can Alice win?
		- Yes, unless Alice & Bob both play 9 (not optimal play, against the game rule)
- I think now you should get the idea of the game. Let\'s say, for left side & right side, we move the smaller sum to the other side of the equal sign (we call the result `digit_sum`); for question mark, we move it to the opposite direction (we call the result `?_count`. After doing something Math, the only situation that Bob can win is that:
	- `?_count % 2 == 0 and digit_sum == ?_count // 2 * 9`. This basically saying that:
		- `?_count` has to be an even number
		- `digit_sum` is a multiple of 9
		- Half number of plays (or `?`) * 9 equals to `digit_sum`
- In the following implementation:
	- `q_cnt_1`: **Q**uestion mark **c**ou**nt** for the **1**st half of `num`
	- `q_cnt_2`: **Q**uestion mark **c**ou**nt** for the **2**nd half of `num`
	- `s1`: **S**um of digits for the **1**st half of `num`
	- `s2`: **S**um of digits for the **2**nd half of `num`
	- `s_diff`: **S**um difference (we take the greater sum - the smaller sum)
	- `q_diff`: **Q**uestion mark difference (opposite direction to the digit sum move)


### Implementation
```
class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        q_cnt_1 = s1 = 0
        for i in range(n//2):    # get digit sum and question mark count for the first half of `num`
            if num[i] == \'?\':
                q_cnt_1 += 1
            else:    
                s1 += int(num[i])
        q_cnt_2 = s2 = 0				
        for i in range(n//2, n): # get digit sum and question mark count for the second half of `num`
            if num[i] == \'?\':
                q_cnt_2 += 1
            else:    
                s2 += int(num[i])
        s_diff = s1 - s2         # calculate sum difference and question mark difference
        q_diff = q_cnt_2 - q_cnt_1
        return not (q_diff % 2 == 0 and q_diff // 2 * 9 == s_diff) # When Bob can\'t win, Alice wins
```

</details>
