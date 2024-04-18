WITH filter_date AS (SELECT visit_date, person_id, person_visits.pizzeria_id
                     FROM person
                              JOIN person_visits on person.id = person_visits.person_id
                     WHERE name = 'Kate'),
     filter_pizzeria AS (SELECT pizzeria.name, filter_date.visit_date
                         FROM pizzeria
                                  JOIN filter_date on pizzeria.id = filter_date.pizzeria_id),
     filter_menu AS (SELECT pizza_name, price, pizzeria.name AS pizzeria_name
                     FROM menu
                              JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
                     WHERE price BETWEEN 800 AND 1000)
SELECT filter_menu.pizza_name AS pizza_name,
       filter_menu.price,
       filter_pizzeria.name   AS pizzeria_name,
       filter_pizzeria.visit_date
FROM filter_menu
         JOIN filter_pizzeria ON filter_pizzeria.name = filter_menu.pizzeria_name
ORDER BY pizza_name, price, pizzeria_name;








