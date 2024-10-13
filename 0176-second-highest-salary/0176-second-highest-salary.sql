# Write your MySQL query statement below
select max(t1.salary) as SecondHighestSalary
from Employee as t1 join Employee as t2
on t1.salary < t2.salary;