# Write your MySQL query statement below
select t1.name from Employee as t1 
join Employee as t2 on t1.id=t2.managerId
group by t2.managerId
having count(t2.managerId) >=5;