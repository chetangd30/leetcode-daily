# Reverse Nodes in k-Group

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Hard |
| **Language** | python3 |
| **Solved On** | September 2, 2026 |
| **Tags** | Linked List, Recursion |
| **Link** | [View Problem](https://leetcode.com/problems/reverse-nodes-in-k-group/) |
| **Runtime** | 0 ms |
| **Memory** | 19.3 MB |

## Problem Description

<p>Given the <code>head</code> of a linked list, reverse the nodes of the list <code>k</code> at a time, and return <em>the modified list</em>.</p>

<p><code>k</code> is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of <code>k</code> then left-out nodes, in the end, should remain as it is.</p>

<p>You may not alter the values in the list's nodes, only nodes themselves may be changed.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [2,1,4,3,5]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 3
<strong>Output:</strong> [3,2,1,4,5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 5000</code></li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong> Can you solve the problem in <code>O(1)</code> extra memory space?</p>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: python3 easy recursion solution
**Author**: [@hongfu1220](https://leetcode.com/hongfu1220/)
**Upvotes**: 166 👍
**Link**: [View Original Post](https://leetcode.com/problems/reverse-nodes-in-k-group/solutions/718457/)

---

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:        
        # Check if we need to reverse the group
        curr = head
        for _ in range(k):
            if not curr: return head
            curr = curr.next
		        
				
        # Reverse the group (basic way to reverse linked list)
        prev = None
        curr = head
        for _ in range(k):
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        
		
        # After reverse, we know that `head` is the tail of the group.
		# And `curr` is the next pointer in original linked list order
        head.next = self.reverseKGroup(curr, k)
        return prev
    ```

</details>
