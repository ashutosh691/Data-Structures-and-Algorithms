# Write your MySQL query statement below
select distinct num as ConsecutiveNums
from (
    select num, 
    lead(num, 1) over(order by id) as next_num,
    lead(num, 2) over(order by id) as next_next_num
    from logs
) as subq
where num = subq.next_num and subq.next_num = subq.next_next_num;