# Generate Parentheses

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | python3 |
| **Solved On** | September 1, 2026 |
| **Tags** | String, Dynamic Programming, Backtracking, Bracket Sequences |
| **Link** | [View Problem](https://leetcode.com/problems/generate-parentheses/) |
| **Runtime** | 0 ms |
| **Memory** | 19.2 MB |

## Problem Description

<p>Given <code>n</code> pairs of parentheses, write a function to <em>generate all combinations of well-formed parentheses</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> ["((()))","(()())","(())()","()(())","()()()"]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> ["()"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Python, Java w/ Explanation | Faster than 96% w/ Proof | Easy to Understand
**Author**: [@IdealYuvi](https://leetcode.com/IdealYuvi/)
**Upvotes**: 1948 👍
**Link**: [View Original Post](https://leetcode.com/problems/generate-parentheses/solutions/2542620/)

---

1. The idea is to add `\')\'` only after valid `\'(\'`
2. We use two integer variables `left` & `right` to see how many `\'(\'` & `\')\'` are in the current string
3. If `left < n` then we can add `\'(\'` to the current string
4. If `right < left` then we can add `\')\'` to the current string

**Python Code:**
```
def generateParenthesis(self, n: int) -> List[str]:
	def dfs(left, right, s):
		if len(s) == n * 2:
			res.append(s)
			return 

		if left < n:
			dfs(left + 1, right, s + \'(\')

		if right < left:
			dfs(left, right + 1, s + \')\')

	res = []
	dfs(0, 0, \'\')
	return res
```

For` n = 2`, the recursion tree will be something like this,
```
								   	(0, 0, \'\')
								 	    |	
									(1, 0, \'(\')  
								   /           \\
							(2, 0, \'((\')      (1, 1, \'()\')
							   /                 \\
						(2, 1, \'(()\')           (2, 1, \'()(\')
						   /                       \\
					(2, 2, \'(())\')                (2, 2, \'()()\')
						      |	                             |
					res.append(\'(())\')             res.append(\'()()\')
   
```

**Java Code:**
```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        recurse(res, 0, 0, "", n);
        return res;
    }
    
    public void recurse(List<String> res, int left, int right, String s, int n) {
        if (s.length() == n * 2) {
            res.add(s);
            return;
        }
        
        if (left < n) {
            recurse(res, left + 1, right, s + "(", n);
        }
        
        if (right < left) {
            recurse(res, left, right + 1, s + ")", n);
        }
    }
	// See above tree diagram with parameters (left, right, s) for better understanding
}
```
![image](https://assets.leetcode.com/users/images/7df8c537-35e6-42a5-8b91-e2f6ec9031d0_1662519743.7174962.png)


![image](https://assets.leetcode.com/users/images/227fc269-7b54-4e64-b490-66e6154a40cd_1662518370.2619233.png)





</details>
