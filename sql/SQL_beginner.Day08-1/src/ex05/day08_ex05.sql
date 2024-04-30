-- Пример работы уровня "read committed" (Чтение подтвержденных данных (дефолт для PostreSQL))
-- который здесь НЕ РЕШАЕТ  "аномалию фантомного чтения"

-- Session #1
BEGIN;
SHOW TRANSACTION ISOLATION LEVEL;
SELECT SUM(rating) FROM pizzeria;
-- один и тот же запрос дает разный результат, до окончания сессии1
-- т.к в это время сессия 2 вносит изменения в БД
SELECT SUM(rating) FROM pizzeria;
COMMIT;
SELECT SUM(rating) FROM pizzeria;

-- Session #2
BEGIN;
SHOW TRANSACTION ISOLATION LEVEL;
UPDATE pizzeria SET rating = 1 WHERE name = 'Pizza Hut';
COMMIT;
-- внесли изменения в БД.ю хотя транзакция в сессии 1 уже работает с
-- этими данными и еще не произвела commit, в следствие чего в сессии 1
-- будут разные выборки одних и тех же данных (до update и после в сессии 2),
-- что может привести к неверным расчетам
SELECT SUM(rating) FROM pizzeria;