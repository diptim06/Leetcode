SELECT user_id,
       UPPER(SUBSTRING(LOWER(name) FROM 1 FOR 1)) || SUBSTRING(LOWER(name) FROM 2) AS name
FROM Users
ORDER BY user_id;