# Write your MySQL query statement below
select t1.name,IF(sum(t2.distance)is NULL,0,sum(t2.distance)) as travelled_distance
from Rides as t2 right join Users as t1
on t1.id=t2.user_id
group by t2.user_id
order by travelled_distance desc,t1.name;
