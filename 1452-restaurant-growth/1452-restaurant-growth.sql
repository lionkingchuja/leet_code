# Write your MySQL query statement below
with t1 as
(select visited_on,sum(amount) as total_amount
from Customer 
group by visited_on
),
t2 as(
  select visited_on,sum(total_amount) over(order by visited_on 
  rows between 6 preceding and current row) as amount,
  round(avg(total_amount) over(order by visited_on 
  rows between 6 preceding and current row),2) as average_amount
  from t1
)
select * from t2
where visited_on >=(select visited_on from t2 limit 1)+ 6;