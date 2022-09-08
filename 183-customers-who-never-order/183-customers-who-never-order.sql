# Write your MySQL query statement below

SELECT cc.name AS Customers FROM Customers cc
LEFT JOIN    orders oo On  cc.id =oo.customerID  
WHERE oo.customerId is NULL ; 