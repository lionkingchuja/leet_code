# Write your MySQL query statement below
select x1.machine_id,round(avg(x2.timestamp-x1.timestamp),3) as processing_time from Activity x1
join Activity x2
on x1.machine_id=x2.machine_id and x1.process_id=x2.process_id 
and x1.activity_type='start' and x2.activity_type='end'
group by x1.machine_id;
