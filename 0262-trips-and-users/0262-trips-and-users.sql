# Write your MySQL query statement below
with new as(
select t1.request_at as Day,
count(status) as total,
count(IF(status!='completed',1,NULL))as cnt
from Trips as t1 
join Users as t2 on t1.client_id=t2.users_id 
join users as t3 on t1.driver_id=t3.users_id
where t2.banned='No' and t3.banned='No'
and t1.request_at BETWEEN '2013-10-01' AND '2013-10-03'
group by t1.request_at
)

select Day,round((cnt/total),2) as 'Cancellation Rate'
from new;
