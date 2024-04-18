SELECT self_menu1.pizza_name,
       self_pizzeria1.name AS pizzeria_name_1,
       self_pizzeria2.name AS pizzeria_name_2,
       self_menu1.price
FROM menu AS self_menu1
         JOIN pizzeria AS self_pizzeria1 ON self_menu1.pizzeria_id = self_pizzeria1.id
         JOIN menu AS self_menu2 ON self_menu1.pizza_name = self_menu2.pizza_name
                                AND self_menu1.price = self_menu2.price
                                AND self_menu1.id > self_menu2.id
         JOIN pizzeria AS self_pizzeria2 ON self_menu2.pizzeria_id = self_pizzeria2.id
ORDER BY pizza_name;


