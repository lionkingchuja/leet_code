# Write your MySQL query statement below
with new as
(
    select *,dense_rank() over(partition by departmentId order by salary desc) as rn
    from employee
)
select t2.name as Department,new.name as Employee,new.salary 
from new join Department as t2 on new.departmentId=t2.id
where rn=1;