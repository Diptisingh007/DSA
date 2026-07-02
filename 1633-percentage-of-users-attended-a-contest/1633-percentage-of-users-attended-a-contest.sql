# Write your MySQL query statement below
SELECT
    r.contest_id,
    round(
        count(distinct r.user_id) * 100.0 /
        (SELECT count(*) FROM Users),
        2
    ) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id ASC;
