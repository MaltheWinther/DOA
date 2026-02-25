cmake_minimum_required(VERSION 3.20)



project(AlgoritmerOgDatastrukturer)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler warnings
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wuninitialized")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

# Delt kode (valgfrit)
set(SHARED_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/shared/include)
file(GLOB SHARED_SOURCES "shared/src/*.cpp")

if(SHARED_SOURCES)
    add_library(shared_lib STATIC ${SHARED_SOURCES})
    target_include_directories(shared_lib PUBLIC ${SHARED_INCLUDE_DIR})
endif()

# Automatisk projektopdagelse (opgaver)
file(GLOB OPGAVE_DIRS "projects/*/*")
set(OPGAVER fundet)

foreach(OPGAVE_DIR ${OPGAVE_DIRS})
    if(IS_DIRECTORY ${OPGAVE_DIR} AND EXISTS "${OPGAVE_DIR}/src/main.cpp")
        get_filename_component(TARGET_NAME ${OPGAVE_DIR} NAME)
        file(GLOB OPGAVE_SOURCES "${OPGAVE_DIR}/src/*.cpp")
        add_executable(${TARGET_NAME} ${OPGAVE_SOURCES})
        # Lokal include
        if(EXISTS "${OPGAVE_DIR}/include")
            target_include_directories(${TARGET_NAME} PRIVATE "${OPGAVE_DIR}/include")
        endif()
        # Link til delt kode hvis nødvendigt
        if(SHARED_SOURCES)
            target_link_libraries(${TARGET_NAME} PRIVATE shared_lib)
            target_include_directories(${TARGET_NAME} PRIVATE ${SHARED_INCLUDE_DIR})
        endif()
        message(STATUS "Fundet opgave/projekt: ${TARGET_NAME}")
        set(OPGAVER fundet)
    endif()
endforeach()


if(NOT OPGAVER)
    message(WARNING "Ingen opgaver/projekter fundet under projects/*/src/main.cpp")
endif()

message(STATUS "")
message(STATUS "════════════════════════════════════════════════════════")
message(STATUS "  Ny opgave/projekt: Opret projects/opgaveX/src/main.cpp")
message(STATUS "  (eller et andet navn, fx. opgave2_mutex, opgave2_semaphore, etc.)")
message(STATUS "════════════════════════════════════════════════════════")