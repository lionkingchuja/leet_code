# Write your MySQL query statement below
select t1.project_id,
round(sum(t2.experience_years)/count(t1.employee_id),2) as average_years
from Project as t1 join Employee as t2 on t1.employee_id=t2.employee_id
group by t1.project_id; 