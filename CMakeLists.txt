# 指定CMake的最低版本要求（3.10及以上）
cmake_minimum_required(VERSION 3.10)

# 优先查找自定义Qt安装路径
set(CMAKE_PREFIX_PATH "/home/adc/Qt/6.9.1/gcc_64/lib/cmake")

# 项目名称
project(DeviceManager)

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)
# 强制要求编译器必须支持C++17标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建data目录
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/data)

# 查找并链接Qt6
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)
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

add_executable(device_manager ${SOURCES})

# 包含目录
# 添加Qt头文件路径及其子文件夹
include_directories(/home/adc/Qt/6.9.1/gcc_64/include)
include_directories(/home/adc/Qt/6.9.1/gcc_64/include/QtWidgets)
include_directories(/home/adc/Qt/6.9.1/gcc_64/include/QtCore)
include_directories(/home/adc/Qt/6.9.1/gcc_64/include/QtGui)
target_include_directories(device_manager PRIVATE include)

# 将Qt6头文件包含到目标中
target_link_libraries(device_manager PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)

# 自动复制配置文件（首次运行）
add_custom_command(TARGET device_manager POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/data/device_params.json # 源配置文件路径
    ${CMAKE_BINARY_DIR}/data/device_params.json # 目标路径
)