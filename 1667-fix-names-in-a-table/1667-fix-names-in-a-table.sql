# Write your MySQL query statement below

# The CONCAT(string_1, string_2, ... string_n) function joins all the string.
# The UPPER() function converts a string to upper-case.
# The LOWER() function converts a string to lower-case.
# The SUBSTR(stirng, position, length) function return substring of specified length from specified position.

SELECT user_id , 
CONCAT(UPPER(SUBSTR(name,1,1)) , LOWER(SUBSTR(name,2))) As name
FROM Users
ORDER BY user_id ;
