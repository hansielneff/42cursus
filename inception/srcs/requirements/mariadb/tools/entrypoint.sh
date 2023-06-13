#! /bin/bash

# Setup database if none exists
if [ ! -f "/var/lib/mysql/mysql/setup" ]; then
	
	# Transfer ownership of database dir to mysql user
	chown -R mysql:mysql /var/lib/mysql

	# Install mariadb database
	mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm > /dev/null

	# Create the 'setup' file, indicating that MariaDB has been initialized
	touch /var/lib/mysql/mysql/setup

	# Basic setup and applying recommended security changes (equivalent to running mysql_secure_installation)
	# https://dev.mysql.com/doc/refman/5.7/en/mysql-secure-installation.html
	# https://stackoverflow.com/questions/10299148/mysql-error-1045-28000-access-denied-for-user-billlocalhost-using-passw
	mysqld --user=mysql --bootstrap << EOF
USE mysql;
FLUSH PRIVILEGES;

DELETE FROM	mysql.user WHERE User='';
DROP DATABASE test;
DELETE FROM mysql.db WHERE Db='test';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');

ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';

CREATE DATABASE ${MARIADB_DATABASE} CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '${MARIADB_USER}'@'%' IDENTIFIED by '${MARIADB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MARIADB_DATABASE}.* TO '${MARIADB_USER}'@'%';

FLUSH PRIVILEGES;
EOF
fi

# https://mariadb.com/kb/en/starting-and-stopping-mariadb-automatically/
mysqld_safe
