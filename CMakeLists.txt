cmake_minimum_required(VERSION 3.13)
project(RAID5)

set(CMAKE_CXX_STANDARD 14)

add_library(RAID5 library.cpp library.h Stripe.cpp Stripe.h Folder.cpp Folder.h List.cpp List.h Node.cpp Node.h)