FROM		debian:buster

RUN		apt update && \
		apt install -y \
		wget \
		tar \
		mariadb-client \
		redis \
		php \
		php-fpm \
		php-bcmath \
		php-bz2 \
		php-calendar \
		php-ctype \
		php-curl \
		php-dom \
		php-exif \
		php-fileinfo \
		php-gd \
		php-gmagick \
		php-gmp \
		php-iconv \
		php-imap \
		php-intl \
		php-json \
		php-mbstring \
		php-memcache \
		php-mysqli \
		php-mysqlnd \
		php-pdo \
		php-pgsql \
		php-phar \
		php-posix \
		php-shmop \
		php-simplexml \
		php-soap \
		php-sockets \
		php-sqlite3 \
		php-sysvsem \
		php-sysvshm \
		php-tokenizer \
		php-xml \
		php-xmlreader \
		php-xmlwriter \
		php-xsl \
		php-zip

RUN		adduser --system nginx && addgroup --system nginx

COPY		conf/php-fpm.conf /etc/php/php-fmp.conf
COPY		conf/www.conf /etc/php/php-fpm.d/www.conf

COPY		conf/index.html /tmp/index.html

RUN		wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
		chmod +x wp-cli.phar && \
		mv wp-cli.phar /usr/local/bin/wp

WORKDIR		/var/www/html/wordpress

COPY		tools/configure.sh /tmp/configure.sh

ENTRYPOINT	[ "sh", "/tmp/configure.sh" ]
