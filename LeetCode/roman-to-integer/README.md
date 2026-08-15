# Roman to Integer

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | python3 |
| **Solved On** | August 15, 2026 |
| **Tags** | Hash Table, Math, String |
| **Link** | [View Problem](https://leetcode.com/problems/roman-to-integer/) |
| **Runtime** | 0 ms |
| **Memory** | 19.2 MB |

## Problem Description

<p>Roman numerals are represented by seven different symbols:&nbsp;<code>I</code>, <code>V</code>, <code>X</code>, <code>L</code>, <code>C</code>, <code>D</code> and <code>M</code>.</p>

<pre><strong>Symbol</strong>       <strong>Value</strong>
I             1
V             5
X             10
L             50
C             100
D             500
M             1000</pre>

<p>For example,&nbsp;<code>2</code> is written as <code>II</code>&nbsp;in Roman numeral, just two ones added together. <code>12</code> is written as&nbsp;<code>XII</code>, which is simply <code>X + II</code>. The number <code>27</code> is written as <code>XXVII</code>, which is <code>XX + V + II</code>.</p>

<p>Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not <code>IIII</code>. Instead, the number four is written as <code>IV</code>. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as <code>IX</code>. There are six instances where subtraction is used:</p>

<ul>
	<li><code>I</code> can be placed before <code>V</code> (5) and <code>X</code> (10) to make 4 and 9.&nbsp;</li>
	<li><code>X</code> can be placed before <code>L</code> (50) and <code>C</code> (100) to make 40 and 90.&nbsp;</li>
	<li><code>C</code> can be placed before <code>D</code> (500) and <code>M</code> (1000) to make 400 and 900.</li>
</ul>

<p>Given a roman numeral, convert it to an integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "III"
<strong>Output:</strong> 3
<strong>Explanation:</strong> III = 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "LVIII"
<strong>Output:</strong> 58
<strong>Explanation:</strong> L = 50, V= 5, III = 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "MCMXCIV"
<strong>Output:</strong> 1994
<strong>Explanation:</strong> M = 1000, CM = 900, XC = 90 and IV = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 15</code></li>
	<li><code>s</code> contains only&nbsp;the characters <code>('I', 'V', 'X', 'L', 'C', 'D', 'M')</code>.</li>
	<li>It is <strong>guaranteed</strong>&nbsp;that <code>s</code> is a valid roman numeral in the range <code>[1, 3999]</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅Best Method || C++ || JAVA || PYTHON || Beginner Friendly🔥🔥🔥
**Author**: [@rahulvarma5297](https://leetcode.com/rahulvarma5297/)
**Upvotes**: 3076 👍
**Link**: [View Original Post](https://leetcode.com/problems/roman-to-integer/solutions/3651672/)

---

**Certainly! Let\'s break down the code and provide a clear intuition and explanation, using the examples "IX" and "XI" to demonstrate its functionality.**

# Intuition:
The key intuition lies in the fact that in Roman numerals, when a smaller value appears before a larger value, it represents subtraction, while when a smaller value appears after or equal to a larger value, it represents addition.

# Explanation:

1. The unordered map `m` is created and initialized with mappings between Roman numeral characters and their corresponding integer values. For example, \'I\' is mapped to 1, \'V\' to 5, \'X\' to 10, and so on.
2. The variable `ans` is initialized to 0. This variable will accumulate the final integer value of the Roman numeral string.
3. The for loop iterates over each character in the input string `s`.
   **For the example "IX":**
   
     - When `i` is 0, the current character `s[i]` is \'I\'. Since there is a next character (\'X\'), and the value of \'I\' (1) is less than the value of \'X\' (10), the condition `m[s[i]] < m[s[i+1]]` is true. In this case, we subtract the value of the current character from `ans`.
     
       `ans -= m[s[i]];`
       `ans -= m[\'I\'];`
       `ans -= 1;`
       `ans` becomes -1.
     
     - When `i` is 1, the current character `s[i]` is \'X\'. This is the last character in the string, so there is no next character to compare. Since there is no next character, we don\'t need to evaluate the condition. In this case, we add the value of the current character to `ans`.
     
       `ans += m[s[i]];`
       `ans += m[\'X\'];`
       `ans += 10;`
       `ans` becomes 9.
       
   **For the example "XI":**
   
     - When `i` is 0, the current character `s[i]` is \'X\'. Since there is a next character (\'I\'), and the value of \'X\' (10) is greater than the value of \'I\' (1), the condition `m[s[i]] < m[s[i+1]]` is false. In this case, we add the value of the current character to `ans`.
     
       `ans += m[s[i]];`
       `ans += m[\'X\'];`
       `ans += 10;`
       `ans` becomes 10.
     
     - When `i` is 1, the current character `s[i]` is \'I\'. This is the last character in the string, so there is no next character to compare. Since there is no next character, we don\'t need to evaluate the condition. In this case, we add the value of the current character to `ans`.
     
       `ans += m[s[i]];`
       `ans += m[\'I\'];`
       `ans += 1;`
       `ans` becomes 11.

4. After the for loop, the accumulated value in `ans` represents the integer conversion of the Roman numeral string, and it is returned as the result.

# Code
```C++ []
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        
        m[\'I\'] = 1;
        m[\'V\'] = 5;
        m[\'X\'] = 10;
        m[\'L\'] = 50;
        m[\'C\'] = 100;
        m[\'D\'] = 500;
        m[\'M\'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }
};
```
```Java []
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> m = new HashMap<>();
        
        m.put(\'I\', 1);
        m.put(\'V\', 5);
        m.put(\'X\', 10);
        m.put(\'L\', 50);
        m.put(\'C\', 100);
        m.put(\'D\', 500);
        m.put(\'M\', 1000);
        
        int ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && m.get(s.charAt(i)) < m.get(s.charAt(i + 1))) {
                ans -= m.get(s.charAt(i));
            } else {
                ans += m.get(s.charAt(i));
            }
        }
        
        return ans;
    }
}

```
```Python3 []
class Solution:
    def romanToInt(self, s: str) -> int:
        m = {
            \'I\': 1,
            \'V\': 5,
            \'X\': 10,
            \'L\': 50,
            \'C\': 100,
            \'D\': 500,
            \'M\': 1000
        }
        
        ans = 0
        
        for i in range(len(s)):
            if i < len(s) - 1 and m[s[i]] < m[s[i+1]]:
                ans -= m[s[i]]
            else:
                ans += m[s[i]]
        
        return ans
```
![CUTE_CAT.png](https://assets.leetcode.com/users/images/54624a63-8635-4039-b17e-344ebb2a19d9_1687076744.9965477.png)

**If you are a beginner solve these problems which makes concepts clear for future coding:**
1. [Two Sum](https://leetcode.com/problems/two-sum/solutions/3619262/3-method-s-c-java-python-beginner-friendly/)
2. [Roman to Integer](https://leetcode.com/problems/roman-to-integer/solutions/3651672/best-method-c-java-python-beginner-friendly/)
3. [Palindrome Number](https://leetcode.com/problems/palindrome-number/solutions/3651712/2-method-s-c-java-python-beginner-friendly/)
4. [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/solutions/3666304/beats-100-c-java-python-beginner-friendly/)
5. [Remove Element](https://leetcode.com/problems/remove-element/solutions/3670940/best-100-c-java-python-beginner-friendly/)
6. [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/solutions/3672475/4-method-s-c-java-python-beginner-friendly/)
7. [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/solutions/3675747/beats-100-c-java-python-beginner-friendly/)
8. [Majority Element](https://leetcode.com/problems/majority-element/solutions/3676530/3-methods-beats-100-c-java-python-beginner-friendly/)
9. [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/solutions/3676877/best-method-100-c-java-python-beginner-friendly/)
10. **Practice them in a row for better understanding and please Upvote for more questions.**


**If you found my solution helpful, I would greatly appreciate your upvote, as it would motivate me to continue sharing more solutions.**



</details>
