# Write your MySQL query statement below
select query_name, 
round(sum(rating/position)/count(result),2) as quality,
round(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END)/count(result)*100,2) as poor_query_percentage
from Queries
where query_name is not NULL
group by query_name;