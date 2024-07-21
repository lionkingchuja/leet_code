with new as
(
Select *,datediff(event_date,Lag(event_date,1) Over(Partition By player_id Order By event_date)) as 'day_difference',
ROW_NUMBER() OVER(Partition By player_id Order By event_date) as first_log
From Activity
)
select round(sum(case when day_difference=1  and first_log=2 then 1 else 0 end)/count(distinct player_id),2)
as fraction
from new;