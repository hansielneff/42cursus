FROM debian:buster

WORKDIR /

RUN apt-get update && apt-get -y upgrade
RUN apt-get -y install php php-fpm mariadb-client apache2 sendmail wordpress wget

RUN mkdir -p /run/php && mkdir -p /var/www/html

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

# Install wp-cli
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html

COPY ./tools/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 9000/tcp

ENTRYPOINT ["entrypoint.sh"]
