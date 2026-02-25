# =============================================================================
# CMakeLists.txt - Multi-projekt C++ skabelon
# =============================================================================
# STRUKTUR:
#   projects/
#   ├── exercise1/
#   │   ├── src/main.cpp
#   │   └── include/
#   ├── exercise2/
#   │   ├── src/main.cpp
#   │   └── include/
#   └── ...
#
# SÅDAN TILFØJER DU EN NY OPGAVE:
#   1. Opret mappen: projects/exercise3/
#   2. Opret undermapper: src/ og include/
#   3. Tilføj main.cpp i src/
#   4. Gem - CMake finder det automatisk!
#
# SÅDAN KØRER DU I VSCODE:
#   - Vælg target (f.eks. "exercise1") nederst i statuslinjen
#   - Tryk F5 for at køre
# =============================================================================

cmake_minimum_required(VERSION 3.20)

# ─────────────────────────────────────────────────────────────────────────────
# PROJEKT OPSÆTNING
# ─────────────────────────────────────────────────────────────────────────────
project(AlgoritmerOgDatastrukturer)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ─────────────────────────────────────────────────────────────────────────────
# COMPILER WARNINGS - Hjælper dig med at finde fejl
# ─────────────────────────────────────────────────────────────────────────────
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wuninitialized")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

# ─────────────────────────────────────────────────────────────────────────────
# DELT KODE (valgfrit) - Kode der bruges af flere projekter
# ─────────────────────────────────────────────────────────────────────────────
set(SHARED_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/shared/include)
file(GLOB SHARED_SOURCES "shared/src/*.cpp")

if(SHARED_SOURCES)
    add_library(shared_lib STATIC ${SHARED_SOURCES})
    target_include_directories(shared_lib PUBLIC ${SHARED_INCLUDE_DIR})
endif()

# ─────────────────────────────────────────────────────────────────────────────
# AUTOMATISK PROJEKT OPDAGELSE
# ─────────────────────────────────────────────────────────────────────────────
# Scanner: projects/{exercise}/src/main.cpp
# Bygger:  {exercise}.exe

file(GLOB EXERCISE_DIRS "projects/*")

foreach(EXERCISE_DIR ${EXERCISE_DIRS})
    # Tjek om det er en opgave med src/main.cpp
    if(IS_DIRECTORY ${EXERCISE_DIR} AND EXISTS "${EXERCISE_DIR}/src/main.cpp")
        get_filename_component(TARGET_NAME ${EXERCISE_DIR} NAME)

        # Find alle .cpp filer
        file(GLOB EXERCISE_SOURCES "${EXERCISE_DIR}/src/*.cpp")

        # Opret executable
        add_executable(${TARGET_NAME} ${EXERCISE_SOURCES})

        # Tilføj lokal include mappe
        if(EXISTS "${EXERCISE_DIR}/include")
            target_include_directories(${TARGET_NAME} PRIVATE "${EXERCISE_DIR}/include")
        endif()

        # Link til delt kode
        if(SHARED_SOURCES)
            target_link_libraries(${TARGET_NAME} PRIVATE shared_lib)
            target_include_directories(${TARGET_NAME} PRIVATE ${SHARED_INCLUDE_DIR})
        endif()

        message(STATUS "Fundet: ${TARGET_NAME}")
    endif()
endforeach()

# ─────────────────────────────────────────────────────────────────────────────
# INFO
# ─────────────────────────────────────────────────────────────────────────────
message(STATUS "")
message(STATUS "════════════════════════════════════════════════════════")
message(STATUS "  Ny opgave: Opret projects/exerciseX/src/main.cpp")
message(STATUS "════════════════════════════════════════════════════════")