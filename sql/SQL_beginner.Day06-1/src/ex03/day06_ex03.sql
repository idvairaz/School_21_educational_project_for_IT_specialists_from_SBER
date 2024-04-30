CREATE UNIQUE INDEX idx_person_discounts_unique ON
    person_discounts (person_id, pizzeria_id);

SET
    enable_seqscan = OFF;

EXPLAIN ANALYSE
SELECT *
FROM person_discounts
WHERE person_id BETWEEN 1 AND 7
  AND pizzeria_id BETWEEN 1 AND 5;