WITH visits AS (SELECT pizzeria.name AS name, count(person_visits.id) AS count
                FROM person_visits
                         JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
                GROUP BY pizzeria.name),
     orders AS (SELECT pizzeria.name AS name, count(person_order.id) AS count
                FROM menu
                         JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
                         JOIN person_order ON menu.id = person_order.menu_id
                GROUP BY pizzeria.name)

SELECT pizzeria.name, COALESCE(visits.count, 0) + COALESCE(orders.count, 0) AS total_count
FROM pizzeria
    JOIN visits ON pizzeria.name = visits.name
    FULL JOIN orders ON pizzeria.name = orders.name
    ORDER BY total_count DESC, pizzeria.name;
