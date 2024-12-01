# Используем официальный образ nginx в качестве базового
#FROM nginx
FROM alpine

# Устанавливаем необходимые пакеты для компиляции и запуска
# RUN apt-get update && apt-get install -y \
#     build-essential \
#     libc6-dev \
#     libfcgi-dev \
#     spawn-fcgi \
#     fcgiwrap \
#     && apt-get clean \
#     && rm -rf /var/lib/apt/lists/*
RUN apk --no-cache --upgrade add \
    bash \
    build-base \
    alpine-sdk \
    fcgi-dev \
    spawn-fcgi \
    nginx

# Копируем исходный файл hello.c в контейнер
COPY server/hello.c .

# Компилируем исходный файл в двоичный файл hello
RUN gcc hello.c -o hello -lfcgi

# Создаем директорию для FastCGI
RUN mkdir -p /var/run/fcgiwrap

RUN  touch /var/run/nginx.pid && \
     chown -R nginx:nginx /var/run/nginx.pid
#     chown -R nginx:nginx /var/cache/nginx /var/run/nginx.pid

USER nginx
# Копируем конфигурационный файл nginx.conf в контейнер
COPY --chown=nginx:nginx ./server/nginx/nginx.conf /etc/nginx/nginx.conf

EXPOSE 81

# Запускаем fcgiwrap и Nginx
CMD ["sh", "-c", "spawn-fcgi -p 8080 /hello && nginx -g 'daemon off;'"]
