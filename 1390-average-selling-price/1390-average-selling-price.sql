# Write your MySQL query statement below
select t1.product_id,ifnull(round(sum(t1.price * t2.units)/sum(t2.units),2),0)as average_price
from Prices as t1 left join UnitsSold as t2 
on t1.product_id=t2.product_id AND t2.purchase_date BETWEEN t1.start_date AND t1.end_date
group by t1.product_id;