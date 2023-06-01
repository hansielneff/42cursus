FROM debian:buster

WORKDIR /

RUN apt-get update && apt-get -y upgrade
RUN apt-get -y install mariadb-server

# Configure mariadb to allow remote connections on 0.0.0.0:3306
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
RUN chmod 440 /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 3306/tcp

ENTRYPOINT ["entrypoint.sh"]
