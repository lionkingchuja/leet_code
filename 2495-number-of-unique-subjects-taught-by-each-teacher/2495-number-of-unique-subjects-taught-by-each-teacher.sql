#Write your MySQL query statement below
select teacher_id,count(DISTINCT subject_id) AS cnt
from Teacher 
group by teacher_id;
# select count(distinct subject_id) from Teacher ;