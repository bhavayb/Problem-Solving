# Write your MySQL query statement below
with producttable as(
    select
    product_id,
    min(year) as miniyear
    from Sales
    group by product_id
)
select
pt.product_id as product_id,
pt.miniyear as first_year,
s.quantity as quantity, s.price as price 
from producttable pt,Sales s
where pt.miniyear = s.year and pt.product_id = s.product_id

