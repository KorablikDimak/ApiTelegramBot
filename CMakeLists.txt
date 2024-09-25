cmake_minimum_required(VERSION 3.5)

project(Telebot
        VERSION 1.1.2
        DESCRIPTION "Library for connect to telegram bot api"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(cmake/utils.cmake)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

option(BUILD_SHARED_LIBS "Build libs as shared" ON)
option(Telebot_INSTALL "Generate target for installing ApiTelegramBot" ${is_top_level})
set_if_undefined(Telebot_INSTALL_CMAKEDIR
        "${CMAKE_INSTALL_LIBDIR}/telebot" CACHE STRING
        "Install path for ApiTelegramBot package-related CMake files")

set(Telebot_INCLUDES
        include/Telebot/Telebot.h
        include/Telebot/TelebotApi.h
        include/Telebot/HttpContext.h
        include/Telebot/HttpsClient.h)

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

add_library(Telebot ${Telebot_INCLUDES} ${Telebot_SOURCE})
add_library(Telebot::Telebot ALIAS Telebot)

find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED)
find_package(ExtendedCpp REQUIRED)

set_public_include_directories(Telebot)
set_targets_version(Telebot)

target_link_libraries(Telebot PRIVATE
        ExtendedCpp::Json
        ExtendedCpp::Events
        ExtendedCpp::Common
        ${OPENSSL_LIBRARIES}
        ${Boost_LIBRARIES})

if(MINGW)
    target_link_libraries(Telebot PRIVATE ws2_32)
endif()

if(MSVC AND WIN32)
    target_compile_definitions(Telebot PRIVATE _WIN32_WINNT=0x0601)
endif()

if(Telebot_INSTALL AND NOT CMAKE_SKIP_INSTALL_RULES)
    configure_package_config_file(cmake/telebot-config.cmake.in telebot-config.cmake
            INSTALL_DESTINATION "${Telebot_INSTALL_CMAKEDIR}")

    write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/telebot-config-version.cmake"
            VERSION ${PROJECT_VERSION}
            COMPATIBILITY SameMajorVersion)

    install(DIRECTORY include/
            TYPE INCLUDE)

    set(targets_file "telebot-shared-targets.cmake")
    if(NOT BUILD_SHARED_LIBS)
        set(targets_file "telebot-static-targets.cmake")
    endif()

    install(EXPORT Telebot_export
            NAMESPACE Telebot::
            FILE "telebot-targets.cmake"
            DESTINATION ${Telebot_INSTALL_CMAKEDIR})

    install(FILES
            "${CMAKE_CURRENT_BINARY_DIR}/telebot-config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/telebot-config-version.cmake"
            DESTINATION ${Telebot_INSTALL_CMAKEDIR})

    install_projects(Telebot)
endif()