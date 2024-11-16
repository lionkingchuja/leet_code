#Write your MySQL query statement below
select person_name
from (
select person_name,weight,turn,
sum(weight) over(order by turn) as sm
from Queue
) as sub
where sm <=1000
order by sm desc
limit 1;