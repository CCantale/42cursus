FROM	debian:buster

RUN	apt update

RUN	apt install -y mariadb-server mariadb-client

EXPOSE		3306

COPY	tools/config.sh /tmp/
COPY	conf/mariadb.conf /etc/mysql/conf.d/mysql.cnf

CMD	["sh", "/tmp/config.sh"]

