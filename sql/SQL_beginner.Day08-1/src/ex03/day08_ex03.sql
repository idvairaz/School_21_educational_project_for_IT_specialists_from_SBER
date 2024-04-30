-- Пример работы уровня "read committed" (Чтение подтвержденных данных (дефолт для PostreSQL))
-- который здесь решает  "аномалию потерянного обновления"

-- Чтение всех изменений своей транзакции и зафиксированных изменений параллельных
-- транзакций, но процессы-писатели могут изменять уже прочитанные читателем данные.
-- Возможны неповторяемое чтение и фантомы

-- Session #1
BEGIN;
SHOW TRANSACTION ISOLATION LEVEL;
-- в сессии 1 транзакция началась
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
-- смотрим данные
-- вносим изменения и КОММИТИМ! в сессии 2
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
-- изменения в сессии 2 произошли в БД
COMMIT;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

-- Session #2
BEGIN;
SHOW TRANSACTION ISOLATION LEVEL;
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut';
COMMIT;
-- вносим изменения и КОММИТИМ!, в БД они сохранятся, это можно увидеть  в сессии 1
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';