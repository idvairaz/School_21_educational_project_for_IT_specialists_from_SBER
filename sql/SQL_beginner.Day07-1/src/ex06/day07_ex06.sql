SELECT pizzeria.name, count(person_order.id) AS count_of_orders, round(avg(price), 2) AS average_price, max(price) AS max_price, min(price) AS min_price
    FROM pizzeria
    JOIN menu  ON pizzeria.id = menu.pizzeria_id
JOIN person_order ON menu.id = person_order.menu_id
GROUP BY pizzeria.name
ORDER BY name;