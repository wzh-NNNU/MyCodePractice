// 测试链接 : https://leetcode.cn/problems/sort-an-array/
// 此时不要求掌握，因为这些排序后续的课都会讲到的
// 这里只是想说明代码语言的转换并不困难
// 整个系列虽然都是java讲的，但使用不同语言的同学听懂思路之后，想理解代码真的不是问题
// 语言问题并不是学习算法的障碍，有了人工智能工具之后，就更不是障碍了
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50001;
int help[MAXN];
int first, last;

class Solution {
public:
	void sortArray(int nums[], int n) {
		if (n > 1) {
			mergeSort(nums, n);
		}
	}

	// 以下是归并排序
	void mergeSort(int nums[], int n) {
		for (int l, m, r, step = 1; step < n; step <<= 1) {
			l = 0;
			while (l < n) {
				m = l + step - 1;
				if (m + 1 >= n) {
					break;
				}
				r = min(l + (step << 1) - 1, n - 1);
				merge(nums, l, m, r);
				l = r + 1;
			}
		}
	}

	void merge(int nums[], int l, int m, int r) {
		int p1 = l;
		int p2 = m + 1;
		int i = l;
		while (p1 <= m && p2 <= r) {
			help[i++] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];
		}
		while (p1 <= m) {
			help[i++] = nums[p1++];
		}
		while (p2 <= r) {
			help[i++] = nums[p2++];
		}
		for (i = l; i <= r; i++) {
			nums[i] = help[i];
		}
	}

	// 以下是随机快速排序
	void quickSort(int nums[], int n) {
		sort(nums, 0, n - 1);
	}

	void sort(int nums[], int l, int r) {
		if (l >= r) {
			return;
		}
		// 随机这一下，常数时间比较大
		// 但只有这一下随机，才能在概率上把快速排序的时间复杂度收敛到O(n * logn)
		int x = nums[l + rand() % (r - l + 1)];
		partition(nums, l, r, x);
		int left = first;
		int right = last;
		sort(nums, l, left - 1);
		sort(nums, right + 1, r);
	}

	void partition(int nums[], int l, int r, int x) {
		first = l;
		last = r;
		int i = l;
		while (i <= last) {
			if (nums[i] == x) {
				i++;
			} else if (nums[i] < x) {
				swap(nums, first++, i++);
			} else {
				swap(nums, i, last--);
			}
		}
	}

	void swap(int nums[], int i, int j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

	// 以下是堆排序
	void heapSort(int nums[], int n) {
		for (int i = n - 1; i >= 0; i--) {
			heapify(nums, i, n);
		}
		while (n > 1) {
			swap(nums, 0, --n);
			heapify(nums, 0, n);
		}
	}

	// 这个方法虽然堆排序用不上，但是堆结构里是重要方法，所以这里保留
	// 后面的课会讲
	void heapInsert(int nums[], int i) {
		while (nums[i] > nums[(i - 1) / 2]) {
			swap(nums, i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
	}

	void heapify(int nums[], int i, int s) {
		int l = i * 2 + 1;
		while (l < s) {
			int best = l + 1 < s && nums[l + 1] > nums[l] ? l + 1 : l;
			best = nums[best] > nums[i] ? best : i;
			if (best == i) {
				break;
			}
			swap(nums, best, i);
			i = best;
			l = i * 2 + 1;
		}
	}
};

int main() {
	srand(time(0));
	Solution sol;
	int nums[] = {5, 2, 3, 1};
	int n = sizeof(nums) / sizeof(nums[0]);
	sol.sortArray(nums, n);
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << nums[i];
	}
	cout << endl;
	return 0;
}
