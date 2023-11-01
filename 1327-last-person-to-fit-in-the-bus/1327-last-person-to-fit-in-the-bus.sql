# Write your MySQL query statement below
select x.person_name
from(
select Turn,person_Id,person_name,Weight,sum(Weight) over(order by turn) as Total
from Queue) as x
where x.Total <=1000
order by x.Total desc
limit 1;