# 指定CMake的最低版本要求（3.10及以上）
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(DeviceManager)

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)
# 强制要求编译器必须支持C++17标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建data目录
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/data)

# 定义生成的可执行目标
add_executable(device_manager
    src/main.cpp
    src/DeviceManager.cpp
)

# 包含目录
target_include_directories(device_manager PRIVATE include)

# 自动复制配置文件（首次运行）
add_custom_command(TARGET device_manager POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/data/device_params.json # 源配置文件路径
    ${CMAKE_BINARY_DIR}/data/device_params.json # 目标路径
)