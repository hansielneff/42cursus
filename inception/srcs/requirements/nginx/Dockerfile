FROM debian:buster

WORKDIR /

RUN apt-get update && apt-get -y upgrade
RUN apt-get -y install openssl ssl-cert nginx

COPY ./conf/nginx.conf /etc/nginx/
COPY ./conf/default /etc/nginx/sites-available/

EXPOSE 443/tcp

ENTRYPOINT ["nginx", "-g", "daemon off;"]
