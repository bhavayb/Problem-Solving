# Write your MySQL query statement below
with counttable as(
    select 
    num,
    count(num) as cnt
    from MyNumbers
    group by num
)
select
max(num) as num
from counttable ct
where ct.cnt = 1