cmake_minimum_required(VERSION 3.10)
project(sys ASM C)

add_library(STATIC aarch64/svc.S aarch64/tls.c)