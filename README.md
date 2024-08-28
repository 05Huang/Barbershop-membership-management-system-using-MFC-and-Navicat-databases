# 使用MFC与navicat Premium 16实现的理发店会员管理系统
## 概述

理发店会员管理系统是一个利用Microsoft Foundation Classes (MFC)技术开发的桌面应用程序，专为理发店设计，用以提升会员管理的效率和效果。该系统通过与Navicata Premium 16数据库的紧密结合，实现了数据的高效管理和维护。

## 功能特点

- **数据驱动**：系统后端使用Navicata Premium 16进行数据库管理，保证了数据的安全性和稳定性。
- **用户界面**：友好的图形用户界面(GUI)，使得操作直观易懂。
- **会员管理**：支持会员信息的增加、查询、修改和删除。
- **交易处理**：能够处理会员的充值和消费扣费等交易。
- **数据展示**：清晰展示会员列表和详细信息，支持不同排序和筛选方式。

## 技术栈

- **编程语言**：C++
- **开发框架**：MFC (Microsoft Foundation Classes)
- **数据库管理工具**：Navicata Premium 16
- **数据库**：MySQL
## 部分截图
![image](https://github.com/user-attachments/assets/d82d0b49-034e-46ed-8d5e-a0778d36fcf6)
![image](https://github.com/user-attachments/assets/8ec4a2f0-e9cb-47bd-8f8f-df39179d31af)
![image](https://github.com/user-attachments/assets/afafb22a-a7df-4351-b32d-3f19769adaae)

## 系统要求

- 操作系统：Windows 7/8/10
- 数据库管理工具：Navicata Premium 16 或更新版本
- 编译器：Microsoft Visual C++ 2017 或更新版本

## 安装与配置
1. 在开始之前需要配置VS与MySQL的配置与连接，[C/C++ vs2017连接MySQL数据库 - 增删改查(详细步骤)](https://blog.csdn.net/cpp_learner/article/details/116171955)
1. 确保已安装Microsoft Visual C++ 2017或更新版本的开发环境。
2. 安装Navicata Premium 16并配置MySQL数据库。
3. 打开项目解决方案文件 `.sln` 并根据需要配置项目属性。
4. 编译并运行项目。

## 使用说明

- 启动应用程序后，主界面将展示会员列表。
- 使用提供的按钮进行会员信息的增加、删除、修改等操作。
- 点击“查询”按钮可以搜索特定会员信息。
- 点击“充值”和“消费”按钮可以对会员账户进行操作。
![image](https://github.com/user-attachments/assets/345b524a-6dbb-4c03-bfcf-35b85745668a)
![image](https://github.com/user-attachments/assets/6f75470f-f183-491d-a8b1-06b7b0036c4d)
![image](https://github.com/user-attachments/assets/2deb57cd-1842-4d42-aa69-dcfc7e37a178)
![image](https://github.com/user-attachments/assets/35ce4638-243a-402a-b197-eae86e3046c3)
![image](https://github.com/user-attachments/assets/0ac6dec8-5aae-4b76-aff5-4232f6d024f5)

## 文件结构

- `Barershop member management.h` 和 `.cpp`：主应用程序类文件。
- `Barershop member managementDlg.h` 和 `.cpp`：主对话框类文件。
- `SQLInterface.h` 和 `.cpp`：数据库接口类文件，负责数据库的连接、查询、更新等操作。
- `MemberInfo.h` 和 `.cpp`：会员信息类，定义了会员数据结构。
- `resource.h`：资源文件，包含项目的所有资源定义。

## 注意事项

- 确保数据库服务正在运行，且连接信息正确无误。
- 在进行数据操作前，请确保输入的数据格式正确。
- 定期备份数据库，以防数据丢失。

## 版本历史

- v1.0.0：初始版本，实现了基本的会员管理功能。

## 许可

本项目采用[MIT许可](https://opensource.org/licenses/MIT)进行许可。

---

请根据项目实际情况调整上述文档内容。如果需要进一步解析提供的链接，请确保链接有效并可访问。
