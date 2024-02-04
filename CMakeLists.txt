cmake_minimum_required (VERSION 3.10)

project (NeuronNetwork)

#####################################################################

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

#####################################################################

if (WIN32)
    # próbujemy linkować statycznie (nie trzeba kopiować plików dll do katalogu projektu)
    set( SFML_STATIC_LIBRARIES TRUE )

    # można zmienić katalog na właściwy
    set ( SFML_DIR "C:/cpp/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable( NeuronNetwork main.cpp source/Window.cpp include/Window.h source/Neuron.cpp include/Neuron.h source/Net.cpp include/Net.h)

target_link_libraries(NeuronNetwork sfml-graphics sfml-audio)