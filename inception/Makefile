.PHONY: build domain

build:
	@ docker-compose --env-file srcs/.env -f srcs/docker-compose.yml up --build

domain:
	@ echo "127.0.0.1 helneff.42.fr" >> /etc/hosts
