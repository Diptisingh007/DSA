# Write your MySQL query statement below
select name from Employee as e
inner join (select managerId  ,count(managerId) as cnt from Employee group by managerId having cnt>=5) temp
on e.id=temp.managerId;
 