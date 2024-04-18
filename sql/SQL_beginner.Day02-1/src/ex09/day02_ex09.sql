SELECT DISTINCT person.name
FROM person
         JOIN person_order ON person.id = person_order.person_id
         JOIN menu ON person_order.menu_id = menu.id AND menu.pizza_name = 'pepperoni pizza'
WHERE person.gender = 'female'
  AND EXISTS (SELECT person.name
              FROM person_order
                       JOIN menu ON person_order.menu_id = menu.id AND menu.pizza_name = 'cheese pizza'
              WHERE person_order.person_id = person.id);

