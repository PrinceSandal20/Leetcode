/* Write your PL/SQL query statement below */
select e.name from employee e join (select managerid from employee group by managerid having count(*)>=5) a on e.id=a.managerid