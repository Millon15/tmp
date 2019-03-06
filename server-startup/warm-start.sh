#!/bin/bash

# This file needs to be launched, when you have to restart your preconfigured docker container for cheatera.pp.ua app
# IT MUST BE LAUNCHED IN THE ROOT OF THE PROJECT, THAT WAY: . ./warm-start.sh

GREEN='\e[0;32m'
RED='\e[0;31m'

composer i
docker-machine start default
eval $(docker-machine env default)
#docker stop $(docker ps -q)
#docker rm $(docker ps -aq)

if docker-compose up -d --build; then
	# Setup database from dump placed in the root of the project
	sleep 5
	MYSQL_HASH=$(docker ps | grep mysql | awk '{print $1}')
	DB_USERNAME=$(grep "^DB_USERNAME=" .env | cut -d= -f2)
	DB_PASSWORD=$(grep "^DB_PASSWORD=" .env | cut -d= -f2)
	DB_NAME=$(grep "^DB_NAME=" .env | cut -d= -f2)

	docker exec $MYSQL_HASH mysql -u$DB_USERNAME -p$DB_PASSWORD -e "CREATE DATABASE IF NOT EXISTS yii2"
	docker exec -i $MYSQL_HASH mysql -u$DB_USERNAME -p$DB_PASSWORD $DB_NAME < schema.sql

	printf "${GREEN}Server successfully setted up and now reachable at: http://$(docker-machine ip default):8888\n"
else
	printf "${RED}Error occured when running command: docker-compose up -d --build\n"
fi
