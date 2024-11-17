# Write your MySQL query statement below
with t1 as
(
  select requester_id as total_id from RequestAccepted
  union all
  select accepter_id from RequestAccepted
)
select total_id as id,count(total_id) as num
from t1
group by total_id
order by count(total_id) desc
limit 1;