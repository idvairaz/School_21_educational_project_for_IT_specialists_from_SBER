SET enable_seqscan TO OFF;
EXPLAIN ANALYZE
SELECT menu.pizza_name, pizzeria.name AS pizzeria_name
FROM menu
         JOIN pizzeria on menu.pizzeria_id = pizzeria.id;


-- Когда таблица слишком мала для сканирования по индексу, командой SET enable_seqscan TO OFF;
-- можно отключить последовательное сканирование, при котором все строки отбрасываются условием фильтра










