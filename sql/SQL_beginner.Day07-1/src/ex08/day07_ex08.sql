SELECT person.address, pizzeria.name, count(person_order.id) AS count_of_orders
FROM menu
         JOIN pizzeria on pizzeria.id = menu.pizzeria_id
         JOIN person_order on menu.id = person_order.menu_id
         JOIN person on person.id = person_order.person_id
GROUP BY person.address, pizzeria.name
ORDER BY person.address, pizzeria.name;