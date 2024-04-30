-- Session #1
BEGIN; -- начинаем транзакцию со слова BEGIN
UPDATE pizzeria
SET rating = 5
WHERE name = 'Pizza Hut';
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

-- пока не применим COMMIT, в сессии 2 результат операции UPDATE не увидим
COMMIT;

-- Session #2

SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
