#!/bin/bash


TELEGRAM_BOT_TOKEN="8015135936:AAEc8MKkY6MNxG6HyQtgt4aHDXqV5wrpZkw"
TELEGRAM_USER_ID="879082243"
CHANNEL_ID="-1002372318843" 
TIME=10

URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
TEXT="Deploy status: $1%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG%0A%0AJob name: $CI_JOB_NAME%0A%0AStatus:+$CI_JOB_STATUS"

curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
curl -s --max-time $TIME -d "chat_id=$CHANNEL_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null

