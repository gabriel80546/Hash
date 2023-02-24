#!/usr/bin/env bash
echo "rodando: \"gcc main.c -o main -lssl -lcrypto\""
gcc main.c -o main -lssl -lcrypto
echo "rodando: echo \$?"
echo " => $?"
