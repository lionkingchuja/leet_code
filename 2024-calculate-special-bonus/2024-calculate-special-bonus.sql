# Write your MySQL query statement below
select employee_id,
case when employee_id % 2=0 then 0 
     when name like 'M%' then 0 
     when employee_id %2 !=0 then salary
end as bonus
from Employees
order by employee_id;