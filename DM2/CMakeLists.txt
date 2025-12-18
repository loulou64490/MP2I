cmake_minimum_required(VERSION 3.10)
project(DM2 C)

set(CMAKE_C_STANDARD 17)

add_executable(DM2
        src/main.c
        src/sound.c
        src/melody.c
        src/wav.c
        src/waveform.c
        src/test.c
)

target_link_libraries(DM2 m) # maths

