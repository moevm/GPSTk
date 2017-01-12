cmake_minimum_required(VERSION 3.0.2)
project(ephemeris_to_kml)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC TRUE)
set(CMAKE_AUTOUIC TRUE)

find_library( CPPUNIT_LIBRARY_DEBUG NAMES libgpstk
            PATHS   ${FOO_PREFIX}/lib
                    /usr/lib
                    /usr/lib64
                    /usr/local/lib
                    /usr/local/lib64
            PATH_SUFFIXES debug )

find_library( CPPUNIT_LIBRARY_RELEASE NAMES libgpstk
            PATHS   ${FOO_PREFIX}/lib
                    /usr/lib
                    /usr/lib64
                    /usr/local/lib
                    /usr/local/lib64
            PATH_SUFFIXES release )


set (HEADERS
    inc/Ephemeris.h
    inc/GeodeticSystemPoint.h
    inc/KMLFile.h)

set (SRC
    src/main.cpp
    src/Ephemeris.cpp
    src/GeodeticSystemPoint.cpp
    src/KMLFile.cpp)

add_executable(${PROJECT_NAME} ${SRC} ${HEADERS})

target_link_libraries(${PROJECT_NAME} gpstk)
