select m.name
from Employee e
join Employee m
on e.managerId = m.id
group by m.id,m.name
having count(*)>=5;