# Simple Docker  
  
## Содержание  
  
1. [Часть 1. Готовый докер](#часть-1-готовый-докер)  
2. [Часть 2. Операции с контейнером](#часть-2-операции-с-контейнером)   
  
## Часть 1. Готовый докер  
   * Возьми официальный докер-образ с **nginx** и выкачай его при помощи `docker pull`  
     - ![report01](../misc/images/report01.png "Получение образа nginx")    
     - `docker pull nginx`   
   * Проверь наличие докер-образа через `docker images`  
     - ![report02](../misc/images/report02.png "Получение списка доступных образов")  
     - `docker images`   
   * Запусти докер-образ через `docker run -d [image_id|repository]`  
     - ![report03](../misc/images/report03.png "Запуск образа")  
     - `docker run -d nginx`   
   * Проверь, что образ запустился через `docker ps`  
     - ![report04](../misc/images/report04.png "Просмотр списка контейнеров")  
     - `docker ps`   
   * Посмотри информацию о контейнере через `docker inspect [container_id|container_name]`  
     - ![report05](../misc/images/report05.png "Просмотр информации о контейнере")  
     - ![report05.2](../misc/images/report05.2.png "Просмотр информации о контейнере")  
     - `docker inspect zen_khayyam`(по имени информации больше).   
     - ![report05.3](../misc/images/report05.3.png "Просмотр информации о контейнере")  
     - `docker inspect 3b25b682ea82`. 
   * По выводу команды определи и помести в отчёт размер контейнера, список замапленных портов и ip контейнера  
     - ![report06](../misc/images/report06.png "Список замапленных портов, IP контейнера, Размер контейнера")  
   * Останови докер образ через `docker stop [container_id|container_name]`    
   * Проверь, что образ остановился через `docker ps`.  
     - ![report10](../misc/images/report10.png "Остановка контейнера, Просмотр активных контейнеров")
     - `docker stop zen_khayyam`
     - `docker ps`    
   * Запусти докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду  
     - ![report11](../misc/images/report11.png "Запуск образа с портами 80 и 443")  
     - `docker run -d -p 80:80 -p 443:443 nginx`  
   * Проверь, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**.  
     - ![report12](../misc/images/report12.png "Проверка работы nginx")  
   * Перезапусти докер контейнер через `docker restart [container_id|container_name]`  
     - ![report13](../misc/images/report13.png "Перезапуск контейнера")  
     - `docker restart a873a7bf2752`  
   * Проверь любым способом, что контейнер запустился.  
     - ![report14](../misc/images/report14.png "Проверка работы nginx")  
     
## Часть 2. Операции с контейнером  
   * Прочитай конфигурационный файл *nginx.conf* внутри докер контейнера через команду *exec*  
     - ![report15](../misc/images/report15.png "Чтение nginx.conf внутри контейнера")  
     - `docker exec zen_khayyam cat /etc/nginx/nginx.conf`  
   * Создай на локальной машине файл *nginx.conf*.
     - ![report15.1](../misc/images/report15.1.png "Создание nginx.conf на локальной машине")  
     - `docker exec zen_khayyam cat /etc/nginx/nginx.conf > nginx.conf`  
   * Настрой в нем по пути */status* отдачу страницы статуса сервера **nginx**  
     - ![report16](../misc/images/report16.png "Изменен nginx.conf")  
   * Скопируй созданный файл *nginx.conf* внутрь докер-образа через команду `docker cp`  
     - ![report17](../misc/images/report17.png "Перезапуск службыв nginx контейнере")  
     - `docker cp /home/ira/Downloads/School-21_Основа/DO5_SimpleDocker-1/nginx.conf zen_khayyam:/etc/nginx/nginx.conf`  
   * Перезапусти **nginx** внутри докер-образа через команду *exec*  
     - ![report18](../misc/images/report18.png "Перезапуск nginx в контейнере")  
     - `docker exec zen_khayyam nginx -s reload`  
   * Проверь, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**  
     - ![report19](../misc/images/report19.png "Проверка работоспособности /status")  
     - `curl localhost:80/status`  
   * Экспортируй контейнер в файл *container.tar* через команду *export*  
     - ![report20](../misc/images/report20.png "Экспорт контейнера в файл")  
     - `docker export 9d5aa -o container.tar`  
   * Останови контейнер  
     - ![report21](../misc/images/report21.png "Остановка контейнера")  
     - `docker stop 9d5aa`  
   * Удали образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры  
     - ![report22](../misc/images/report22.png "Удаление образа nginx")  
     - `docker rmi -f nginx`  
   * Удали остановленный контейнер  
     - ![report23](../misc/images/report23.png "Удаление контейнера")   
     - `docker rm 9d5aa`  
     - `docker ps -a`  
   * Импортируй контейнер обратно через команду *import*  
     - ![report24](../misc/images/report24.png "Импорт образа из файла")  
     - `docker import --change 'CMD ["nginx", "-g", "daemon off;"]' container.tar ira_nginx`  
   * Запусти импортированный контейнер  
     - ![report25](../misc/images/report25.png "Запуск контейнера из импортированного образа")  
     - `docker run -d -p 80:80 -p 443:443 ira_nginx`  
   * Проверь, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**  
     - ![report26](../misc/images/report26.png "Проверка работоспособности /status")  
     - `curl localhost:80/status`
