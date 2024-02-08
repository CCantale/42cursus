#!/bin/bash



service mysql start 


echo "CREATE DATABASE IF NOT EXISTS $maria_name ;" > maria.sql
echo "CREATE USER IF NOT EXISTS '$maria_user'@'%' IDENTIFIED BY '$maria_pwd' ;" >> maria.sql
echo "GRANT ALL PRIVILEGES ON $maria_name.* TO '$maria_user'@'%' ;" >> maria.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '12345' ;" >> maria.sql
echo "FLUSH PRIVILEGES;" >> maria.sql

mysql < maria.sql

kill $(cat /var/run/mysqld/mysqld.pid)

mysqld
