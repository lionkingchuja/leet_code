# Write your MySQL query statement below
WITH new AS (
    SELECT *,
           rank() OVER (PARTITION BY product_id ORDER BY year) AS rnk
    FROM Sales
)
SELECT t1.product_id, t1.year AS first_year, t1.quantity, t1.price
FROM new AS t1
WHERE t1.rnk = 1;



-- select t1.product_id,t1.year as first_year,t1.quantity,t1.price
-- from Sales as t1 left join Product as t2 on t1.product_id=t2.product_id
-- where (t1.product_id,t1.year) in 
-- (
--     select product_id,min(year)
--     from Sales
--     group by product_id
-- );
