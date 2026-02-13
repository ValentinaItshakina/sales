cmake_minimum_required(VERSION 3.10)

project(ProjectName)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(${PROJECT_NAME}

    main.cpp

    src/Class1.cpp

    src/Class2.cpp

    include/Class1.h

    include/Class2.h

)