cmake_minimum_required(VERSION 3.5)

project(Telebot
        VERSION 1.0.0
        DESCRIPTION "Library for connect to telegram bot api"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

macro(set_if_undefined variable)
    if(NOT DEFINED "${variable}")
        set("${variable}" ${ARGN})
    endif()
endmacro()

option(Telebot_SHARED_LIBS "Build libs as shared" OFF)

option(Telebot_INSTALL "Generate target for installing ApiTelegramBot" ${is_top_level})
set_if_undefined(Telebot_INSTALL_CMAKEDIR
        "${CMAKE_INSTALL_LIBDIR}/cmake/telebot" CACHE STRING
        "Install path for ApiTelegramBot package-related CMake files")

if(DEFINED Telebot_SHARED_LIBS)
    set(BUILD_SHARED_LIBS ${Telebot_SHARED_LIBS})
endif()

if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT DEFINED CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

add_library(Telebot)
add_library(Telebot::Telebot ALIAS Telebot)

set(Telebot_INCLUDES
        include/Telebot/Telebot.h
        include/Telebot/TelebotApi.h
        include/Telebot/Types/..)

set(Telebot_SOURCE
        src/Telebot/Telebot.cpp
        src/Telebot/TelebotApi.cpp
        src/Telebot/Types/BotCommandScope.cpp
        src/Telebot/Types/ChatMember.cpp
        src/Telebot/Types/InlineQueryResult.cpp
        src/Telebot/Types/InputFile.cpp
        src/Telebot/Types/InputMedia.cpp
        src/Telebot/Types/InputMessageContent.cpp
        src/Telebot/Types/MenuButton.cpp
        src/Telebot/Types/PassportElementError.cpp
        src/Telebot/Types/GenericReply.cpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES
        ${Telebot_INCLUDES}
        ${Telebot_SOURCE})

target_sources(Telebot PRIVATE ${Telebot_INCLUDES} ${Telebot_SOURCE})

find_package(Boost REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ExtendedCpp REQUIRED)

target_include_directories(Telebot PUBLIC
        ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIRS}
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/Telebot")

set_target_properties(Telebot PROPERTIES
        SOVERSION ${PROJECT_VERSION_MAJOR}
        VERSION ${PROJECT_VERSION})

target_link_libraries(Telebot PRIVATE ExtendedCpp::Json ExtendedCpp::Events ExtendedCpp::Common ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})

if(MSVC)
    target_compile_options(Telebot PRIVATE /bigobj)
else()
    target_compile_options(Telebot PRIVATE -Wa,-mbig-obj)
endif()

if(Telebot_INSTALL AND NOT CMAKE_SKIP_INSTALL_RULES)
    include(CMakePackageConfigHelpers)
    configure_package_config_file(cmake/telebot-config.cmake.in telebot-config.cmake
            INSTALL_DESTINATION "${Telebot_INSTALL_CMAKEDIR}")
    write_basic_package_version_file(telebot-config-version.cmake
            COMPATIBILITY SameMajorVersion)

    install(DIRECTORY include/
            TYPE INCLUDE
            COMPONENT Telebot)

    set(targets_file "telebot-shared-targets.cmake")
    if(NOT BUILD_SHARED_LIBS)
        set(targets_file "telebot-static-targets.cmake")
    endif()

    install(EXPORT Telebot_export
            COMPONENT "${PROJECT_NAME}"
            FILE "${targets_file}"
            DESTINATION ${Telebot_INSTALL_CMAKEDIR}
            NAMESPACE ${PROJECT_NAME}::)

    install(FILES
            "${CMAKE_CURRENT_BINARY_DIR}/telebot-config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/telebot-config-version.cmake"
            COMPONENT Telebot
            DESTINATION "${Telebot_INSTALL_CMAKEDIR}")

    include(cmake/utils.cmake)
    install_projects(Telebot)
endif()