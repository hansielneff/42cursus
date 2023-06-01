#! /bin/bash

# Establish connection to mariadb before proceeding
while ! mariadb -h${MARIADB_HOST} -u${MARIADB_USER} -p${MARIADB_PASSWORD} ${MARIADB_DATABASE} &>/dev/null; do
	echo Establishing connection to database..
    sleep 2
done

if [ -f "wp-config.php" ]; then
	echo "WordPress: already installed"
else
	wp core download --allow-root

	wp config create --allow-root \
		--dbhost=${MARIADB_HOST} \
		--dbname=${MARIADB_DATABASE} \
		--dbuser=${MARIADB_USER} \
		--dbpass=${MARIADB_PASSWORD}

	wp core install --allow-root \
		--url=${DOMAIN_NAME} \
		--title=${WP_TITLE} \
		--admin_user=${WP_ADMIN_USER} \
		--admin_password=${WP_ADMIN_PASS} \
		--admin_email=${WP_ADMIN_EMAIL}

	wp user create --allow-root \
		${WP_USER} ${WP_EMAIL} \
		--role=${WP_ROLE} \
		--user_pass=${WP_PASS}
	
	chown -R www-data:www-data /var/www/html
	chmod -R 775 /var/www/html

	echo Finished installation and setup!
fi

/usr/sbin/php-fpm7.3 -R -F
