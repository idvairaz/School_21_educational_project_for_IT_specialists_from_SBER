CREATE INDEX idx_person_order_multi ON person_order (person_id, menu_id, order_date);

SET enable_seqscan TO OFF;
EXPLAIN ANALYSE
SELECT person_id, menu_id, order_date
FROM person_order
WHERE person_id = 8 AND menu_id = 19;


-- Index Only Scan используется, когда запрашиваемые данные все содержатся в индексе
-- и база данных не нуждается в обращении к самой таблиц
-- В ex02  БД использовала Index Scan , так как нужно было применить функцию UPPER()
-- к столбцу name
