-- Пример работы уровня "REPEATABLE READ", который здесь решает
-- "аномалию потерянного обновления"

-- Session #1
-- команда для изменения уровня изолированности транзакции
-- это надо сделать в обеих сессиях
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;
-- на всякий случай проверим уровень
SHOW TRANSACTION ISOLATION LEVEL;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
UPDATE pizzeria SET rating = 4 WHERE name = 'Pizza Hut';
COMMIT;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

-- Session #2
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;
SHOW TRANSACTION ISOLATION LEVEL;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut';
COMMIT;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';