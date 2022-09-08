# Write your MySQL query statement below
SELECT score AS "score" , 
       dense_rank() over (order by score desc) AS "rank"
FROM scores ;        
 