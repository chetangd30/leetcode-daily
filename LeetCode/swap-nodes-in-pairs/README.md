# Swap Nodes in Pairs

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | python3 |
| **Solved On** | September 2, 2026 |
| **Tags** | Linked List, Recursion |
| **Link** | [View Problem](https://leetcode.com/problems/swap-nodes-in-pairs/) |
| **Runtime** | 0 ms |
| **Memory** | 19.2 MB |

## Problem Description

<p>Given a&nbsp;linked list, swap every two adjacent nodes and return its head. You must solve the problem without&nbsp;modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">head = [1,2,3,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,1,4,3]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg" style="width: 422px; height: 222px;"></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">head = []</span></p>

<p><strong>Output:</strong> <span class="example-io">[]</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">head = [1]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1]</span></p>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">head = [1,2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,1,3]</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the&nbsp;list&nbsp;is in the range <code>[0, 100]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✔️ [Python3] I HATE LINKED LISTS, щ（ﾟДﾟщ）, Not Explained
**Author**: [@artod](https://leetcode.com/artod/)
**Upvotes**: 183 👍
**Link**: [View Original Post](https://leetcode.com/problems/swap-nodes-in-pairs/solutions/1774318/)

---

**UPVOTE if you like (\uD83C\uDF38-_-\'), If you have any question, feel free to ask.**

Just a bunch of placeholders, edge cases, and strange errors about a cycle meanwhile :(

prev cur cur porev next cur prev pasdfaslfjgnzdsf;ljgfsdaz;lkjkfgn

Time: **O(n)** - iterate
Space: **O(1)**

```
def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
	if not head: return head

	prev, cur, ans = None, head, head.next
	while cur and cur.next:
		adj = cur.next
		if prev: prev.next = adj

		cur.next, adj.next = adj.next, cur
		prev, cur = cur, cur.next

	return ans or head
```

**UPVOTE if you like (\uD83C\uDF38-_-\'), If you have any question, feel free to ask.**

</details>
