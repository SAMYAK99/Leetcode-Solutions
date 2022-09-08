# Write your MySQL query statement below
/*
Use self join to compare 2 id FROM ID ANF ID+1
*/

SELECT DISTINCT l1.num AS ConsecutiveNums FROM logs l1
JOIN logs l2 on l1.id = l2.id+1 AND l1.num = l2.num
JOIN logs l3 on l1.id = l3.id+2 AND l1.num = l3.num ; 
