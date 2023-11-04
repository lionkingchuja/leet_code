# Write your MySQL query statement below
(select t1.name as results
from Users as t1 join MovieRating as t2
on t1.user_id=t2.user_id
group by t2.user_id
order by count(t2.user_id) desc,t1.name
limit 1)
union all
(select t1.title as results
from Movies as t1 join MovieRating as t2
on t1.movie_id=t2.movie_id
where t2.created_at BETWEEN '2020-02-01' AND '2020-02-29'
group by t1.movie_id
having avg(t2.rating)
order by avg(t2.rating) desc,t1.title
limit 1)