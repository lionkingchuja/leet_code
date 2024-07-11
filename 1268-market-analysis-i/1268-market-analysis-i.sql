SELECT 
    t1.user_id as buyer_id,
    t1.join_date,
    COUNT(CASE WHEN YEAR(t2.order_date) = 2019 THEN 1 ELSE NULL END) AS orders_in_2019
FROM 
    Users AS t1
LEFT JOIN 
    Orders AS t2 
ON 
    t1.user_id = t2.buyer_id
GROUP BY 
    t1.user_id;
