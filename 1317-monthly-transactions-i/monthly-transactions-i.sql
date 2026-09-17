SELECT
SUBSTR(trans_date, 1, 7) as month,
country,
count(id) as trans_count,
sum(state= "approved") as approved_count,
sum(amount) as trans_total_amount,
sum((state="approved")*amount) as approved_total_amount
from transactions
GROUP BY month, country

