-- Без индекса

EXPLAIN ANALYZE
SELECT
    m.pizza_name AS pizza_name,
    max(rating) OVER (PARTITION BY rating ORDER BY rating ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) AS k
FROM  menu m
          INNER JOIN pizzeria pz ON m.pizzeria_id = pz.id
ORDER BY 1,2;
-----------------------------------------------------------------
-- Вариант1

CREATE UNIQUE INDEX  idx_1 ON pizzeria (id);

SET enable_seqscan TO OFF;
EXPLAIN ANALYZE
SELECT
    m.pizza_name AS pizza_name,
    max(rating) OVER (PARTITION BY rating ORDER BY rating ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) AS k
FROM  menu m
          INNER JOIN pizzeria pz ON m.pizzeria_id = pz.id
ORDER BY 1,2;

DROP INDEX idx_1;
------------------------------------------------------
-- Вариант2

CREATE INDEX  idx_1 ON pizzeria (rating);

SET enable_seqscan TO OFF;
EXPLAIN ANALYZE
SELECT
    m.pizza_name AS pizza_name,
    max(rating) OVER (PARTITION BY rating ORDER BY rating ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) AS k
FROM  menu m
          INNER JOIN pizzeria pz ON m.pizzeria_id = pz.id
ORDER BY 1,2;

DROP INDEX idx_1;

-- DROP INDEX idx_menu_pizzeria_id;
-- DROP INDEX idx_person_order_person_id;
-- DROP INDEX idx_person_order_menu_id;
-- DROP INDEX idx_person_visits_person_id;
-- DROP INDEX idx_person_visits_pizzeria_id;