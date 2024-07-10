# Write your MySQL query statement below
with new as
(
    select *,row_number() over() as rn
    from Stadium where people >=100
),
new1 as
(
    select *,id-rn as diff from new
),
new2 as
(
    select *,count(diff) over(partition by diff) as cnt
    from new1 
)
select id,visit_date,people 
from new2
where cnt >=3
order by visit_date asc;
