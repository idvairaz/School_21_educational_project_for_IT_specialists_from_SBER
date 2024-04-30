WITH visits AS (SELECT pizzeria.name AS name, count(person_visits.id) AS count, 'visit' AS action_type
                FROM person_visits
                         JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
                GROUP BY pizzeria.name
                ORDER BY count DESC
                LIMIT 3),
     orders AS (SELECT pizzeria.name AS name, count(person_order.id) AS count, 'order' AS action_type
                FROM menu
                         JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
                         JOIN person_order ON menu.id = person_order.menu_id
                GROUP BY pizzeria.name
                ORDER BY count DESC
                LIMIT 3)
SELECT *
FROM orders
UNION ALL
SELECT *
FROM visits;

