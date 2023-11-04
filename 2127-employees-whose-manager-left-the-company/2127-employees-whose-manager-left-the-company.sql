select employee_id
from Employees as t
where t.salary < 30000 and t.manager_id not in(
  select employee_id from Employees
)
order by employee_id;