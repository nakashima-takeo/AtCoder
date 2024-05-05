WITH JohnsShop as (SELECT id, name FROM shops WHERE id = (SELECT shop_id FROM employees WHERE name = 'John Green')),
TopItem as (SELECT name, category, price FROM items where shop_id = (SELECT id FROM JohnsShop) ORDER BY price DESC LIMIT 1)
SELECT js.name as shop_name, (SELECT name FROM employees WHERE shop_id = js.id and manager = 1) as manager_name, ti.name as item_name, ti.category as category, ti.price as price FROM JohnsShop as js, TopItem as ti ORDER BY manager_name LIMIT 1;
