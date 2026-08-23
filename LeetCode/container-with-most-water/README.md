# Container With Most Water

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | python3 |
| **Solved On** | August 23, 2026 |
| **Tags** | Array, Two Pointers, Greedy |
| **Link** | [View Problem](https://leetcode.com/problems/container-with-most-water/) |
| **Runtime** | 0 ms |
| **Memory** | 19.4 MB |

## Problem Description

<p>You are given an integer array <code>height</code> of length <code>n</code>. There are <code>n</code> vertical lines drawn such that the two endpoints of the <code>i<sup>th</sup></code> line are <code>(i, 0)</code> and <code>(i, height[i])</code>.</p>

<p>Find two lines that together with the x-axis form a container, such that the container contains the most water.</p>

<p>Return <em>the maximum amount of water a container can store</em>.</p>

<p><strong>Notice</strong> that you may not slant the container.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg" style="width: 600px; height: 287px;">
<pre><strong>Input:</strong> height = [1,8,6,2,5,4,8,3,7]
<strong>Output:</strong> 49
<strong>Explanation:</strong> The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> height = [1,1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>4</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅Best Method 🔥 || C++ || JAVA || PYTHON || Beginner Friendly🔥🔥🔥
**Author**: [@rahulvarma5297](https://leetcode.com/rahulvarma5297/)
**Upvotes**: 1385 👍
**Link**: [View Original Post](https://leetcode.com/problems/container-with-most-water/solutions/3701708/)

---

# Intuition:
The two-pointer technique starts with the widest container and moves the pointers inward based on the comparison of heights. 
Increasing the width of the container can only lead to a larger area if the height of the new boundary is greater. By moving the pointers towards the center, we explore containers with the potential for greater areas.

# Explanation:
1. Initialize the variables:
   - `left` to represent the left pointer, starting at the beginning of the container (index 0).
   - `right` to represent the right pointer, starting at the end of the container (index `height.size() - 1`).
   - `maxArea` to keep track of the maximum area found, initially set to 0.

2. Enter a loop using the condition `left < right`, which means the pointers have not crossed each other yet.

3. Calculate the current area:
   - Use the `min` function to find the minimum height between the `left` and `right` pointers.
   - Multiply the minimum height by the width, which is the difference between the indices of the pointers: `(right - left)`.
   - Store this value in the `currentArea` variable.

4. Update the maximum area:
   - Use the `max` function to compare the `currentArea` with the `maxArea`.
   - If the `currentArea` is greater than the `maxArea`, update `maxArea` with the `currentArea`.

5. Move the pointers inward: (Explained in detail below)
   - Check if the height at the `left` pointer is smaller than the height at the `right` pointer.
   - If so, increment the `left` pointer, moving it towards the center of the container.
   - Otherwise, decrement the `right` pointer, also moving it towards the center.

6. Repeat steps 3 to 5 until the pointers meet (`left >= right`), indicating that all possible containers have been explored.

7. Return the `maxArea`, which represents the maximum area encountered among all the containers.

# Update the maximum area:
The purpose of this condition is to determine which pointer to move inward, either the left pointer (`i`) or the right pointer (`j`), based on the comparison of heights at their respective positions.

Imagine you have two containers represented by the heights at the left and right pointers. The condition checks which container has a smaller height and moves the pointer corresponding to that container.

1. If `height[i] > height[j]`:
   - This means that the height of the left container is greater than the height of the right container.
   - Moving the right pointer (`j`) would not increase the potential area because the height of the right container is the limiting factor.
   - So, to explore containers with the possibility of greater areas, we need to move the right pointer inward by decrementing `j`.

2. If `height[i] <= height[j]`:
   - This means that the height of the left container is less than or equal to the height of the right container.
   - Moving the left pointer (`i`) would not increase the potential area because the height of the left container is the limiting factor.
   - So, to explore containers with the possibility of greater areas, we need to move the left pointer inward by incrementing `i`.

By making these pointer movements, we ensure that we are always exploring containers with the potential for larger areas. The approach is based on the observation that increasing the width of the container can only lead to a larger area if the height of the new boundary is greater.
By following this condition and moving the pointers accordingly, the algorithm explores all possible containers and finds the one with the maximum area.

# Code
```C++ []
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
```
```Java []
class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0;

        while (left < right) {
            int currentArea = Math.min(height[left], height[right]) * (right - left);
            maxArea = Math.max(maxArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
}
```
```Python3 []
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        maxArea = 0

        while left < right:
            currentArea = min(height[left], height[right]) * (right - left)
            maxArea = max(maxArea, currentArea)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return maxArea
```

![CUTE_CAT.png](https://assets.leetcode.com/users/images/159f3912-a0d3-4723-a9d1-3a6a67e1450e_1688150480.977912.png)


**If you found my solution helpful, I would greatly appreciate your upvote, as it would motivate me to continue sharing more solutions.**

</details>
