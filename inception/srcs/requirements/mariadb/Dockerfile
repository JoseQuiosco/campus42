FROM alpine:3.18

RUN apk update && apk upgrade && apk add --no-cache mariadb mariadb-client

RUN apk --no-cache add bash

COPY tools/configure.sh /tmp/configure.sh

ENTRYPOINT ["sh", "/tmp/configure.sh"]