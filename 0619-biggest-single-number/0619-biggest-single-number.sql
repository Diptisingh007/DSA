# Write your MySQL query statement below
select (
    select num
    from MyNumbers
    group by num
    having COUNT(*) = 1
    order by num DESC
    limit 1
) as num;