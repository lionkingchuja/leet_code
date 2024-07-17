# Write your MySQL query statement below
with new as
(
select t1.user_id,action,count(t2.action) as total_cnt,
sum(case when action='confirmed' then 1 else 0 end) as cnt
from Signups as t1 left join Confirmations as t2 on t1.user_id=t2.user_id
group by t1.user_id
)

select user_id,COALESCE(ROUND(cnt / total_cnt, 2), 0) as confirmation_rate
from new;
