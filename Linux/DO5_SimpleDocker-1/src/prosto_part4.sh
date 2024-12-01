#!/bin/bash

# sudo docker build -t my-fastcgi-server .
# sudo docker run -d -p 80:81  --name prosto my-fastcgi-server

# с тегом my-fastcgi-server dоckle давал Warn, FIX - добавила версию к тегу,
# еще был Warn - отсутствие юзера контейнера, FIX - добавила юзера в dockerfile,
# еще был ERR на уровне слоев образа, немсполняемых файлов, ключей и токенов,
# FIX - замена базового образа с nginx на alpine

sudo docker build -t my-fastcgi-server:v1 .
sudo docker run -d -p 80:81  --name prosto my-fastcgi-server:v1