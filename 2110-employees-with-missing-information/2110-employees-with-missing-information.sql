# Write your MySQL query statement below

    select t1.employee_id
    from Employees as t1 left join Salaries as t2 
    on t1.employee_id=t2.employee_id
    where t1.name is null or t2.salary is null
    union 
    select t2.employee_id
    from Employees as t1 right join Salaries as t2
    on t1.employee_id=t2.employee_id
    where t1.name is null or t2.salary is null
    order by employee_id;

