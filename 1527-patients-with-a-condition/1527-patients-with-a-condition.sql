# Write your MySQL query statement below

/*
Looping across multiple values : 
'DIAB1%' : Start with DIAB1
' %DIAB1' : Second letter can also start with DIAB1
*/

SELECT *
FROM Patients
where conditions like 'DIAB1%' OR conditions like '% DIAB1%'
; 