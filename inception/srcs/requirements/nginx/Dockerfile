FROM alpine:3.15

RUN apk update  && apk upgrade 
RUN apk add nginx openssl
# RUN apk --no-cache add bash
RUN rm -rf /var/cache/apk/*

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/CN/dvasco-m.42.fr/C=ES/L=Malaga"

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
