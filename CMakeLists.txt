cmake_minimum_required(VERSION 3.5)
project(AdoptAPet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Dog.cpp Dog.h ControllerAdmin.cpp ControllerAdmin.h ControllerUser.cpp ControllerUser.h Playlist.cpp Playlist.h RepositoryAdmin.cpp RepositoryAdmin.h RepositoryUser.cpp RepositoryUser.h Tests.cpp Tests.h UI.cpp UI.h Utils.cpp Utils.h Vector.h CustomException.h Validator.cpp Validator.h AdoptionList.cpp AdoptionList.h)
add_executable(AdoptAPet ${SOURCE_FILES})