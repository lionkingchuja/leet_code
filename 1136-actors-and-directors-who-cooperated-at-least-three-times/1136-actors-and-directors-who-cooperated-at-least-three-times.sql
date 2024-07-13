# Write your MySQL query statement below
with new as(
select actor_id,director_id,count(timestamp) as cnt
from ActorDirector
group by actor_id,director_id
having cnt >=3
)
select actor_id,director_id from new;
