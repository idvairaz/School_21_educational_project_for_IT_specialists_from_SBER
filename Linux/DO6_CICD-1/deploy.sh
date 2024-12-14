#!/bin/bash
# этот файл был запасной вариант, в проекте не используется
# Переменные для доступа к GitLab и второй виртуальной машине
GITLAB_URL="https://gitlab.com"
GITLAB_PROJECT="845898"
#GITLAB_TOKEN="your_gitlab_token"
VM_HOST="10.0.2.15"
VM_USER="cicd2-VirtualBox"
VM_DEST_DIR="/usr/local/bin"

# Создание временной директории для загрузки артефактов
temp_dir=$(mktemp -d)

# Загрузка артефактов с GitLab
curl --header "PRIVATE-TOKEN: $GITLAB_TOKEN" -o "$temp_dir/artifact.zip" "$GITLAB_URL/api/v4/projects/$GITLAB_PROJECT/jobs/artifacts/master/download?job=build"

# Копирование артефактов на вторую виртуальную машину
scp -i //.ssh/id_rsa "$temp_dir/artifact.zip" "$VM_USER@$VM_HOST:$VM_DEST_DIR"

# Удаление временной директории
#rm -rf "$temp_dir"


#!/bin/bash

# Переменные для доступа к второй виртуальной машине
GITLAB_PROJECT="845898"
VM_HOST="10.0.2.15"
VM_USER="cicd2-VirtualBox"
VM_DEST_DIR="/usr/local/bin"

# Создание временной директории для загрузки артефактов
temp_dir=$(mktemp -d)

# Загрузка артефактов с GitLab
source /home/penny/.gitlab-runner/config.toml
curl --header "PRIVATE-TOKEN: $CI_JOB_TOKEN" -o "$temp_dir/artifact.zip" "$CI_PROJECT_URL/api/v4/projects/$CI_PROJECT_ID/jobs/artifacts/master/download?job=build"

# Копирование артефактов на вторую виртуальную машину
scp -i /home/.ssh/id_rsa "$temp_dir/artifact.zip" "$VM_USER@$VM_HOST:$VM_DEST_DIR"


# Удаление временной директории
#rm -rf "$temp_dir"
