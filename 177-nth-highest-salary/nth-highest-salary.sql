CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        select salary from 
            (select salary, 
                    DENSE_RANK() over (order by salary desc) as rnk
                    from employee) as t
        where rnk = N
        limit 1
  );
END