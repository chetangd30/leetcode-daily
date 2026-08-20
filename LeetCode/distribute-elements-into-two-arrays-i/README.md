# Distribute Elements Into Two Arrays I

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | python3 |
| **Solved On** | August 20, 2026 |
| **Tags** | Array, Simulation |
| **Link** | [View Problem](https://leetcode.com/problems/distribute-elements-into-two-arrays-i/) |
| **Runtime** | 0 ms |
| **Memory** | 19.2 MB |

## Problem Description

<p>You are given a <strong>1-indexed</strong> array of <strong>distinct</strong> integers <code>nums</code> of length <code>n</code>.</p>

<p>You need to distribute all the elements of <code>nums</code> between two arrays <code>arr1</code> and <code>arr2</code> using <code>n</code> operations. In the first operation, append <code>nums[1]</code> to <code>arr1</code>. In the second operation, append <code>nums[2]</code> to <code>arr2</code>. Afterwards, in the <code>i<sup>th</sup></code> operation:</p>

<ul>
	<li>If the last element of <code>arr1</code> is<strong> greater</strong> than the last element of <code>arr2</code>, append <code>nums[i]</code> to <code>arr1</code>. Otherwise, append <code>nums[i]</code> to <code>arr2</code>.</li>
</ul>

<p>The array <code>result</code> is formed by concatenating the arrays <code>arr1</code> and <code>arr2</code>. For example, if <code>arr1 == [1,2,3]</code> and <code>arr2 == [4,5,6]</code>, then <code>result = [1,2,3,4,5,6]</code>.</p>

<p>Return <em>the array</em> <code>result</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,3]
<strong>Output:</strong> [2,3,1]
<strong>Explanation:</strong> After the first 2 operations, arr1 = [2] and arr2 = [1].
In the 3<sup>rd</sup> operation, as the last element of arr1 is greater than the last element of arr2 (2 &gt; 1), append nums[3] to arr1.
After 3 operations, arr1 = [2,3] and arr2 = [1].
Hence, the array result formed by concatenation is [2,3,1].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,4,3,8]
<strong>Output:</strong> [5,3,4,8]
<strong>Explanation:</strong> After the first 2 operations, arr1 = [5] and arr2 = [4].
In the 3<sup>rd</sup> operation, as the last element of arr1 is greater than the last element of arr2 (5 &gt; 4), append nums[3] to arr1, hence arr1 becomes [5,3].
In the 4<sup>th</sup> operation, as the last element of arr2 is greater than the last element of arr1 (4 &gt; 3), append nums[4] to arr2, hence arr2 becomes [4,8].
After 4 operations, arr1 = [5,3] and arr2 = [4,8].
Hence, the array result formed by concatenation is [5,3,4,8].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li>All elements in <code>nums</code> are distinct.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Easy Video Solution for beginners 🔥 || C++ JAVA PYTHON
**Author**: [@ayushnemmaniwar12](https://leetcode.com/ayushnemmaniwar12/)
**Upvotes**: 16 👍
**Link**: [View Original Post](https://leetcode.com/problems/distribute-elements-into-two-arrays-i/solutions/4813919/)

---

# ***Easy Video Explanation***

https://youtu.be/Rj8s8mTJLAA





# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
    O(N)
    

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
    O(N)
    

# Code


```C++ []
class Solution {
public:
    vector<int> resultArray(vector<int>& v) {
        int n=v.size();
        vector<int>ans;
        vector<int>v1,v2;
        v1.push_back(v[0]);
        v2.push_back(v[1]);
        for(int i=2;i<n;i++) {
            if(v1.back()>v2.back())
                v1.push_back(v[i]);
            else
                v2.push_back(v[i]);
        }
        ans=v1;
        for(auto i:v2)
            ans.push_back(i);
        return ans;
    }
};
```
```python []
from typing import List

class Solution:
    def resultArray(self, v: List[int]) -> List[int]:
        n = len(v)
        ans = []
        v1 = [v[0]]
        v2 = [v[1]]
        for i in range(2, n):
            if v1[-1] > v2[-1]:
                v1.append(v[i])
            else:
                v2.append(v[i])
        ans.extend(v1)
        ans.extend(v2)
        return ans

```
```Java []
import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<Integer> resultArray(List<Integer> v) {
        int n = v.size();
        List<Integer> ans = new ArrayList<>();
        List<Integer> v1 = new ArrayList<>();
        List<Integer> v2 = new ArrayList<>();
        v1.add(v.get(0));
        v2.add(v.get(1));
        for (int i = 2; i < n; i++) {
            if (v1.get(v1.size() - 1) > v2.get(v2.size() - 1))
                v1.add(v.get(i));
            else
                v2.add(v.get(i));
        }
        ans.addAll(v1);
        ans.addAll(v2);
        return ans;
    }
}


```

# ***If you like the solution Please Upvote and subscribe to my youtube channel***
***It Motivates me to record more videos***

*Thank you* \uD83D\uDE00

</details>
