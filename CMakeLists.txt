cmake_minimum_required(VERSION 3.19)
project(CountIt LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(CountIt
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    MaterialDark.qss
    textprocessor.h
    filehandler.h
    filehandler.cpp
    textprocessor.cpp
    wordfrequencydialog.h wordfrequencydialog.cpp wordfrequencydialog.ui





)

qt_add_translations(
    TARGETS CountIt
    TS_FILES CountIt_ru_RU.ts
)

target_link_libraries(CountIt
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS CountIt
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET CountIt
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
