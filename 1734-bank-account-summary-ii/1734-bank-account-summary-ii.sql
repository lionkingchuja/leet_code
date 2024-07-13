# Write your MySQL query statement below
select t1.name as NAME,sum(t2.amount) as BALANCE
from Users as t1 join Transactions as t2 on t1.account=t2.account
group by name
having BALANCE >10000;