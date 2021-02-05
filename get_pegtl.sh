#!/bin/sh

mkdir -p vendor/
git clone --single-branch --branch 3.2.0 https://github.com/taocpp/PEGTL/ vendor/PEGTL