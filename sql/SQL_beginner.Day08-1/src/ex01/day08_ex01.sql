-- Пример работы уровня "read committed", который здесь решает
-- "аномалию потерянного обновления"

-- Session #1
BEGIN;
-- команда для проверки уровня изолированности транзакций
-- (в Postgres по умолчанию read committed)
SHOW TRANSACTION ISOLATION LEVEL;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
UPDATE pizzeria SET rating = 4 WHERE name = 'Pizza Hut';
-- все операции повторяем по очереди по одной для каждой сессии,
-- пока не применен COMMIT в сессии 1, в сессии 2 не выполняется
-- UPDATE (скрин 01_1)
COMMIT;
-- после применения COMMIT в сессии 1, в сессии 2 произвелся UPDATE (скрин 01_2)
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

-- Session #2
BEGIN;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut';
COMMIT;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

-- после выполнения всех операций рейтинг Pizza Hut в БД 3,6,
-- согласно последнему "заапдейтченному коммиту"
-- (UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut';)
-- в сессии 2 (скрин 01_3)