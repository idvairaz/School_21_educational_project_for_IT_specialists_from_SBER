-- Пример работы уровня "REPEATABLE READ", который здесь  РЕШАЕТ
-- "аномалию фантомного чтения"

-- Session #1
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;
SELECT SUM(rating) FROM pizzeria;
-- один и тот же запрос дает одинаковый результат (такой же, как на момент начала транзакции 1),
-- до окончания сессии1, не взираяна то, что  в это время сессия 2 вносит изменения в БД
SELECT SUM(rating) FROM pizzeria;
COMMIT;
SELECT SUM(rating) FROM pizzeria;

-- Session #2
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;
UPDATE pizzeria SET rating = 5 WHERE name = 'Pizza Hut';
COMMIT;
-- внесли изменения в БД, но не  в сессии 1, которая уже работает с
-- этими данными и еще не произвела commit, изменения из сессии 2 не видны,
-- т.е  повторные  выборки одних и тех же данных (до update и после в сессии 2),
-- в сессии 1 будут одинаковыми, такими же, как на момент начала транзакции 1.
-- только после коммита в сессии 1, там появятся изменения произведенные в сессии 2.

SELECT SUM(rating) FROM pizzeria;