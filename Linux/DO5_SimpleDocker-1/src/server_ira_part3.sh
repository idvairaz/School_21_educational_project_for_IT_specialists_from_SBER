#!/bin/bash

#Этот скрипт выполняет действия, чтобы развернуть сервер на основе Nginx 
#с использованием Docker и обслуживать FastCGI-приложение

sudo docker pull nginx    
#Загружает образ Nginx с Docker Hub

sudo docker rm --force server_ira
#Удаляет контейнер server_ira, при наличии, даже если он запущен(--force)

sudo docker run -d -p 81:81 --name server_ira nginx
#Запускает новый контейнер на основе образа Nginx в фоновом режиме (-d демон), 
#связывая порт 81 из контейнера с портом 81 на хосте. Контейнеру присваивается имя server_ira

sudo docker cp server/hello.c server_ira:/
#Копирует файл hello.c из локальной директории server в корневую директорию контейнера server_ira

sudo docker cp server/nginx/nginx.conf server_ira:/etc/nginx
#Копирует файл конфигурации nginx.conf из локальной директории server/nginx в /etc/nginx в контейнере server_ira

sudo docker exec server_ira nginx -s reload
#Перезагружает конфигурацию Nginx внутри контейнера server_ira, чтобы изменения вступили в силу.

sudo docker exec server_ira apt update
#Запускает команду apt update внутри контейнера (-it), чтобы обновить список пакетов

sudo docker exec server_ira apt install gcc libfcgi-dev spawn-fcgi -y
#Устанавливает компилятор GCC, библиотеки для работы с FastCGI и утилиту spawn-fcgi 
#внутри контейнера без необходимости интерактивного подтверждения (-y)

sudo docker exec server_ira gcc hello.c -o hello -lfcgi
#Компилирует файл hello.c, создавая исполняемый файл с именем server. При компиляции используется библиотека FastCGI (-lfcgi)

sudo docker exec server_ira spawn-fcgi -p 8080 ./hello
#Запускает скомпилированный исполняемый файл server с помощью spawn-fcgi, связывая его с портом 8080. 
#Этот процесс будет обрабатывать запросы FastCGI