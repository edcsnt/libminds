FROM docker.io/library/alpine:latest
COPY config.mk Makefile minds.h /
COPY test /test
RUN <<EOT
  printf 'https://dl-cdn.alpinelinux.org/alpine/edge/testing\n' \
    >> /etc/apk/repositories
  apk -U upgrade
  apk add cproc musl-dev pdpmake
  ln -fs cproc /usr/bin/cc
  ln -s pdpmake /usr/bin/make
  make
EOT
