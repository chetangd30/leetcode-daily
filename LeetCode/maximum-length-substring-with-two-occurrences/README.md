# Maximum Length Substring With Two Occurrences

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | python3 |
| **Solved On** | August 14, 2026 |
| **Tags** | Hash Table, String, Sliding Window |
| **Link** | [View Problem](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/) |
| **Runtime** | 0 ms |
| **Memory** | 19.5 MB |

## Problem Description

Given a string <code>s</code>, return the <strong>maximum</strong> length of a <span data-keyword="substring" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_s_" data-state="closed" class="">substring</button></span>&nbsp;such that it contains <em>at most two occurrences</em> of each character.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "bcbbbcba"</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>
The following substring has a length of 4 and contains at most two occurrences of each character: <code>"bcbb<u>bcba</u>"</code>.</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "aaaa"</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>
The following substring has a length of 2 and contains at most two occurrences of each character: <code>"<u>aa</u>aa"</code>.</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Python 3 || 10 lines,  Counter, iter || T/S: 97% / 99%
**Author**: [@Spaulding_](https://leetcode.com/Spaulding_/)
**Upvotes**: 10 👍
**Link**: [View Original Post](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/solutions/4920054/)

---

```
class Solution:
    def maximumLengthSubstring(self, s: str) -> int:

        lftLst = iter(s)
        ans, left = 0, next(lftLst)
        ctr = defaultdict(int)

        for rght in s: 

            ctr[rght]+= 1

            while ctr[rght] == 3: 
                ctr[left]-= 1
                left = next(lftLst)

            ans = max(ans, sum(ctr.values()))

        return ans
```
[https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/submissions/1212749113/](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/submissions/1212749113/)

I could be wrong, but I think that time complexity is *O*(*N*) and space complexity is *O*(1), in which *N* ~ `len(s)`. 

(5/1/24 edit: Note the code iterates over each character in `s` once, which gives the *O*(*N*) TC. Also, `len(ctr)` is always <= 3, which gives the *O*(1) SC.)

</details>
