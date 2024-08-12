# Write your MySQL query statement below
select t2.contest_id,
round(count(t2.user_id)/(select count(user_id) from Users)*100,2) as percentage
from Users as t1 join Register as t2 on t1.user_id=t2.user_id
group by t2.contest_id
order by percentage desc,contest_id;

