FROM alpine:3.15

RUN apk update && apk upgrade && apk add --no-cache redis

COPY tools/configure.sh /tmp/configure.sh

ENTRYPOINT ["sh", "/tmp/configure.sh"]