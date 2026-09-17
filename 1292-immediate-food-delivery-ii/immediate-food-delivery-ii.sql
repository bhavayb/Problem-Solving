# Write your MySQL query statement below
WITH first_order as(
    select 
    customer_id,
    min(order_date) as orderD,
    min(customer_pref_delivery_date) as delD
    from delivery
    group by customer_id
)
select
round(avg(orderD= delD)*100,2) as immediate_percentage
from first_order