SELECT menu.id AS menu_id
FROM menu
         FULL JOIN person_order  ON menu.id = person_order.menu_id
WHERE person_order.id IS NULL
ORDER BY menu_id;

