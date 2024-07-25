# Write your MySQL query statement below
-- with new as
-- (
-- select *,
-- row_number() over (partition by product_id order by year) as rnk
-- from Sales
-- )
-- select * from new;
-- select t1.product_id,t1.year as first_year,t1.quantity,t1.price
-- from new as t1 inner join Product as t2 on t1.product_id=t2.product_id
-- where t1.rnk=1;

select t1.product_id,t1.year as first_year,t1.quantity,t1.price
from Sales as t1 left join Product as t2 on t1.product_id=t2.product_id
where (t1.product_id,t1.year) in 
(
    select product_id,min(year)
    from Sales
    group by product_id
);
