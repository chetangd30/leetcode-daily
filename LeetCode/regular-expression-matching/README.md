# Regular Expression Matching

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Hard |
| **Language** | python3 |
| **Solved On** | August 20, 2026 |
| **Tags** | String, Dynamic Programming, Recursion |
| **Link** | [View Problem](https://leetcode.com/problems/regular-expression-matching/) |
| **Runtime** | 2 ms |
| **Memory** | 19.4 MB |

## Problem Description

<p>Given an input string <code>s</code>&nbsp;and a pattern <code>p</code>, implement regular expression matching with support for <code>'.'</code> and <code>'*'</code> where:</p>

<ul>
	<li><code>'.'</code> Matches any single character.​​​​</li>
	<li><code>'*'</code> Matches zero or more of the preceding element.</li>
</ul>

<p>Return a boolean indicating whether the matching covers the entire input string (not partial).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aa", p = "a"
<strong>Output:</strong> false
<strong>Explanation:</strong> "a" does not match the entire string "aa".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aa", p = "a*"
<strong>Output:</strong> true
<strong>Explanation:</strong> '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "ab", p = ".*"
<strong>Output:</strong> true
<strong>Explanation:</strong> ".*" means "zero or more (*) of any character (.)".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length&nbsp;&lt;= 20</code></li>
	<li><code>1 &lt;= p.length&nbsp;&lt;= 20</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
	<li><code>p</code> contains only lowercase English letters, <code>'.'</code>, and&nbsp;<code>'*'</code>.</li>
	<li>It is guaranteed for each appearance of the character <code>'*'</code>, there will be a previous valid character to match.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Solution
**Author**: [@deleted_user](https://leetcode.com/deleted_user/)
**Upvotes**: 480 👍
**Link**: [View Original Post](https://leetcode.com/problems/regular-expression-matching/solutions/2976919/)

---

```C++ []
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for(int i=0; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == \'*\'){
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == \'.\') && dp[i-1][j]);
                }
                else{
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == \'.\');
                }
            }
        }
        
        return dp[n][m];
    }
};
```

```Python3 []
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i, j = len(s) - 1, len(p) - 1
        return self.backtrack({}, s, p, i, j)

    def backtrack(self, cache, s, p, i, j):
        key = (i, j)
        if key in cache:
            return cache[key]

        if i == -1 and j == -1:
            cache[key] = True
            return True

        if i != -1 and j == -1:
            cache[key] = False
            return cache[key]

        if i == -1 and p[j] == \'*\':
            k = j
            while k != -1 and p[k] == \'*\':
                k -= 2
            
            if k == -1:
                cache[key] = True
                return cache[key]
            
            cache[key] = False
            return cache[key]
        
        if i == -1 and p[j] != \'*\':
            cache[key] = False
            return cache[key]

        if p[j] == \'*\':
            if self.backtrack(cache, s, p, i, j - 2):
                cache[key] = True
                return cache[key]
            
            if p[j - 1] == s[i] or p[j - 1] == \'.\':
                if self.backtrack(cache, s, p, i - 1, j):
                    cache[key] = True
                    return cache[key]
        
        if p[j] == \'.\' or s[i] == p[j]:
            if self.backtrack(cache, s, p, i - 1, j - 1):
                cache[key] = True
                return cache[key]

        cache[key] = False
        return cache[key]
```

```Java []
enum Result {
    TRUE, FALSE
}

class Solution {
    Result[][] memo;

    public boolean isMatch(String text, String pattern) {
        memo = new Result[text.length() + 1][pattern.length() + 1];
        return dp(0, 0, text, pattern);
    }

    public boolean dp(int i, int j, String text, String pattern) {
        if (memo[i][j] != null) {
            return memo[i][j] == Result.TRUE;
        }
        boolean ans;
        if (j == pattern.length()){
            ans = i == text.length();
        } else{
            boolean first_match = (i < text.length() &&
                                   (pattern.charAt(j) == text.charAt(i) ||
                                    pattern.charAt(j) == \'.\'));

            if (j + 1 < pattern.length() && pattern.charAt(j+1) == \'*\'){
                ans = (dp(i, j+2, text, pattern) ||
                       first_match && dp(i+1, j, text, pattern));
            } else {
                ans = first_match && dp(i+1, j+1, text, pattern);
            }
        }
        memo[i][j] = ans ? Result.TRUE : Result.FALSE;
        return ans;
    }
}
```


</details>
