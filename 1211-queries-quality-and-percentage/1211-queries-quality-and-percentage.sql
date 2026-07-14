# Write your MySQL query statement below
select q.query_name,
   round(avg((q.rating)/position),2) as quality,
   round(avg(if(q.rating<3,1,0))*100,2) poor_query_percentage
from Queries q
group by q.query_name ;