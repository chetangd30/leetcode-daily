# Merge k Sorted Lists

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Hard |
| **Language** | python3 |
| **Solved On** | September 1, 2026 |
| **Tags** | Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort, Tournament Sort |
| **Link** | [View Problem](https://leetcode.com/problems/merge-k-sorted-lists/) |
| **Runtime** | 3 ms |
| **Memory** | 19.5 MB |

## Problem Description

<p>You are given an array of <code>k</code> linked-lists <code>lists</code>, each linked-list is sorted in ascending order.</p>

<p><em>Merge all the linked-lists into one sorted linked-list and return it.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> lists = [[1,4,5],[1,3,4],[2,6]]
<strong>Output:</strong> [1,1,2,3,4,4,5,6]
<strong>Explanation:</strong> The linked-lists are:
[
  1-&gt;4-&gt;5,
  1-&gt;3-&gt;4,
  2-&gt;6
]
merging them into one sorted linked list:
1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> lists = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> lists = [[]]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>k == lists.length</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= lists[i].length &lt;= 500</code></li>
	<li><code>-10<sup>4</sup> &lt;= lists[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>lists[i]</code> is sorted in <strong>ascending order</strong>.</li>
	<li>The sum of <code>lists[i].length</code> will not exceed <code>10<sup>4</sup></code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Problems with Python3 and Multiple Solutions
**Author**: [@batman_005](https://leetcode.com/batman_005/)
**Upvotes**: 196 👍
**Link**: [View Original Post](https://leetcode.com/problems/merge-k-sorted-lists/solutions/465094/)

---

**Python 2 Solution:**
```
def mergeKLists_Python2(self, lists):
	h = []
	head = tail = ListNode(0)
	for i in lists:
		if i:
			heapq.heappush(h, (i.val, i))

	while h:
		node = heapq.heappop(h)[1]
		tail.next = node
		tail = tail.next
		if node.next:
			heapq.heappush(h, (node.next.val, node.next))

	return head.next
```

**Python 3:** 
The above solution works fine with Python 2.However, with Python3 it gives Type Error:
TypeError: \'<\' not supported between instances of \'ListNode\' and \'ListNode\'
**This error occurs because the cmp() special method is no longer honored in Python 3**

Here are the two ways we can solve this problem:
**a) Implement eq, lt methods** 
	
One of the solution would be to provide `__eq__ and __lt__` method implementation to `ListNode` class
```
def mergeKLists_Python3(self, lists):
	ListNode.__eq__ = lambda self, other: self.val == other.val
	ListNode.__lt__ = lambda self, other: self.val < other.val
	h = []
	head = tail = ListNode(0)
	for i in lists:
		if i:
			heapq.heappush(h, (i.val, i))

	while h:
		node = heapq.heappop(h)[1]
		tail.next = node
		tail = tail.next
		if node.next:
			heapq.heappush(h, (node.next.val, node.next))

	return head.next
```

**b) Fix heapq** 

The problem while adding `ListNode` objects as tasks is that the Tuple comparison breaks for (priority, task) pairs if the priorities are equal and the tasks do not have a default comparison order. The solution is to store entries as 3-element list including the priority, an entry count, and the task.
The entry count serves as a tie-breaker so that two tasks with the same priority are returned in the order they were added.
And since no two entry counts are the same, the tuple comparison will never attempt to directly compare two tasks.

```
def mergeKLists_heapq(self, lists):
	h = []
	head = tail = ListNode(0)
	for i in range(len(lists)):
		heapq.heappush(h, (lists[i].val, i, lists[i]))

	while h:
		node = heapq.heappop(h)
		node = node[2]
		tail.next = node
		tail = tail.next
		if node.next:
			i+=1
			heapq.heappush(h, (node.next.val, i, node.next))

	return head.next
```
	

</details>
