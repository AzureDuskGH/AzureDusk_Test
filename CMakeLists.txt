# 指定CMake的最低版本要求（3.10及以上）
cmake_minimum_required(VERSION 3.10)

# 设置默认构建类型为 Debug，便于 VS Code IntelliSense 正确关联
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# 项目名称
project(DeviceManager)

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)
# 强制要求编译器必须支持C++17标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建data目录
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/data)

# 查找并链接Qt5
find_package(Qt5 REQUIRED COMPONENTS Widgets Gui Core)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 定义生成的可执行目标
set(SOURCES
    src/main.cpp
    src/DeviceManager.cpp
    src/MainWindow.cpp
    include/MainWindow.h
)

# 自动化 uic 处理 ui/MainWindow.ui，生成 include/ui_MainWindow.h
set(UIS ui/MainWindow.ui)
qt5_wrap_ui(UIS_HDRS ${UIS})
add_executable(device_manager ${SOURCES} ${UIS_HDRS})

# 包含目录
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)
target_include_directories(device_manager PRIVATE include)

# 链接Qt5库
target_link_libraries(device_manager PRIVATE Qt5::Widgets Qt5::Gui Qt5::Core)

# 自动复制配置文件（首次运行）
add_custom_command(TARGET device_manager POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/data/device_params.json # 源配置文件路径
    ${CMAKE_BINARY_DIR}/data/device_params.json # 目标路径
)