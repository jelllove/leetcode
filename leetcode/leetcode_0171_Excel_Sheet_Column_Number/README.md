Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
Example 4:

Input: columnTitle = "FXSHRXW"
Output: 2147483647
 

Constraints:

1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].



题目比较简单，就是把一个用字母表示的26进制的字符串，转成一个INT，就行了。
所以只要找到一位后，转成对应的数字，然后把之前的结果乘上26, 再加上就可以了。
这里唯一的问题，就是它有没有可能会溢出，超过INT_MAX，如果会的话，就要在加和乘之前做一个判断。

但是题目最后看上去是做了限制了，所以解题的过程中，是不需要进行判断的。
