# Write your MySQL query statement below
select  t1.user_id,round(avg(if(t2.action='confirmed',1,0)),2) as confirmation_rate
from Signups as t1 
left join Confirmations as t2
ON t1.user_id=t2.user_id
group by t1.user_id;
# having t2.action='confirmed';
#where count(t2.action='confirmed') or count(t2.action='timeout');