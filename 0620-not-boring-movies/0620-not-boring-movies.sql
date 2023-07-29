/* Write your PL/SQL query statement below */
select * from cinema where mod(id,2)=1 and description<>'boring' order by rating desc