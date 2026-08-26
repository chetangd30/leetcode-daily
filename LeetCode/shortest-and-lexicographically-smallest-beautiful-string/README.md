# Shortest and Lexicographically Smallest Beautiful String

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | python3 |
| **Solved On** | August 26, 2026 |
| **Tags** | String, Sliding Window |
| **Link** | [View Problem](https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/) |
| **Runtime** | 0 ms |
| **Memory** | 19.3 MB |

## Problem Description

<p>You are given a binary string <code>s</code> and a positive integer <code>k</code>.</p>

<p>A substring of <code>s</code> is <strong>beautiful</strong> if the number of <code>1</code>'s in it is exactly <code>k</code>.</p>

<p>Let <code>len</code> be the length of the <strong>shortest</strong> beautiful substring.</p>

<p>Return <em>the lexicographically <strong>smallest</strong> beautiful substring of string </em><code>s</code><em> with length equal to </em><code>len</code>. If <code>s</code> doesn't contain a beautiful substring, return <em>an <strong>empty</strong> string</em>.</p>

<p>A string <code>a</code> is lexicographically <strong>larger</strong> than a string <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, <code>a</code> has a character strictly larger than the corresponding character in <code>b</code>.</p>

<ul>
	<li>For example, <code>"abcd"</code> is lexicographically larger than <code>"abcc"</code> because the first position they differ is at the fourth character, and <code>d</code> is greater than <code>c</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "100011001", k = 3
<strong>Output:</strong> "11001"
<strong>Explanation:</strong> There are 7 beautiful substrings in this example:
1. The substring "<u>100011</u>001".
2. The substring "<u>1000110</u>01".
3. The substring "<u>10001100</u>1".
4. The substring "1<u>00011001</u>".
5. The substring "10<u>0011001</u>".
6. The substring "100<u>011001</u>".
7. The substring "1000<u>11001</u>".
The length of the shortest beautiful substring is 5.
The lexicographically smallest beautiful substring with length 5 is the substring "11001".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "1011", k = 2
<strong>Output:</strong> "11"
<strong>Explanation:</strong> There are 3 beautiful substrings in this example:
1. The substring "<u>101</u>1".
2. The substring "1<u>011</u>".
3. The substring "10<u>11</u>".
The length of the shortest beautiful substring is 2.
The lexicographically smallest beautiful substring with length 2 is the substring "11".
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "000", k = 1
<strong>Output:</strong> ""
<strong>Explanation:</strong> There are no beautiful substrings in this example.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Python 3   ||   6 lines, with explanation  ||   T/S: 98% / 99%
**Author**: [@Spaulding_](https://leetcode.com/Spaulding_/)
**Upvotes**: 6 👍
**Link**: [View Original Post](https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/solutions/4172386/)

---

Here\'s the plan:

An analysis of the problem leads to this condition: the first and last characters of the solution must each be one. So:

1. We collect the indices of ones in `ones`.
2. We determine the delimiting indices `l` and `r` of those candidate strings in`cands` that (a) start and end with one and (b) contain`k`ones.
2. We determine `minLen`, the minimum `r-l` of elements in `cands`.
3. We filter`cands`to only include those candidates for which `l-r = minLen`
4. We determine the lexicographically smallest substring with`min`.

```
class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:

        ones = [i for i, digit in enumerate(s) if digit == \'1\']     # <-- 1.
        
        if len(ones) < k: return \'\'

        cands = list(zip(ones,ones[k-1:]))                          
        minLen = min(r-l for l, r in cands)                         # <-- 2.

        cands = list(filter(lambda x: x[1]-x[0] == minLen, cands))  # <-- 3.

        return min([s[l:r+1] for l,r in cands])                     # <-- 4.
```
[https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/submissions/1272097085/](https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/submissions/1272097085/)

I could be wrong, but I think that time complexity is *O*(*N*) and space complexity is *O*(*N*), in which *N* ~ `len(s)`.




</details>
