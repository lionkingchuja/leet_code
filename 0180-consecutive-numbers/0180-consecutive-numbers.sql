# Write your MySQL query statement below
select distinct t1.num as ConsecutiveNums
from Logs as t1 join Logs as t2 on t1.id=t2.id + 1
join logs as t3 on t1.id=t3.id+2
where t1.num=t2.num and t2.num=t3.num;