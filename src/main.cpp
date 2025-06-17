#include "DeviceManager.h"
#include <iostream>
#include <cstdlib>

int main() {
    // 配置文件路径：项目目录下的data文件夹
    DeviceManager manager("data/device_params.json");
    
    std::cout << "设备参数管理系统\n";
    std::cout << "1. 显示当前参数\n";
    std::cout << "2. 修改设备名称\n";
    std::cout << "3. 修改校准数据\n";
    std::cout << "4. 保存并退出\n";
    
    int choice;
    while (true) {
        std::cout << "\n请输入选项: ";
        std::cin >> choice;
        
        try {
            switch (choice) {
                case 1:
                    manager.print_parameters();
                    break;
                case 2: {
                    std::string new_name;
                    std::cout << "输入新设备名称: ";
                    std::cin.ignore();
                    std::getline(std::cin, new_name);
                    manager.update_parameter("name", new_name);
                    break;
                }
                case 3: {
                    std::cout << "输入校准数据 (空格分隔，回车结束): ";
                    std::vector<int> calib;
                    int value;
                    while (std::cin >> value) {
                        calib.push_back(value);
                    }
                    std::cin.clear();
                    std::cin.ignore();
                    manager.update_parameter("calibration_data", calib);
                    break;
                }
                case 4:
                    manager.save_to_file();
                    std::cout << "参数已保存!\n";
                    return 0;
                default:
                    std::cout << "无效选项!\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "错误: " << e.what() << "\n";
        }
    }
}