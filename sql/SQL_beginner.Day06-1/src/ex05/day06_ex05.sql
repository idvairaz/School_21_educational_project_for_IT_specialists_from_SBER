COMMENT ON TABLE person_discounts IS 'Таблица с информацией о скидках для заказов конкретных клиентов';
COMMENT ON COLUMN person_discounts.id IS 'Уникальный идентификатор записи в таблице person_discounts, PK';
COMMENT ON COLUMN person_discounts.person_id IS 'Идентификатор клиента, FK, ссылается на таблицу person';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'Идентификатор пиццерии, FK, ссылается на таблицу pizzeria';
COMMENT ON COLUMN person_discounts.discount IS 'Размер скидки клиента в пиццерии';





-- SELECT description
-- FROM pg_description
-- WHERE objsubid = 0 AND objoid = 'person_discounts'::regclass;
--
-- SELECT a.attname AS column_name, d.description AS column_comment
-- FROM pg_description d
--          JOIN pg_attribute a ON a.attnum = d.objsubid AND a.attrelid = d.objoid
-- WHERE d.objoid = 'person_discounts'::regclass;