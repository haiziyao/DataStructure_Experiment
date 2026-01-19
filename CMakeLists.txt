cmake_minimum_required(VERSION 4.0)
project(DataStructure)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.9.3/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(DataStructure main.cpp
        src/exp/main_menu/MainMenuWindow.h
        src/exp/main_menu/MainMenuWindow.cpp
        src/exp/exp6_menu/Exp6Window.h
        src/exp/exp6_menu/Exp6Window.cpp
        src/exp/exp13_menu/Exp13Window.cpp
        src/exp/exp13_menu/Exp13Window.h
        src/exp/experiment_13/src/work.h
        src/exp/experiment_13/src/work.cpp
        src/exp/experiment_1/src/work.h
        src/exp/experiment_1/src/work.cpp
        src/exp/experiment_2/src/work.h
        src/exp/experiment_2/src/work.cpp
        src/exp/experiment_11/src/work.h
        src/exp/experiment_11/src/work.cpp
        src/exp/experiment_4/src/work.h
        src/exp/experiment_4/src/work.cpp
        src/exp/exp11_menu/Exp11Window.h
        src/exp/exp11_menu/Exp11Window.cpp
        src/exp/exp4_menu/Exp4Window.h
        src/exp/exp4_menu/Exp4Window.cpp
        src/exp/exp1_menu/Exp1Window.h
        src/exp/exp1_menu/Exp1Window.cpp)
target_link_libraries(DataStructure
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
