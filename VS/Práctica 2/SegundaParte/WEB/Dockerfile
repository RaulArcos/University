FROM alpine:3.14
RUN apk add --no-cache py3-pip g++ mariadb-dev python3-dev
WORKDIR /web_project
COPY ./web_project .
RUN pip install django-crispy-forms mysqlclient django
ENTRYPOINT [ "python3","manage.py","runserver", "0.0.0.0:80"]
