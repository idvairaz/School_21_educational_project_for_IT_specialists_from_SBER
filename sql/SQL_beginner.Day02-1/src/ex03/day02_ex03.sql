WITH day_generator AS (
    (SELECT date::DATE AS missing_date
     FROM generate_series('2022-01-01', '2022-01-10', interval '1 day') AS date))

SELECT day_generator.missing_date
FROM day_generator
         FULL JOIN (SELECT visit_date
                    FROM person_visits
                    WHERE (person_id = 1 OR person_id = 2)
                      AND visit_date BETWEEN '2022-01-01' AND '2022-01-10') AS temp
                   ON (day_generator.missing_date = temp.visit_date)
WHERE temp.visit_date IS NULL;

