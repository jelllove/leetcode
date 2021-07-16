Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.



其实是一个字符串的操作，就是两个字符串模拟二进制加起来，一开始很容易想到使用bitset，但是bitset最多使用to_ullong，最后会溢出的，所以只能还是使用string进行操作