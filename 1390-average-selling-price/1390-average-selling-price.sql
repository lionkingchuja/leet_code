# Write your MySQL query statement below
select t1.product_id,coalesce(round(sum(t1.price*t2.units)/sum(t2.units),2),0) as average_price
from Prices as t1 left join UnitsSold as t2 on t1.product_id=t2.product_id 
and t2.purchase_date between t1.start_date and t1.end_date
group by t1.product_id;

