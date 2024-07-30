# Write your MySQL query statement below
with new as
(
select *,
lag(temperature,1) over(order by recordDate) as prev_temp,
lag(recordDate,1) over(order by recordDate) as prev_date
from Weather
)

select id
from new
where prev_temp < temperature and datediff(recordDate,prev_date)=1;
