/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both arrays ).

The overall run time complexity should be O(log (m+n)).

NOTE: If the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 


Problem Constraints
0 <= |A| <= 106
0 <= |B| <= 106
1 <= |A| + |B| <= 2 * 106


Output Format
Return a double value equal to the median.


Example Input
A : [1 4 5]
B : [2 3]


Example Output
3


Example Explanation
Merged A and B will be : [1, 2, 3, 4, 5]
Its median will be 3
*/