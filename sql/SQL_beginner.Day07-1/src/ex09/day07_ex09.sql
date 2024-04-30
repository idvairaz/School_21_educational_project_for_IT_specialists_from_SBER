SELECT address,
       round(max(age)::NUMERIC - (min(age)::NUMERIC / max(age)::NUMERIC), 2) AS formula,
       round(avg(age), 2)                                                    AS average,
       CASE
           WHEN MAX(age) - (MIN(age) / MAX(age)) > AVG(age) THEN 'True'
           ELSE 'False'
           END                                                               AS comparison
FROM person
GROUP BY address
ORDER BY address;