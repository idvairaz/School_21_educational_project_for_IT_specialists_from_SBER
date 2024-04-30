SELECT  person.name,
       menu.pizza_name,
       menu.price,
       menu.price / 100 * (100 - person_discounts.discount) AS discount_price,
       pizzeria.name             AS pizzeria_name
FROM person
         JOIN person_order ON person.id = person_order.person_id
         JOIN menu ON person_order.menu_id = menu.id
         JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
         JOIN person_discounts ON pizzeria.id = person_discounts.pizzeria_id AND person.id = person_discounts.person_id
ORDER BY person.name, menu.pizza_name;
