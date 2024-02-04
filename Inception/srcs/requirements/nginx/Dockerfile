FROM	debian:buster

RUN	apt-get update
RUN	apt-get install -y nginx \
			openssl

RUN	mkdir /etc/nginx/ssl
RUN	openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/ccantale.crt \
	-keyout /etc/nginx/ssl/ccantale.key \
	-subj "/C=IT/ST=Rome/L=Rome/O=42 School/OU=ccantale/CN=ccantale/"

RUN	rm -rf /etc/nginx/conf.d/default.conf
COPY	./conf/nginx.conf /etc/nginx/conf.d/default.conf

COPY	./www/index.html /var/www/index.html

RUN	mkdir -p /run/nginx

EXPOSE	443

CMD	["nginx", "-g",  "daemon off;"]
