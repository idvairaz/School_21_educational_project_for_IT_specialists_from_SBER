-- Пример работы уровня "serializable", который здесь решает
-- "аномалию неповторяемого чтения"
--
-- Гарантирует неизменяемость данных другими процессами до завершения транзакции.

-- Session #1
BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;
-- в сессии 1 транзакция началась
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
-- вносим изменения и КОММИТИМ! в сессии 2
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
--  но изменения , сделанные в сессии 2 в БД не произошли

COMMIT;
-- пока не сделан commit в сессии 1
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

-- Session #2
BEGIN TRANSACTION ISOLATION LEVEL SERIALIZABLE;
UPDATE pizzeria SET rating = 3 WHERE name = 'Pizza Hut';
COMMIT;
-- вносим изменения и КОММИТИМ!, но в БД они сохранятся тоько после того
-- как произойдет коммит в сессии 1
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';