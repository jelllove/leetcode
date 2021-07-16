Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Example 3:

Input: digits = [0]
Output: [1]



其实就是让你模拟加对一个数组进行加1的操作，这里因为是1，2，3的顺序，所以如果正常的想法可能就是从digits.size() - 1开始，一直到0为值，其实也可以把它反转一下，然后再算完之后再反转回来