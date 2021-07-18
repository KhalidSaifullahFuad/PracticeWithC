# Anti-Lychrel Numbers 

An anti-Lychrel number is a number that forms a palindrome through the iterative process of repeatedly reversing its digits and adding the resulting numbers. For example, 56 becomes palindromic after one iteration: 56+65=121. If the number doesn't become palindromic after 30 iterations, then it is not an anti-Lychrel number.

**Examples:**

**Input:** 12 </br>
**Output:** true (12 + 21 = 33, a palindrome)

**Input:** 57 </br>
**Output:** true (57 + 75 = 132, 132 + 231 = 363, a palindrome)

**Input:** 10911 </br>
**Output:** false (10911 takes 55 iterations to reach a palindrome)
