# Write your MySQL query statement below
delete r1
from Person r1,Person r2
where r1.email=r2.email and r1.id > r2.id;