# Write your MySQL query statement below
select s.student_id ,s.student_name, sb.subject_name ,  count(e.student_id) attended_exams

from Students s
cross join Subjects sb
left join examinations e

  ON s.student_id=e.student_id AND sb.subject_name=e.subject_name

group by  s.student_id, s.student_name, sb.subject_name
order by  s.student_id, s.student_name, sb.subject_name;