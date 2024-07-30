# Write your MySQL query statement below
with new as
(
select num
from MyNumbers
group by num
having count(num)=1
order by num desc
limit 1
)
select if(count(num)=0,null,num) as num
from new;
