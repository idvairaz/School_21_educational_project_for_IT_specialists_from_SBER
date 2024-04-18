SELECT menu.pizza_name, menu.price, pizzeria.name AS pizzeria_name
FROM menu
         FULL JOIN person_order po ON menu.id = po.menu_id
         FULL JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
WHERE po.menu_id IS NULL
ORDER BY pizza_name, price;

