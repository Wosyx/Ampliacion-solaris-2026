cmake_minimum_required(VERSION 4.0)

project(Watchdog)

add_executable(main)

target_sources(main 
    PRIVATE
    main.c
)

add_library(header)

target_sources(header
    PRIVATE
    src/watchdog.c 

    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
    watchdog.h
    types.h
)

target_link_libraries(main
    PRIVATE
    header
)