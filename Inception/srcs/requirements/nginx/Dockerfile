FROM debian:buster


RUN apt -y update && apt install -y nginx && apt install openssl -y


COPY ./tools/script.sh /


CMD [ "/script.sh" ]
