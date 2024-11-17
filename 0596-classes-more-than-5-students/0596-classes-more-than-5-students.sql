# Write your MySQL query statement below
select class
from(
select class,count(class) as val
from Courses
group by class
) as new_table
where val >=5;
